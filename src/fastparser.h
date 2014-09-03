#ifndef FASTPARSER_H
#define FASTPARSER_H

#include "dbg.h"

#include "stepone.h"

#include <string>
#include <map>

using namespace std;

class ParserIterator {
    string::const_iterator si;
};

class FastParser {
    map<string, Ob::Ptr> symbolTable;

    string s;

    string nosymbol;

    Ob::Ptr a;

    void pushInContext(string s, const Ob::Ptr & v) {
        Ob::Ptr p = new Symbol();
        symbolTable.insert(pair<string, Ob::Ptr>(s, p));
        a = new Context(p, v, a);
    }

    void initTable() {
        symbolTable.clear();

        pushInContext("-i", BaseNumFunc::fintNeg);
        pushInContext("i+", BaseNumFunc::fintPlus);
        pushInContext("i-", BaseNumFunc::fintMinus);
        pushInContext("i*", BaseNumFunc::fintProduct);
        pushInContext("i/", BaseNumFunc::fintDivision);
        pushInContext("i%", BaseNumFunc::fintMod);
        pushInContext("i?", BaseNumFunc::fintp);
        pushInContext("i-not", BaseNumFunc::fintnot);
        pushInContext("i-and", BaseNumFunc::fintand);
        pushInContext("i-or", BaseNumFunc::fintor);
        pushInContext("i-xor", BaseNumFunc::fintxor);
        pushInContext("i-shl", BaseNumFunc::fintshl);
        pushInContext("i-shr", BaseNumFunc::fintshr);
        pushInContext("i=", BaseNumFunc::fintEql);
        pushInContext("i!=", BaseNumFunc::fintNE);
        pushInContext("i<", BaseNumFunc::fintLT);
        pushInContext("i>", BaseNumFunc::fintGT);
        pushInContext("i<=", BaseNumFunc::fintLE);
        pushInContext("i>=", BaseNumFunc::fintGE);

        pushInContext("u?", BaseNumFunc::flongp);
        pushInContext("u-not", BaseNumFunc::flongnot);
        pushInContext("u-and", BaseNumFunc::flongand);
        pushInContext("u-or", BaseNumFunc::flongor);
        pushInContext("u-xor", BaseNumFunc::flongxor);
        pushInContext("u-shl", BaseNumFunc::flongshl);
        pushInContext("u-shr", BaseNumFunc::flongshr);

        pushInContext("u=", BaseNumFunc::flongEql);
        pushInContext("u!=", BaseNumFunc::flongNE);
        pushInContext("u<", BaseNumFunc::flongLT);
        pushInContext("u>", BaseNumFunc::flongGT);
        pushInContext("u<=", BaseNumFunc::flongLE);
        pushInContext("u>=", BaseNumFunc::flongGE);

        pushInContext("c?", BaseNumFunc::fcharp);
        pushInContext("c-not", BaseNumFunc::fcharnot);
        pushInContext("c-and", BaseNumFunc::fcharand);
        pushInContext("c-or", BaseNumFunc::fcharor);
        pushInContext("c-xor", BaseNumFunc::fcharxor);
        pushInContext("c-shl", BaseNumFunc::fcharshl);
        pushInContext("c-shr", BaseNumFunc::fcharshr);
        pushInContext("c=", BaseNumFunc::fcharEql);
        pushInContext("c!=", BaseNumFunc::fcharNE);
        pushInContext("c<", BaseNumFunc::fcharLT);
        pushInContext("c>", BaseNumFunc::fcharGT);
        pushInContext("c<=", BaseNumFunc::fcharLE);
        pushInContext("c>=", BaseNumFunc::fcharGE);

        pushInContext("-f", BaseNumFunc::ffloatNeg);
        pushInContext("f+", BaseNumFunc::ffloatPlus);
        pushInContext("f-", BaseNumFunc::ffloatMinus);
        pushInContext("f*", BaseNumFunc::ffloatProduct);
        pushInContext("f/", BaseNumFunc::ffloatDivision);
        pushInContext("f?", BaseNumFunc::ffloatp);
        pushInContext("f=", BaseNumFunc::ffloatEql);
        pushInContext("f!=", BaseNumFunc::ffloatNE);
        pushInContext("f<", BaseNumFunc::ffloatLT);
        pushInContext("f>", BaseNumFunc::ffloatGT);
        pushInContext("f<=", BaseNumFunc::ffloatLE);
        pushInContext("f>=", BaseNumFunc::ffloatGE);

        pushInContext("u2i", BaseNumFunc::flong2int);
        pushInContext("i2u", BaseNumFunc::fint2long);
        pushInContext("f2i", BaseNumFunc::ffloat2int);
        pushInContext("i2f", BaseNumFunc::fint2float);
        pushInContext("c2i", BaseNumFunc::fchar2int);
        pushInContext("i2c", BaseNumFunc::fint2char);
        pushInContext("c2u", BaseNumFunc::fchar2long);
        pushInContext("u2c", BaseNumFunc::flong2char);

        pushInContext("vec?", VectorFunctions::fvecp);
        pushInContext("mkvec", VectorFunctions::fmkvec);
        pushInContext("vec-len", VectorFunctions::fveclen);
        pushInContext("vec-mid", VectorFunctions::fvecmid);
        pushInContext("vec-el", VectorFunctions::fvecel);
        pushInContext("vec-cat", VectorFunctions::fveccat);

        pushInContext("b?", ByteArrayFunctions::fbytesp);
        pushInContext("b-len", ByteArrayFunctions::fbyteslen);
        pushInContext("b-cat", ByteArrayFunctions::fbytescat);
        pushInContext("b-mid", ByteArrayFunctions::fbytesmid);
        pushInContext("i2b", ByteArrayFunctions::fserint);
        pushInContext("f2b", ByteArrayFunctions::fserfloat);
        pushInContext("c2b", ByteArrayFunctions::fserchar);
        pushInContext("u1-2b", ByteArrayFunctions::fserbyte);
        pushInContext("u2-2b", ByteArrayFunctions::fser2bytes);
        pushInContext("u4-2b", ByteArrayFunctions::fser4bytes);
        pushInContext("u8-2b", ByteArrayFunctions::fser8bytes);
        pushInContext("b-geti", ByteArrayFunctions::fgetint);
        pushInContext("b-getf", ByteArrayFunctions::fgetfloat);
        pushInContext("b-getc", ByteArrayFunctions::fgetchar);
        pushInContext("b-getu1", ByteArrayFunctions::fgetbyte);
        pushInContext("b-getu2", ByteArrayFunctions::fget2bytes);
        pushInContext("b-getu4", ByteArrayFunctions::fget4bytes);
        pushInContext("b-getu8", ByteArrayFunctions::fget8bytes);

        pushInContext("sz-i", new ValueType<int>(sizeof(int)));
        pushInContext("sz-f", new ValueType<int>(sizeof(float)));
        pushInContext("sz-c", new ValueType<int>(sizeof(char)));
        pushInContext("sz-u", new ValueType<int>(sizeof(long long)));

        pushInContext("pair?", BaseTypePredicates::fpairp);
        pushInContext("lazy?", BaseTypePredicates::flazyp);
        pushInContext("label?", BaseTypePredicates::flabelp);
        pushInContext("context?", BaseTypePredicates::fcontextp);
        pushInContext("atom?", BaseTypePredicates::fatomp);
        pushInContext("symbol?", BaseTypePredicates::fsymbolp);
        pushInContext("const?", BaseTypePredicates::fconstp);
        pushInContext("macro?", BaseTypePredicates::fmacrop);
        pushInContext("basemacro?", BaseTypePredicates::fbasemacrop);
        pushInContext("usermacro?", BaseTypePredicates::fusermacrop);
        pushInContext("function?", BaseTypePredicates::ffunctionp);
        pushInContext("basefunction?", BaseTypePredicates::fbasefunctionp);
        pushInContext("closure?", BaseTypePredicates::fclosurep);
        pushInContext("stectype?", BaseTypePredicates::fspectypep);

        pushInContext("ctx-get", BaseFunctions::fctxget);
        pushInContext("ctx-push", BaseFunctions::fctxpush);
        pushInContext("empty-ctx", Evaluator::eempty);
        pushInContext("get-type", BaseFunctions::fgettype);
        pushInContext("cons", BaseFunctions::fcons);
        pushInContext("car", BaseFunctions::fcar);
        pushInContext("cdr", BaseFunctions::fcdr);
        pushInContext("eq", BaseFunctions::feq);

        a = new Context(Ob::anil, Ob::anil, a);
        symbolTable.insert(pair<string, Ob::Ptr>("t", Ob::at));
        a = new Context(Ob::at, Ob::at, a);

        pushInContext("^", BaseMacroses::mgensym);
        pushInContext("~", BaseMacroses::meval);
        pushInContext("_", BaseMacroses::mbot);
        pushInContext("|", BaseMacroses::mtry);
        pushInContext("$", BaseMacroses::munlazy);
        pushInContext("#", BaseMacroses::mlazy);
        pushInContext("%", BaseMacroses::mmacro);
        pushInContext("\'", BaseMacroses::mquote);
        pushInContext("@", BaseMacroses::mlabel);
        pushInContext("\\", BaseMacroses::mlambda);
        pushInContext("?", BaseMacroses::mif);
        pushInContext(">-", BaseMacroses::mlet);
    }

public:
    FastParser() : s(""), nosymbol("(){}[].\""), a(Ob::anil) {
        initTable();
    }

    Ob::Ptr parse(string _s) {
        s = _s;
        parseRes pr = parseExpression(s.begin());
        return pr.success ? pr.e : Ob::anil;
    }

    Ob::Ptr parseEval(string _s) {return parse(_s)->eval(a)->unlazy();}

    string evalToString(string _s) {
        stringstream ss;
        print(ss, parseEval(_s));
        return ss.str();
    }

    void print(ostream & ts, const Ob::Ptr & p) {printOb(ts, p);}

    void loadInitLibrary(string lib) {
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
        if(p->asFunction()) {
            Function * f = p->asFunction();
            if(f->asBaseFunction())
                ts << f->toString();
            else
                ts << "{closure}";
        }
        else if(p->asLazy())
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
            for(map<string, Ob::Ptr>::iterator it = symbolTable.begin(); it != symbolTable.end(); ++it) {
                if(it->second == sym) {
                    return ts << it->first;
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
        string symbol("");
        string::const_iterator sii = si;
        if(sii == s.end() || isspace(*sii) || (nosymbol.find(*sii) != string::npos)) {
            DBG("symbol fail first char ") << "\"" << *sii << "\"" << endl;
            if(sii == s.end()) DBG("isend");
            else if(isspace(*sii)) DBG("isspace");
            else if((nosymbol.find(*sii) != string::npos)) DBG("nosym");
            return parseRes(Ob::anil, si, false);
        }
        symbol.push_back(*sii);
        ++sii;
        while(sii != s.end() && !isspace(*sii) && (nosymbol.find(*sii) == string::npos)) {
            symbol.push_back(*sii);
            ++sii;
        }
        Ob::Ptr e(Ob::anil);
        if(symbolTable.count(symbol) > 0) {
            e = symbolTable[symbol];
        } else {
            Symbol * sym = new Symbol();
            symbolTable.insert(pair<string, Ob::Ptr>(symbol, sym));
            e = sym;
        }
        return parseRes(e, sii, true);
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

#endif // FASTPARSER_H
