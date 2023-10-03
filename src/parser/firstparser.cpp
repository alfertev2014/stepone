#include "firstparser.h"

#include <ptr.h>
#include <ptr_impl.h>

#include <core/bytearray.h>
#include <core/vector.h>

#include <logging.h>

#include <cstring>
#include <sstream>
#include <string_view>
#include <optional>
#include <algorithm>

namespace stepone::parser {

using namespace core;

using string_pos = std::string_view::const_iterator;

using parseRes = std::optional<Ptr>;


class FirstParser::FirstParserImpl {
public:
    FirstParserImpl(const Ptr &baseSymbolTable) :
        symbols(baseSymbolTable)
    {}

    std::ostream & printOb(std::ostream & ts, const Ptr & p);

    Ptr parse(const std::string &_s);
private:
    Ptr symbols;
};


class Parser {
    Ptr &symbols;

    std::string_view s;
    string_pos si;
    const std::string nosymbol {"(){}[].\""};

    bool eos() const { return si == s.end(); }
    bool punctuation() const { return nosymbol.find(*si) != std::string_view::npos; }
public:
    Parser(Ptr &symbols, std::string_view s)
        : symbols(symbols), s(s), si(s.begin()) {}

    parseRes parseExpression();
    parseRes parseTail();
    parseRes parseAtom();
    parseRes parseChar();
    parseRes parseString();
    parseRes parseSymbol();
    parseRes parseNumber();

    bool lexem(std::string_view lex);
    void spaces();
};


class Printer {
    const Ptr &symbols;
public:
    Printer(const Ptr &symbols)
        : symbols(symbols) {}

    std::ostream & printOb(std::ostream & ts, const Ptr & p);
    std::ostream & printSymbol(std::ostream & ts, const Ptr &sym);
    std::ostream & printList(std::ostream & ts, Pair * pr);
    void printValue(std::ostream &ts, const Ptr &p);
};


FirstParser::FirstParser(const Ptr &baseEvaluator, const Ptr &baseSymbolTable) :
    a(baseEvaluator),
    impl(std::make_unique<FirstParserImpl>(baseSymbolTable))
{}

FirstParser::FirstParser(const FirstParser &fp) :
    a(fp.a),
    impl(std::make_unique<FirstParserImpl>(*fp.impl))
{}

FirstParser::~FirstParser() = default;

Ptr FirstParser::parse(const std::string &_s) {
    return impl->parse(_s);
}

Ptr FirstParser::eval(const Ptr &p) {
    return p.eval(a).unlazy();
}

Ptr FirstParser::parseEval(const std::string &s) {
    return eval(parse(s));
}

std::string FirstParser::evalToString(const std::string &_s) {
    return printToString(parseEval(_s));
}

std::string FirstParser::printToString(const Ptr &p) {
    std::stringstream ss;
    print(ss, p);
    return ss.str();
}

void FirstParser::print(std::ostream &ts, const Ptr &p) {
    impl->printOb(ts, p);
}


std::ostream &FirstParser::FirstParserImpl::printOb(std::ostream &ts, const Ptr &p) {
    Printer printer(symbols);
    printer.printOb(ts, p);
    return ts;
}

Ptr FirstParser::FirstParserImpl::parse(const std::string &_s) {
    Parser fsm(this->symbols, _s);
    parseRes pr = fsm.parseExpression();
    return pr.value_or(Ptr::anil());
}


void Printer::printValue(std::ostream &ts, const Ptr &p) {

    if (Value<long> *val = p.as<Value<long> >(); val)
            ts << val->getValue();
    else if (Value<double> *val = p.as<Value<double> >(); val)
        ts << val->getValue();
    else if (Value<char> *val = p.as<Value<char> >(); val) {
        char c = val->getValue();
        if(c == '\"') ts << "&\"\"";
        else ts << "&\"" << c << "\"";
    }
    else if (Vector * v = p.as<Vector>(); v) {
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
    } else if (ByteArray * ba = p.as<ByteArray>(); ba) {
        ts << "\"";
        ts.write(ba->getData(), ba->getSize());
        ts << "\"";
    } else
        ts << "{SpecType}";
}

std::ostream &Printer::printOb(std::ostream &ts, const Ptr &p) {
    if (p.is<Symbol>())
        return printSymbol(ts, p);
    if (p.is<Pair>()) {
        ts << "(";
        return printList(ts, p.as<Pair>());
    }
    if (p.is<Lazy>())
        ts << "{lazy}";
    else if (p.is<Label>())
        ts << "{label}";
    else if (p.is<ValueBase>()) {
        printValue(ts, p);
    }
    return ts;
}

std::ostream &Printer::printSymbol(std::ostream &ts, const Ptr &sym) {
    if(sym == Ptr::anil()) {
        return ts << "()";
    } else {
        for(Ptr p = symbols; p != Ptr::anil(); p = p.cdr()) {
            if(p.car().car() == sym) {
                ByteArray * ba = p.car().cdr().as<ByteArray>();
                return ts.write(ba->getData(), ba->getSize());
            }
        }
    }
    return ts << "{sym}";
}

std::ostream &Printer::printList(std::ostream &ts, Pair *pr) {
    printOb(ts, pr->car());
    Ptr pcdr = pr->cdr();
    if(pcdr.is<Atom>()) {
        if(pcdr != Ptr::anil()) {
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


parseRes Parser::parseTail() {
    spaces();
    if (lexem(")"))
        return Ptr::anil();
    if (lexem(".")) {
        spaces();
        parseRes pr = parseExpression();
        if(!pr.has_value()) {
            logging::error("parseTail fail");
            return std::nullopt;
        }
        spaces();
        if(lexem(")"))  {
            return pr;
        } else {
            logging::error("fail ) expected");
            return std::nullopt;
        }
    }
    parseRes pr1 = parseExpression();
    if (!pr1.has_value()) {
        logging::error("parseTail fail");
        return std::nullopt;
    }
    parseRes pr2 = parseTail();
    if (!pr2.has_value()) {
        logging::error("parseTail fail");
        return std::nullopt;
    }
    return Ptr::of<Pair>(pr1.value(), pr2.value());
}

parseRes Parser::parseAtom() {
    string_pos sii = si;
    parseRes pr = parseNumber();
    if (pr.has_value()) return pr;

    si = sii;
    pr = parseString();
    if (pr.has_value()) return pr;

    si = sii;
    pr = parseChar();
    if (pr.has_value()) return pr;

    si = sii;
    pr = parseSymbol();
    if (pr.has_value()) return pr;

    return std::nullopt;
}

parseRes Parser::parseChar() {
    if (eos() || *si != '&')
        return std::nullopt;

    ++si;
    if (eos() || *si != '\"')
        return std::nullopt;

    ++si;
    std::string chars; // TODO: Add interpretation of escape sequences and unicoode
    for ( ; !eos() && *si != '\"'; ++si)
        chars.push_back(*si);
    if (!eos())
        ++si;
    return Ptr::of<Value<char>>(chars.size() > 0 ? chars[0] : '\"');
}

parseRes Parser::parseString() {
    if (eos() || *si != '\"')
        return std::nullopt;

    ++si;
    std::string chars; // TODO: Add interpretation of escape sequences and unicoode
    for ( ; !eos() && *si != '\"'; ++si)
        chars.push_back(*si);
    if (!eos())
        ++si;
    return Ptr::of<ByteArray>(chars.c_str(), chars.size());
}

parseRes Parser::parseSymbol() {
    std::string symbolString;
    if (eos()) {
        logging::error("Fail to parse symbol: eos has reached");
        return std::nullopt;
    }
    if (isspace(*si) || punctuation()) {
        logging::error("Fail to parse symbol first char: \"", *si, '\"');
        return std::nullopt;
    }

    symbolString.push_back(*si);
    ++si;
    for ( ; !eos() && !isspace(*si) && !punctuation(); ++si) {
        symbolString.push_back(*si);
    }
    for (Ptr p = symbols; p != Ptr::anil(); p = p.cdr()) {
        ByteArray * ba = p.car().cdr().as<ByteArray>();
        if(ba->getSize() == symbolString.size() &&
                !memcmp(ba->getData(), symbolString.data(), symbolString.size()))
            return p.car().car();
    }

    Ptr sym = Ptr::of<Symbol>();
    symbols = Ptr::of<Pair>(
        Ptr::of<Pair>(
            sym,
            Ptr::of<ByteArray>(symbolString.data(), symbolString.size())
        ),
        symbols
    );
    return sym;
}

parseRes Parser::parseNumber() {
    std::string number;
    if (eos() || (!isdigit(*si) && *si != '-') || isspace(*si) || punctuation()) {
        return std::nullopt;
    }

    number.push_back(*si);
    ++si;
    for ( ; !eos() && isdigit(*si) && !isspace(*si) && !punctuation(); ++si) {
        number.push_back(*si);
    }

    if (eos() || *si != '.') {
        std::istringstream ss(number);
        long i;
        if (ss >> i) {
            return Ptr::of<Value<long>>(i);
        }
    } else {
        number.push_back(*si);
        ++si;
        for ( ; !eos() && isdigit(*si) && !isspace(*si) && !punctuation(); ++si) {
            number.push_back(*si);
        }
        double f;
        std::istringstream ss(number);
        if (ss >> f) {
            return Ptr::of<Value<double>>(f);
        }
    }
    return std::nullopt;
}

bool Parser::lexem(std::string_view lex) {
    if (std::search(si, s.end(), lex.begin(), lex.end()) == si) {
        si += lex.size();
        return true;
    }
    return false;
}

void Parser::spaces() {
    while(!eos() && isspace(*si))
        ++si;
}

parseRes Parser::parseExpression() {
    spaces();
    if (lexem("("))
        return parseTail();
    return parseAtom();
}

} // namespaces
