#include "fistparser.h"

#include <ptr.h>
#include <impl/ptr_impl.h>

#include <impl/core/bytearray.h>
#include <impl/core/vector.h>

#include <dbg.h>

#include <cstring>
#include <sstream>

using namespace std;

struct parseRes {
    Ptr e;
    string::const_iterator rest;
    bool success;

    parseRes(const Ptr & _e, string::const_iterator _rest, bool _success)
        :e(_e), rest(_rest), success(_success) {}
};

class FirstParser::FirstParserImpl {
public:
    FirstParserImpl(const Ptr &baseSymbolTable) :
        symbols(baseSymbolTable),
        nosymbol("(){}[].\"")
    {}

    ostream & printOb(ostream & ts, const Ptr & p);

    Ptr parse(const string &_s);
private:
    string s;
    string nosymbol;
    Ptr symbols;

    ostream & printSymbol(ostream & ts, Symbol * sym);
    ostream & printList(ostream & ts, Pair * pr);
    void printValue(ostream &ts, const Ptr &p);

    parseRes parseExpression(string::const_iterator si);
    parseRes parseTail(string::const_iterator si);
    parseRes parseAtom(string::const_iterator si);
    parseRes parseChar(string::const_iterator si);
    parseRes parseString(string::const_iterator si);
    parseRes parseSymbol(string::const_iterator si);
    parseRes parseNumber(string::const_iterator si);

    bool lexem(const string & lex, string::const_iterator & si);
    void spaces(string::const_iterator & si);
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

Ptr FirstParser::parse(const string &_s) {
    return impl->parse(_s);
}

Ptr FirstParser::parseEval(const string &s) {
    Ptr parsed = parse(s);
    Ptr evaluated = parsed.eval(a).unlazy();
    return evaluated;
}

string FirstParser::evalToString(const string &_s) {
    stringstream ss;
    print(ss, parseEval(_s));
    return ss.str();
}

void FirstParser::print(ostream &ts, const Ptr &p) {
    impl->printOb(ts, p);
}

void FirstParser::FirstParserImpl::printValue(ostream &ts, const Ptr &p) {
    ValueBase * spt = p.as<ValueBase>();
    if(spt->is<Value<int> >())
        ts << spt->as<Value<int> >()->getValue();
    else if(spt->is<Value<float> >())
        ts << spt->as<Value<float> >()->getValue();
    else if(spt->is<Value<char> >()) {
        char c = spt->as<Value<char> >()->getValue();
        if(c == '\"') ts << "&\"\"";
        else ts << "&\"" << c << "\"";
    } else if(spt->is<Vector>()) {
        Vector * v = spt->as<Vector>();
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
    } else if(spt->is<ByteArray>()) {
        ByteArray * ba = spt->as<ByteArray>();
        ts << "\"";
        ts.write(ba->getData(), ba->getSize());
        ts << "\"";
    } else
        ts << "{SpecType}";
}

ostream &FirstParser::FirstParserImpl::printOb(ostream &ts, const Ptr &p) {
    Symbol * sym = p.as<Symbol>();
    if(sym != 0)
        return printSymbol(ts, sym);
    if(p.as<Pair>()) {
        ts << "(";
        return printList(ts, p.as<Pair>());
    }
    if(p.as<Lazy>())
        ts << "{lazy}";
    else if(p.as<Label>())
        ts << "{label}";
    else if(p.as<ValueBase>()) {
        printValue(ts, p);
    }
    return ts;
}

Ptr FirstParser::FirstParserImpl::parse(const string &_s) {
    s = _s;
    parseRes pr = parseExpression(s.begin());
    return pr.success ? pr.e : Ptr::anil;
}

ostream &FirstParser::FirstParserImpl::printSymbol(ostream &ts, Symbol *sym) {
    if(sym == Ptr::anil.as<Symbol>()) {
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

ostream &FirstParser::FirstParserImpl::printList(ostream &ts, Pair *pr) {
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

parseRes FirstParser::FirstParserImpl::parseTail(string::const_iterator si) {
    string::const_iterator sii = si;
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
    return parseRes(new Pair(pr1.e, pr2.e), pr2.rest, true);
}

parseRes FirstParser::FirstParserImpl::parseAtom(string::const_iterator si) {
    parseRes pr = parseNumber(si);
    if(pr.success) return pr;
    pr = parseString(si);
    if(pr.success) return pr;
    pr = parseChar(si);
    if(pr.success) return pr;
    pr = parseSymbol(si);
    return pr.success ? pr : parseRes(Ptr::anil, si, false);
}

parseRes FirstParser::FirstParserImpl::parseChar(string::const_iterator si) {
    string::const_iterator sii = si;
    if(sii == s.end() || *sii != '&')
        return parseRes(Ptr::anil, si, false);
    else
        ++sii;
    if(sii == s.end() || *sii != '\"')
        return parseRes(Ptr::anil, si, false);
    else
        ++sii;
    string chars;
    for( ; sii != s.end() && *sii != '\"'; ++sii)
        chars.push_back(*sii);
    if(sii != s.end())
        ++sii;
    return parseRes(new Value<char>(chars.size() > 0 ? chars[0] : '\"'), sii, true);
}

parseRes FirstParser::FirstParserImpl::parseString(string::const_iterator si) {
    string::const_iterator sii = si;
    if(sii == s.end() || *sii != '\"')
        return parseRes(Ptr::anil, si, false);
    else
        ++sii;
    string chars;
    for( ; sii != s.end() && *sii != '\"'; ++sii)
        chars.push_back(*sii);
    if(sii != s.end())
        ++sii;
    return parseRes(ByteArray::fromChars(chars.size(), chars.c_str()), sii, true);
}

parseRes FirstParser::FirstParserImpl::parseSymbol(string::const_iterator si) {
    string symbolString;
    string::const_iterator sii = si;
    if(sii == s.end() || isspace(*sii) || (nosymbol.find(*sii) != string::npos)) {
        DBG("symbol fail first char ") << "\"" << *sii << "\"" << endl;
        if(sii == s.end()) DBG("isend");
        else if(isspace(*sii)) DBG("isspace");
        else if((nosymbol.find(*sii) != string::npos)) DBG("nosym");
        return parseRes(Ptr::anil, si, false);
    }
    symbolString.push_back(*sii);
    ++sii;
    while(sii != s.end() && !isspace(*sii) && (nosymbol.find(*sii) == string::npos)) {
        symbolString.push_back(*sii);
        ++sii;
    }
    for(Ptr p = symbols; p != Ptr::anil; p = p.cdr()) {
        ByteArray * ba = p.car().cdr().as<ByteArray>();
        if(ba->getSize() == symbolString.size() &&
                !memcmp(ba->getData(), symbolString.data(), symbolString.size()))
            return parseRes(p.car().car(), sii, true);
    }
    Symbol * sym = new Symbol();
    symbols = new Pair(new Pair(sym, ByteArray::fromChars(symbolString.size(), symbolString.data())), symbols);
    return parseRes(sym, sii, true);
}

parseRes FirstParser::FirstParserImpl::parseNumber(string::const_iterator si) {
    string number;
    string::const_iterator sii = si;
    if(sii == s.end() || !isdigit(*sii) && *sii != '-' || isspace(*sii) || (nosymbol.find(*sii) != string::npos)) {
        return parseRes(Ptr::anil, si, false);
    }
    number.push_back(*sii);
    ++sii;
    while(sii != s.end() && isdigit(*sii) && !isspace(*sii) && (nosymbol.find(*sii) == string::npos)) {
        number.push_back(*sii);
        ++sii;
    }
    if(sii == s.end() || *sii != '.') {
        istringstream ss(number);
        int i;
        if(ss >> i)
            return parseRes(new Value<int>(i), sii, true);
        else {
            DBG("int is not int");
        }
    } else {
        number.push_back(*sii);
        ++sii;
        while(sii != s.end() && isdigit(*sii) && !isspace(*sii) && (nosymbol.find(*sii) == string::npos)) {
            number.push_back(*sii);
            ++sii;
        }
        float f;
        istringstream ss(number);
        if(ss >> f)
            return parseRes(new Value<float>(f), sii, true);
        else {
            DBG("float is not float");
        }
    }
    return parseRes(Ptr::anil, si, false);
}

bool FirstParser::FirstParserImpl::lexem(const string &lex, string::const_iterator &si) {
    string::const_iterator sii = si;
    for(string::const_iterator it = lex.begin(); it != lex.end(); ++it) {
        if(sii == s.end() || *sii != *it)
            return false;
        ++sii;
    }
    si = sii;
    return true;
}

void FirstParser::FirstParserImpl::spaces(string::const_iterator &si) {
    while(si != s.end() && isspace(*si))
        ++si;
}

parseRes FirstParser::FirstParserImpl::parseExpression(string::const_iterator si) {
    spaces(si);
    bool success = lexem("(", si);
    return success ? parseTail(si) : parseAtom(si);
}
