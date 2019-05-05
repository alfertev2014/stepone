#include <parser/firstparser.h>

#include <ptr.h>
#include <impl/ptr_impl.h>

#include <impl/core/bytearray.h>
#include <impl/core/vector.h>

#include <dbg.h>

#include <cstring>
#include <sstream>

namespace stepone::parser {

typedef std::string::const_iterator string_pos;
static const std::size_t string_end = std::string::npos;

using namespace core;

struct parseRes {
    Ptr e;
    string_pos rest;
    bool success;

    parseRes(const Ptr & _e, string_pos _rest, bool _success)
        :e(_e), rest(_rest), success(_success) {}
};

class FirstParser::FirstParserImpl {
public:
    FirstParserImpl(const Ptr &baseSymbolTable) :
        symbols(baseSymbolTable),
        nosymbol("(){}[].\"")
    {}

    std::ostream & printOb(std::ostream & ts, const Ptr & p);

    Ptr parse(const std::string &_s);
private:
    std::string s;
    std::string nosymbol;
    Ptr symbols;

    std::ostream & printSymbol(std::ostream & ts, const Ptr &sym);
    std::ostream & printList(std::ostream & ts, Pair * pr);
    void printValue(std::ostream &ts, const Ptr &p);

    parseRes parseExpression(string_pos si);
    parseRes parseTail(string_pos si);
    parseRes parseAtom(string_pos si);
    parseRes parseChar(string_pos si);
    parseRes parseString(string_pos si);
    parseRes parseSymbol(string_pos si);
    parseRes parseNumber(string_pos si);

    bool lexem(const std::string & lex, string_pos & si);
    void spaces(string_pos & si);
};


FirstParser::FirstParser(const Ptr &baseEvaluator, const Ptr &baseSymbolTable) :
    a(baseEvaluator),
    impl(new FirstParserImpl(baseSymbolTable))
{}

FirstParser::FirstParser(const FirstParser &fp) :
    a(fp.a),
    impl(new FirstParserImpl(*fp.impl))
{}

FirstParser::~FirstParser() {
    delete impl;
}

Ptr FirstParser::parse(const std::string &_s) {
    return impl->parse(_s);
}

Ptr FirstParser::parseEval(const std::string &s) {
    Ptr parsed = parse(s);
    Ptr evaluated = parsed.eval(a).unlazy();
    return evaluated;
}

std::string FirstParser::evalToString(const std::string &_s) {
    std::stringstream ss;
    print(ss, parseEval(_s));
    return ss.str();
}

void FirstParser::print(std::ostream &ts, const Ptr &p) {
    impl->printOb(ts, p);
}

void FirstParser::FirstParserImpl::printValue(std::ostream &ts, const Ptr &p) {

    if(Value<int> *val = p.as<Value<int> >(); val)
        ts << val->getValue();
    else if(Value<float> *val = p.as<Value<float> >(); val)
        ts << val->getValue();
    else if(Value<char> *val = p.as<Value<char> >(); val) {
        char c = val->getValue();
        if(c == '\"') ts << "&\"\"";
        else ts << "&\"" << c << "\"";
    }
    else if(Value<long long> *val = p.as<Value<long long> >(); val)
        ts << val->getValue();
    else if(Vector * v = p.as<Vector>(); v) {
        int n = v->getSize();
        if(n == 0)
            ts << "[]";
        else {
            ts << "[";
            printOb(ts, v->getElement(0));
            for(int i = 1; i < n; ++i) {
                ts << ", ";
                printOb(ts, v->getElement(i));
            }
            ts << "]";
        }
    } else if(ByteArray * ba = p.as<ByteArray>(); ba) {
        ts << "\"";
        ts.write(ba->getData(), ba->getSize());
        ts << "\"";
    } else
        ts << "{SpecType}";
}

std::ostream &FirstParser::FirstParserImpl::printOb(std::ostream &ts, const Ptr &p) {
    if(p.is<Symbol>())
        return printSymbol(ts, p);
    if(p.is<Pair>()) {
        ts << "(";
        return printList(ts, p.as<Pair>());
    }
    if(p.is<Lazy>())
        ts << "{lazy}";
    else if(p.is<Label>())
        ts << "{label}";
    else if(p.is<ValueBase>()) {
        printValue(ts, p);
    }
    return ts;
}

Ptr FirstParser::FirstParserImpl::parse(const std::string &_s) {
    s = _s;
    parseRes pr = parseExpression(s.begin());
    return pr.success ? pr.e : Ptr::anil;
}

std::ostream &FirstParser::FirstParserImpl::printSymbol(std::ostream &ts, const Ptr &sym) {
    if(sym == Ptr::anil) {
        return ts << "()";
    } else {
        for(Ptr p = symbols; p != Ptr::anil; p = p.cdr()) {
            if(p.car().car() == sym) {
                ByteArray * ba = p.car().cdr().as<ByteArray>();
                return ts.write(ba->getData(), ba->getSize());
            }
        }
    }
    return ts << "{sym}";
}

std::ostream &FirstParser::FirstParserImpl::printList(std::ostream &ts, Pair *pr) {
    printOb(ts, pr->car());
    Ptr pcdr = pr->cdr();
    Atom * atom = pcdr.as<Atom>();
    if(atom != 0) {
        if(atom != Ptr::anil.as<Atom>()) {
            ts << " . ";
            printOb(ts, pcdr);
        }
        ts << ")";
    } else {
        ts << " ";
        printList(ts, pcdr.as<Pair>());
    }
    return ts;
}

parseRes FirstParser::FirstParserImpl::parseTail(string_pos si) {
    string_pos sii = si;
    spaces(sii);
    if(lexem(")", sii))
        return parseRes(Ptr::anil, sii, true);
    if(lexem(".", sii)) {
        spaces(sii);
        parseRes pr = parseExpression(sii);
        if(!pr.success) {
            DBG("parseTail fail");
            return parseRes(Ptr::anil, si, false);
        }
        sii = pr.rest;
        spaces(sii);
        if(lexem(")", sii))  {
            return parseRes(pr.e, sii, true);
        } else {
            DBG("fail ) expected");
            return parseRes(Ptr::anil, si, false);
        }
    }
    parseRes pr1 = parseExpression(sii);
    if(!pr1.success) {
        DBG("parseTail fail");
        return parseRes(Ptr::anil, si, false);
    }
    parseRes pr2 = parseTail(pr1.rest);
    if(!pr2.success) {
        DBG("parseTail fail");
        return parseRes(Ptr::anil, si, false);
    }
    return parseRes(new Ob(Pair(pr1.e, pr2.e)), pr2.rest, true);
}

parseRes FirstParser::FirstParserImpl::parseAtom(string_pos si) {
    parseRes pr = parseNumber(si);
    if(pr.success) return pr;
    pr = parseString(si);
    if(pr.success) return pr;
    pr = parseChar(si);
    if(pr.success) return pr;
    pr = parseSymbol(si);
    return pr.success ? pr : parseRes(Ptr::anil, si, false);
}

parseRes FirstParser::FirstParserImpl::parseChar(string_pos si) {
    string_pos sii = si;
    if(sii == s.end() || *sii != '&')
        return parseRes(Ptr::anil, si, false);
    else
        ++sii;
    if(sii == s.end() || *sii != '\"')
        return parseRes(Ptr::anil, si, false);
    else
        ++sii;
    std::string chars;
    for( ; sii != s.end() && *sii != '\"'; ++sii)
        chars.push_back(*sii);
    if(sii != s.end())
        ++sii;
    return parseRes(new Ob(Value<char>(chars.size() > 0 ? chars[0] : '\"')), sii, true);
}

parseRes FirstParser::FirstParserImpl::parseString(string_pos si) {
    string_pos sii = si;
    if(sii == s.end() || *sii != '\"')
        return parseRes(Ptr::anil, si, false);
    else
        ++sii;
    std::string chars;
    for( ; sii != s.end() && *sii != '\"'; ++sii)
        chars.push_back(*sii);
    if(sii != s.end())
        ++sii;
    return parseRes(ByteArray::fromChars(chars.size(), chars.c_str()), sii, true);
}

parseRes FirstParser::FirstParserImpl::parseSymbol(string_pos si) {
    std::string symbolString;
    string_pos sii = si;
    if(sii == s.end() || isspace(*sii) || (nosymbol.find(*sii) != string_end)) {
        DBG("symbol fail first char ") << "\"" << *sii << "\"" << std::endl;
        if(sii == s.end()) DBG("isend");
        else if(isspace(*sii)) DBG("isspace");
        else if((nosymbol.find(*sii) != string_end)) DBG("nosym");
        return parseRes(Ptr::anil, si, false);
    }
    symbolString.push_back(*sii);
    ++sii;
    while(sii != s.end() && !isspace(*sii) && (nosymbol.find(*sii) == string_end)) {
        symbolString.push_back(*sii);
        ++sii;
    }
    for(Ptr p = symbols; p != Ptr::anil; p = p.cdr()) {
        ByteArray * ba = p.car().cdr().as<ByteArray>();
        if(ba->getSize() == symbolString.size() &&
                !memcmp(ba->getData(), symbolString.data(), symbolString.size()))
            return parseRes(p.car().car(), sii, true);
    }
    Ptr sym = new Ob(Symbol());
    symbols = new Ob(Pair(new Ob(Pair(sym, ByteArray::fromChars(symbolString.size(), symbolString.data()))), symbols));
    return parseRes(sym, sii, true);
}

parseRes FirstParser::FirstParserImpl::parseNumber(string_pos si) {
    std::string number;
    string_pos sii = si;
    if(sii == s.end() || !isdigit(*sii) && *sii != '-' || isspace(*sii) || (nosymbol.find(*sii) != string_end)) {
        return parseRes(Ptr::anil, si, false);
    }
    number.push_back(*sii);
    ++sii;
    while(sii != s.end() && isdigit(*sii) && !isspace(*sii) && (nosymbol.find(*sii) == string_end)) {
        number.push_back(*sii);
        ++sii;
    }
    if(sii == s.end() || *sii != '.') {
        std::istringstream ss(number);
        int i;
        if(ss >> i)
            return parseRes(new Ob(Value<int>(i)), sii, true);
        else {
            DBG("int is not int");
        }
    } else {
        number.push_back(*sii);
        ++sii;
        while(sii != s.end() && isdigit(*sii) && !isspace(*sii) && (nosymbol.find(*sii) == string_end)) {
            number.push_back(*sii);
            ++sii;
        }
        float f;
        std::istringstream ss(number);
        if(ss >> f)
            return parseRes(new Ob(Value<float>(f)), sii, true);
        else {
            DBG("float is not float");
        }
    }
    return parseRes(Ptr::anil, si, false);
}

bool FirstParser::FirstParserImpl::lexem(const std::string &lex, string_pos &si) {
    string_pos sii = si;
    for(string_pos it = lex.begin(); it != lex.end(); ++it) {
        if(sii == s.end() || *sii != *it)
            return false;
        ++sii;
    }
    si = sii;
    return true;
}

void FirstParser::FirstParserImpl::spaces(string_pos &si) {
    while(si != s.end() && isspace(*si))
        ++si;
}

parseRes FirstParser::FirstParserImpl::parseExpression(string_pos si) {
    spaces(si);
    bool success = lexem("(", si);
    return success ? parseTail(si) : parseAtom(si);
}

} // namespaces
