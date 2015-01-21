#pragma once

#include "dbg.h"

#include "stepone.h"

#include <string>
#include <map>

using namespace std;

class FirstParser {
    string s;

    string nosymbol;

    Ob::Ptr a;
    Ob::Ptr symbols;

    void addInSymbols(const string & s, const Ob::Ptr & p) {
        symbols = new Pair(new Pair(p, ByteArray::fromChars(s.size(), s.data())), symbols);
    }

    void addInContext(const string &s, const Ob::Ptr & v) {
        Ob::Ptr p = new Symbol();
        addInSymbols(s, p);
        a = new Context(p, v, a);
    }

    void initTable() {
        symbols = Ob::anil;
        a = Ob::anil;

        addInContext("-i", BaseNumFunc::fintNeg);
        addInContext("i+", BaseNumFunc::fintPlus);
        addInContext("i-", BaseNumFunc::fintMinus);
        addInContext("i*", BaseNumFunc::fintProduct);
        addInContext("i/", BaseNumFunc::fintDivision);
        addInContext("i%", BaseNumFunc::fintMod);
        addInContext("i?", BaseNumFunc::fintp);
        addInContext("i-not", BaseNumFunc::fintnot);
        addInContext("i-and", BaseNumFunc::fintand);
        addInContext("i-or", BaseNumFunc::fintor);
        addInContext("i-xor", BaseNumFunc::fintxor);
        addInContext("i-shl", BaseNumFunc::fintshl);
        addInContext("i-shr", BaseNumFunc::fintshr);
        addInContext("i=", BaseNumFunc::fintEql);
        addInContext("i!=", BaseNumFunc::fintNE);
        addInContext("i<", BaseNumFunc::fintLT);
        addInContext("i>", BaseNumFunc::fintGT);
        addInContext("i<=", BaseNumFunc::fintLE);
        addInContext("i>=", BaseNumFunc::fintGE);

        addInContext("u?", BaseNumFunc::flongp);
        addInContext("u-not", BaseNumFunc::flongnot);
        addInContext("u-and", BaseNumFunc::flongand);
        addInContext("u-or", BaseNumFunc::flongor);
        addInContext("u-xor", BaseNumFunc::flongxor);
        addInContext("u-shl", BaseNumFunc::flongshl);
        addInContext("u-shr", BaseNumFunc::flongshr);

        addInContext("u=", BaseNumFunc::flongEql);
        addInContext("u!=", BaseNumFunc::flongNE);
        addInContext("u<", BaseNumFunc::flongLT);
        addInContext("u>", BaseNumFunc::flongGT);
        addInContext("u<=", BaseNumFunc::flongLE);
        addInContext("u>=", BaseNumFunc::flongGE);

        addInContext("c?", BaseNumFunc::fcharp);
        addInContext("c-not", BaseNumFunc::fcharnot);
        addInContext("c-and", BaseNumFunc::fcharand);
        addInContext("c-or", BaseNumFunc::fcharor);
        addInContext("c-xor", BaseNumFunc::fcharxor);
        addInContext("c-shl", BaseNumFunc::fcharshl);
        addInContext("c-shr", BaseNumFunc::fcharshr);
        addInContext("c=", BaseNumFunc::fcharEql);
        addInContext("c!=", BaseNumFunc::fcharNE);
        addInContext("c<", BaseNumFunc::fcharLT);
        addInContext("c>", BaseNumFunc::fcharGT);
        addInContext("c<=", BaseNumFunc::fcharLE);
        addInContext("c>=", BaseNumFunc::fcharGE);

        addInContext("-f", BaseNumFunc::ffloatNeg);
        addInContext("f+", BaseNumFunc::ffloatPlus);
        addInContext("f-", BaseNumFunc::ffloatMinus);
        addInContext("f*", BaseNumFunc::ffloatProduct);
        addInContext("f/", BaseNumFunc::ffloatDivision);
        addInContext("f?", BaseNumFunc::ffloatp);
        addInContext("f=", BaseNumFunc::ffloatEql);
        addInContext("f!=", BaseNumFunc::ffloatNE);
        addInContext("f<", BaseNumFunc::ffloatLT);
        addInContext("f>", BaseNumFunc::ffloatGT);
        addInContext("f<=", BaseNumFunc::ffloatLE);
        addInContext("f>=", BaseNumFunc::ffloatGE);

        addInContext("u2i", BaseNumFunc::flong2int);
        addInContext("i2u", BaseNumFunc::fint2long);
        addInContext("f2i", BaseNumFunc::ffloat2int);
        addInContext("i2f", BaseNumFunc::fint2float);
        addInContext("c2i", BaseNumFunc::fchar2int);
        addInContext("i2c", BaseNumFunc::fint2char);
        addInContext("c2u", BaseNumFunc::fchar2long);
        addInContext("u2c", BaseNumFunc::flong2char);

        addInContext("vec?", VectorFunctions::fvecp);
        addInContext("mkvec", VectorFunctions::fmkvec);
        addInContext("vec-clone", VectorFunctions::fvecclone);
        addInContext("vec-len", VectorFunctions::fveclen);
        addInContext("vec-mid", VectorFunctions::fvecmid);
        addInContext("vec-slice", VectorFunctions::fvecslice);
        addInContext("vec-el", VectorFunctions::fvecel);
        addInContext("vec-cat", VectorFunctions::fveccat);

        addInContext("input?", IOFunctions::finputp);
        addInContext("output?", IOFunctions::foutputp);
        addInContext("open-in", IOFunctions::fopenin);
        addInContext("open-out", IOFunctions::fopenout);
        addInContext("read", IOFunctions::fread);
        addInContext("write", IOFunctions::fwrite);
        addInContext("stdin", new StdIn());
        addInContext("stdout", new StdOut());
        addInContext("stderr", new StdErr());

        addInContext("b?", ByteArrayFunctions::fbarrayp);
        addInContext("b-len", ByteArrayFunctions::fbarraylen);
        addInContext("b-clone", ByteArrayFunctions::fbarrayclone);
        addInContext("b-cmp", ByteArrayFunctions::fbarraycmp);
        addInContext("b-ncmp", ByteArrayFunctions::fbarrayncmp);
        addInContext("b-findch", ByteArrayFunctions::fbarrayfindch);
        addInContext("b-find", ByteArrayFunctions::fbarrayfind);
        addInContext("b-cat", ByteArrayFunctions::fbarraycat);
        addInContext("b-mid", ByteArrayFunctions::fbarraymid);
        addInContext("b-slice", ByteArrayFunctions::fbarrayslice);
        addInContext("i2b", ByteArrayFunctions::fserint);
        addInContext("f2b", ByteArrayFunctions::fserfloat);
        addInContext("c2b", ByteArrayFunctions::fserchar);
        addInContext("b-geti", ByteArrayFunctions::fgetint);
        addInContext("b-getf", ByteArrayFunctions::fgetfloat);
        addInContext("b-getc", ByteArrayFunctions::fgetchar);

        addInContext("sz-i", new ValueType<int>(sizeof(int)));
        addInContext("sz-f", new ValueType<int>(sizeof(float)));
        addInContext("sz-c", new ValueType<int>(sizeof(char)));
        addInContext("sz-u", new ValueType<int>(sizeof(long long)));

        addInContext("pair?", BaseTypePredicates::fpairp);
        addInContext("lazy?", BaseTypePredicates::flazyp);
        addInContext("label?", BaseTypePredicates::flabelp);
        addInContext("context?", BaseTypePredicates::fcontextp);
        addInContext("atom?", BaseTypePredicates::fatomp);
        addInContext("symbol?", BaseTypePredicates::fsymbolp);
        addInContext("const?", BaseTypePredicates::fconstp);
        addInContext("macro?", BaseTypePredicates::fmacrop);
        addInContext("basemacro?", BaseTypePredicates::fbasemacrop);
        addInContext("usermacro?", BaseTypePredicates::fusermacrop);
        addInContext("spectype?", BaseTypePredicates::fvaluep);

        addInContext("ctx-get", BaseFunctions::fctxget);
        addInContext("ctx-push", BaseFunctions::fctxpush);
        addInContext("empty-ctx", Evaluator::eempty);
        addInContext("get-type", BaseFunctions::fgettype);
        addInContext("cons", BaseFunctions::fcons);
        addInContext("car", BaseFunctions::fcar);
        addInContext("cdr", BaseFunctions::fcdr);
        addInContext("eq", BaseFunctions::feq);

        a = new Context(Ob::anil, Ob::anil, a);
        addInSymbols("t", Ob::at);
        a = new Context(Ob::at, Ob::at, a);

        addInContext("^", BaseMacroses::mgensym);
        addInContext("~", BaseMacroses::mcurctx);
        addInContext("_", BaseMacroses::mbot);
        addInContext("|", BaseMacroses::mtry);
        addInContext("$", BaseMacroses::munlazy);
        addInContext("#", BaseMacroses::mlazy);
        addInContext("%", BaseMacroses::mmacro);
        addInContext("`", BaseMacroses::mapply);
        addInContext("@", BaseMacroses::mlabel);
        addInContext("?", BaseMacroses::mif);
        addInContext("\\", BaseMacroses::mlambda);
        addInContext(">-", BaseMacroses::mlet);
        addInContext("'", BaseMacroses::mquote);

        addInContext("symbols", symbols);
    }

public:
    FirstParser() : nosymbol("(){}[].\""), a(Ob::anil) {
        initTable();
    }

    Ob::Ptr parse(const string & _s) {
        s = _s;
        parseRes pr = parseExpression(s.begin());
        return pr.success ? pr.e : Ob::anil;
    }

    Ob::Ptr parseEval(const string & _s) {return parse(_s)->eval(a)->unlazy();}

    string evalToString(const string & _s) {
        stringstream ss;
        print(ss, parseEval(_s));
        return ss.str();
    }

    void print(ostream & ts, const Ob::Ptr & p) {printOb(ts, p);}

    void loadInitLibrary(const string & lib) {
        Ob::Ptr res = parseEval(lib);
        if(res->asEvaluator()) {
            a = res->asEvaluator()->getContext();
            cout << "initlib has loaded successfully" << endl;
        } else {
            cout << res->toString() << endl;
        }
    }

private:
    ostream & printOb(ostream & ts, const Ob::Ptr & p) {
        Symbol * sym = p->asSymbol();
        if(sym != 0)
            return printSymbol(ts, sym);
        if(p->asPair()) {
            ts << "(";
            return printList(ts, p->asPair());
        }
        if(p->asLazy())
            ts << "{lazy}";
        else if(p->asLabel())
            ts << "{label}";
        else if(p->asValue()) {
            Value * spt = p->asValue();
            if(spt->is<ValueType<int> >())
                ts << spt->as<ValueType<int> >()->getValue();
            else if(spt->is<ValueType<float> >())
                ts << spt->as<ValueType<float> >()->getValue();
            else if(spt->is<ValueType<char> >()) {
                char c = spt->as<ValueType<char> >()->getValue();
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
        return ts;
    }

    ostream & printSymbol(ostream & ts, Symbol * sym) {
        if(sym == Ob::anil->asSymbol()) {
            return ts << "()";
        } else {
            for(Ob * p = symbols.getPointer(); p != Ob::anil.getPointer(); p = p->cdr().getPointer()) {
                if(p->car()->car() == sym) {
                    ByteArray * ba = p->car()->cdr()->as<ByteArray>();
                    return ts.write(ba->getData(), ba->getSize());
                }
            }
        }
        return ts << "{sym}";
    }

    ostream & printList(ostream & ts, Pair * pr) {
        printOb(ts, pr->car());
        Ob::Ptr pcdr = pr->cdr();
        Atom * atom = pcdr->asAtom();
        if(atom != 0) {
            if(atom != Ob::anil->asAtom()) {
                ts << " . ";
                printOb(ts, pcdr);
            }
            ts << ")";
        } else {
            ts << " ";
            printList(ts, pcdr->asPair());
        }
        return ts;
    }


    struct parseRes {
        Ob::Ptr e;
        string::const_iterator rest;
        bool success;

        parseRes(const Ob::Ptr & _e, string::const_iterator _rest, bool _success)
            :e(_e), rest(_rest), success(_success) {}
    };

    struct lexRes {
        string::const_iterator rest;
        bool success;

        lexRes(string::const_iterator _rest, bool _success)
            : rest(_rest), success(_success) {}
    };

    parseRes parseExpression(string::const_iterator si) {
        lexRes lr = spaces(si);
        lr = lexem("(", lr.rest);
        return lr.success ? parseTail(lr.rest) : parseAtom(lr.rest);
    }

    parseRes parseTail(string::const_iterator si) {
        lexRes lr = spaces(si);
        lr = lexem(")", lr.rest);
        if(lr.success)
            return parseRes(Ob::anil, lr.rest, true);
        lr = lexem(".", lr.rest);
        if(lr.success) {
            lr = spaces(lr.rest);
            parseRes pr = parseExpression(lr.rest);
            if(!pr.success) {
                DBG("parseTail fail");
                return parseRes(Ob::anil, si, false);
            }
            lr = spaces(pr.rest);
            lr = lexem(")", lr.rest);
            if(lr.success)  {
                return parseRes(pr.e, lr.rest, true);
            } else {
                DBG("fail ) expected");
                parseRes(Ob::anil, si, false);
            }
        }
        parseRes pr1 = parseExpression(lr.rest);
        if(!pr1.success) {
            DBG("parseTail fail");
            return parseRes(Ob::anil, si, false);
        }
        parseRes pr2 = parseTail(pr1.rest);
        if(!pr2.success) {
            DBG("parseTail fail");
            return parseRes(Ob::anil, si, false);
        }
        return parseRes(new Pair(pr1.e, pr2.e), pr2.rest, true);
    }

    parseRes parseAtom(string::const_iterator si) {
        parseRes pr = parseNumber(si);
        if(pr.success) return pr;
        pr = parseString(si);
        if(pr.success) return pr;
        pr = parseChar(si);
        if(pr.success) return pr;
        pr = parseSymbol(si);
        return pr.success ? pr : parseRes(Ob::anil, si, false);
    }

    parseRes parseChar(string::const_iterator si) {
        string::const_iterator sii = si;
        if(sii == s.end() || *sii != '&')
            return parseRes(Ob::anil, si, false);
        else
            ++sii;
        if(sii == s.end() || *sii != '\"')
            return parseRes(Ob::anil, si, false);
        else
            ++sii;
        string chars;
        for( ; sii != s.end() && *sii != '\"'; ++sii)
            chars.push_back(*sii);
        if(sii != s.end())
            ++sii;
        return parseRes(new ValueType<char>(chars.size() > 0 ? chars[0] : '\"'), sii, true);
    }

    parseRes parseString(string::const_iterator si) {
        string::const_iterator sii = si;
        if(sii == s.end() || *sii != '\"')
            return parseRes(Ob::anil, si, false);
        else
            ++sii;
        string chars;
        for( ; sii != s.end() && *sii != '\"'; ++sii)
            chars.push_back(*sii);
        if(sii != s.end())
            ++sii;
        return parseRes(ByteArray::fromChars(chars.size(), chars.c_str()), sii, true);
    }

    parseRes parseSymbol(string::const_iterator si) {
        string symbolString;
        string::const_iterator sii = si;
        if(sii == s.end() || isspace(*sii) || (nosymbol.find(*sii) != string::npos)) {
            DBG("symbol fail first char ") << "\"" << *sii << "\"" << endl;
            if(sii == s.end()) DBG("isend");
            else if(isspace(*sii)) DBG("isspace");
            else if((nosymbol.find(*sii) != string::npos)) DBG("nosym");
            return parseRes(Ob::anil, si, false);
        }
        symbolString.push_back(*sii);
        ++sii;
        while(sii != s.end() && !isspace(*sii) && (nosymbol.find(*sii) == string::npos)) {
            symbolString.push_back(*sii);
            ++sii;
        }
        for(Ob * p = symbols.getPointer(); p != Ob::anil.getPointer(); p = p->cdr().getPointer()) {
            ByteArray * ba = p->car()->cdr()->as<ByteArray>();
            if(ba->getSize() == symbolString.size() &&
                !memcmp(ba->getData(), symbolString.data(), symbolString.size()))
                return parseRes(p->car()->car().getPointer(), sii, true);
        }
        Symbol * sym = new Symbol();
        symbols = new Pair(new Pair(sym, ByteArray::fromChars(symbolString.size(), symbolString.data())), symbols);
        return parseRes(sym, sii, true);
    }

    parseRes parseNumber(string::const_iterator si) {
        string number;
        string::const_iterator sii = si;
        if(sii == s.end() || !isdigit(*sii) && *sii != '-' || isspace(*sii) || (nosymbol.find(*sii) != string::npos)) {
            return parseRes(Ob::anil, si, false);
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
                return parseRes(new ValueType<int>(i), sii, true);
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
                return parseRes(new ValueType<float>(f), sii, true);
            else {
                DBG("float is not float");
            }
        }
        return parseRes(Ob::anil, si, false);
    }

    lexRes lexem(string lex, string::const_iterator si) {
        string::const_iterator sii = si;
        for(string::const_iterator it = lex.begin(); it != lex.end(); ++it) {
            if(sii == s.end() || *sii != *it)
                return lexRes(si, false);
            ++sii;
        }
        return lexRes(sii, true);
    }

    lexRes spaces(string::const_iterator si) {
        while(si != s.end() && isspace(*si))
            ++si;
        return lexRes(si, true);
    }
};
