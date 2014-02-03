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

    static const Ob::Ptr acar;
    static const Ob::Ptr acdr;
    static const Ob::Ptr acons;
    static const Ob::Ptr aeq;
    static const Ob::Ptr actxget;
    static const Ob::Ptr actxpush;
    static const Ob::Ptr aemptyctx;
    static const Ob::Ptr agettype;

    static const Ob::Ptr apairp;
    static const Ob::Ptr alazyp;
    static const Ob::Ptr alabelp;
    static const Ob::Ptr acontextp;
    static const Ob::Ptr aatomp;
    static const Ob::Ptr asymbolp;
    static const Ob::Ptr aconstp;
    static const Ob::Ptr amacrop;
    static const Ob::Ptr abasemacrop;
    static const Ob::Ptr ausermacrop;
    static const Ob::Ptr afunctionp;
    static const Ob::Ptr abasefunctionp;
    static const Ob::Ptr aclosurep;
    static const Ob::Ptr aspectypep;

    static const Ob::Ptr aintNeg;
    static const Ob::Ptr aintPlus;
    static const Ob::Ptr aintMinus;
    static const Ob::Ptr aintProduct;
    static const Ob::Ptr aintDivision;
    static const Ob::Ptr aintMod;
    static const Ob::Ptr aintp;
    static const Ob::Ptr abitnot;
    static const Ob::Ptr abitand;
    static const Ob::Ptr abitor;
    static const Ob::Ptr abitxor;
    static const Ob::Ptr aintEql;
    static const Ob::Ptr aintNE;
    static const Ob::Ptr aintGT;
    static const Ob::Ptr aintLT;
    static const Ob::Ptr aintGE;
    static const Ob::Ptr aintLE;

    static const Ob::Ptr afloatNeg;
    static const Ob::Ptr afloatPlus;
    static const Ob::Ptr afloatMinus;
    static const Ob::Ptr afloatProduct;
    static const Ob::Ptr afloatDivision;
    static const Ob::Ptr afloatp;
    static const Ob::Ptr afloatEql;
    static const Ob::Ptr afloatNE;
    static const Ob::Ptr afloatGT;
    static const Ob::Ptr afloatLT;
    static const Ob::Ptr afloatGE;
    static const Ob::Ptr afloatLE;

    static const Ob::Ptr afloat2int;
    static const Ob::Ptr aint2float;

    static const Ob::Ptr avecp;
    static const Ob::Ptr amkvec;
    static const Ob::Ptr aveclen;
    static const Ob::Ptr avecel;
    static const Ob::Ptr aveccat;

    void initTable() {
        symbolTable.clear();
        symbolTable.insert(pair<string, Ob::Ptr>("t", Ob::at));
        symbolTable.insert(pair<string, Ob::Ptr>("?", Ob::aif));
        symbolTable.insert(pair<string, Ob::Ptr>("\'", Ob::aquote));
        symbolTable.insert(pair<string, Ob::Ptr>(">-", Ob::alet));
        symbolTable.insert(pair<string, Ob::Ptr>("~", Ob::aeval));
        symbolTable.insert(pair<string, Ob::Ptr>("\\", Ob::alambda));
        symbolTable.insert(pair<string, Ob::Ptr>("#", Ob::alazy));
        symbolTable.insert(pair<string, Ob::Ptr>("$", Ob::aunlazy));
        symbolTable.insert(pair<string, Ob::Ptr>("@", Ob::alabel));
        symbolTable.insert(pair<string, Ob::Ptr>("%", Ob::amacro));
        symbolTable.insert(pair<string, Ob::Ptr>("^", Ob::agensym));

        symbolTable.insert(pair<string, Ob::Ptr>("car", acar));
        symbolTable.insert(pair<string, Ob::Ptr>("cdr", acdr));
        symbolTable.insert(pair<string, Ob::Ptr>("cons", acons));
        symbolTable.insert(pair<string, Ob::Ptr>("eq", aeq));
        symbolTable.insert(pair<string, Ob::Ptr>("ctx-get", actxget));
        symbolTable.insert(pair<string, Ob::Ptr>("ctx-push", actxpush));
        symbolTable.insert(pair<string, Ob::Ptr>("empty-ctx", aemptyctx));
        symbolTable.insert(pair<string, Ob::Ptr>("get-type", agettype));

        symbolTable.insert(pair<string, Ob::Ptr>("pair?", apairp));
        symbolTable.insert(pair<string, Ob::Ptr>("lazy?", alazyp));
        symbolTable.insert(pair<string, Ob::Ptr>("label?", alabelp));
        symbolTable.insert(pair<string, Ob::Ptr>("context?", acontextp));
        symbolTable.insert(pair<string, Ob::Ptr>("atom?", aatomp));
        symbolTable.insert(pair<string, Ob::Ptr>("symbol?", asymbolp));
        symbolTable.insert(pair<string, Ob::Ptr>("const?", aconstp));
        symbolTable.insert(pair<string, Ob::Ptr>("macro?", amacrop));
        symbolTable.insert(pair<string, Ob::Ptr>("basemacro?", abasemacrop));
        symbolTable.insert(pair<string, Ob::Ptr>("usermacro?", ausermacrop));
        symbolTable.insert(pair<string, Ob::Ptr>("function?", afunctionp));
        symbolTable.insert(pair<string, Ob::Ptr>("basefunction?", abasefunctionp));
        symbolTable.insert(pair<string, Ob::Ptr>("closure?", aclosurep));
        symbolTable.insert(pair<string, Ob::Ptr>("stectype?", aspectypep));

        symbolTable.insert(pair<string, Ob::Ptr>("-i", aintNeg));
        symbolTable.insert(pair<string, Ob::Ptr>("i+", aintPlus));
        symbolTable.insert(pair<string, Ob::Ptr>("i-", aintMinus));
        symbolTable.insert(pair<string, Ob::Ptr>("i*", aintProduct));
        symbolTable.insert(pair<string, Ob::Ptr>("i/", aintDivision));
        symbolTable.insert(pair<string, Ob::Ptr>("i%", aintMod));
        symbolTable.insert(pair<string, Ob::Ptr>("i?", aintp));
        symbolTable.insert(pair<string, Ob::Ptr>("bit-not", abitnot));
        symbolTable.insert(pair<string, Ob::Ptr>("bit-and", abitand));
        symbolTable.insert(pair<string, Ob::Ptr>("bit-or", abitor));
        symbolTable.insert(pair<string, Ob::Ptr>("bit-xor", abitxor));
        symbolTable.insert(pair<string, Ob::Ptr>("i=", aintEql));
        symbolTable.insert(pair<string, Ob::Ptr>("i!=", aintNE));
        symbolTable.insert(pair<string, Ob::Ptr>("i<", aintLT));
        symbolTable.insert(pair<string, Ob::Ptr>("i>", aintGT));
        symbolTable.insert(pair<string, Ob::Ptr>("i<=", aintLE));
        symbolTable.insert(pair<string, Ob::Ptr>("i>=", aintGE));

        symbolTable.insert(pair<string, Ob::Ptr>("-f", afloatNeg));
        symbolTable.insert(pair<string, Ob::Ptr>("f+", afloatPlus));
        symbolTable.insert(pair<string, Ob::Ptr>("f-", afloatMinus));
        symbolTable.insert(pair<string, Ob::Ptr>("f*", afloatProduct));
        symbolTable.insert(pair<string, Ob::Ptr>("f/", afloatDivision));
        symbolTable.insert(pair<string, Ob::Ptr>("f?", afloatp));
        symbolTable.insert(pair<string, Ob::Ptr>("f=", afloatEql));
        symbolTable.insert(pair<string, Ob::Ptr>("f!=", afloatNE));
        symbolTable.insert(pair<string, Ob::Ptr>("f<", afloatLT));
        symbolTable.insert(pair<string, Ob::Ptr>("f>", afloatGT));
        symbolTable.insert(pair<string, Ob::Ptr>("f<=", afloatLE));
        symbolTable.insert(pair<string, Ob::Ptr>("f>=", afloatGE));

        symbolTable.insert(pair<string, Ob::Ptr>("f2i", afloat2int));
        symbolTable.insert(pair<string, Ob::Ptr>("i2f", aint2float));

        symbolTable.insert(pair<string, Ob::Ptr>("vec?", avecp));
        symbolTable.insert(pair<string, Ob::Ptr>("mkvec", amkvec));
        symbolTable.insert(pair<string, Ob::Ptr>("vec-len", aveclen));
        symbolTable.insert(pair<string, Ob::Ptr>("vec-get", avecel));
        symbolTable.insert(pair<string, Ob::Ptr>("vec-cat", aveccat));
    }

public:
    FastParser() : s(""), nosymbol("(){}[].\""), a(Ob::anil) {
        a = new Context(Ob::anil, Ob::anil, a);
        a = new Context(Ob::at, Ob::at, a);

        a = new Context(Ob::aif, BaseMacroses::mif, a);
        a = new Context(Ob::aquote, BaseMacroses::mquote, a);
        a = new Context(Ob::alambda, BaseMacroses::mlambda, a);
        a = new Context(Ob::alet, BaseMacroses::mlet, a);
        a = new Context(Ob::alabel, BaseMacroses::mlabel, a);
        a = new Context(Ob::alazy, BaseMacroses::mlazy, a);
        a = new Context(Ob::aunlazy, BaseMacroses::munlazy, a);
        a = new Context(Ob::aeval, BaseMacroses::meval, a);
        a = new Context(Ob::amacro, BaseMacroses::mmacro, a);
        a = new Context(Ob::agensym, BaseMacroses::mgensym, a);

        a = new Context(acar, BaseFunctions::fcar, a);
        a = new Context(acdr, BaseFunctions::fcdr, a);
        a = new Context(acons, BaseFunctions::fcons, a);
        a = new Context(aeq, BaseFunctions::feq, a);
        a = new Context(actxget, BaseFunctions::fctxget, a);
        a = new Context(actxpush, BaseFunctions::fctxpush, a);
        a = new Context(aemptyctx, Evaluator::eempty, a);
        a = new Context(agettype, BaseFunctions::fgettype, a);

        a = new Context(apairp, BaseTypePredicates::fpairp, a);
        a = new Context(alazyp, BaseTypePredicates::flazyp, a);
        a = new Context(alabelp, BaseTypePredicates::flabelp, a);
        a = new Context(acontextp, BaseTypePredicates::fcontextp, a);
        a = new Context(aatomp, BaseTypePredicates::fatomp, a);
        a = new Context(asymbolp, BaseTypePredicates::fsymbolp, a);
        a = new Context(aconstp, BaseTypePredicates::fconstp, a);
        a = new Context(amacrop, BaseTypePredicates::fmacrop, a);
        a = new Context(abasemacrop, BaseTypePredicates::fbasemacrop, a);
        a = new Context(ausermacrop, BaseTypePredicates::fusermacrop, a);
        a = new Context(afunctionp, BaseTypePredicates::ffunctionp, a);
        a = new Context(abasefunctionp, BaseTypePredicates::fbasefunctionp, a);
        a = new Context(aclosurep, BaseTypePredicates::fclosurep, a);
        a = new Context(aspectypep, BaseTypePredicates::fspectypep, a);

        a = new Context(aintNeg, BaseNumFunc::fintNeg, a);
        a = new Context(aintPlus, BaseNumFunc::fintPlus, a);
        a = new Context(aintMinus, BaseNumFunc::fintMinus, a);
        a = new Context(aintProduct, BaseNumFunc::fintProduct, a);
        a = new Context(aintDivision, BaseNumFunc::fintDivision, a);
        a = new Context(aintMod, BaseNumFunc::fintMod, a);
        a = new Context(aintp, BaseNumFunc::fintp, a);
        a = new Context(abitnot, BaseNumFunc::fbitnot, a);
        a = new Context(abitand, BaseNumFunc::fbitand, a);
        a = new Context(abitor, BaseNumFunc::fbitor, a);
        a = new Context(abitxor, BaseNumFunc::fbitxor, a);
        a = new Context(aintEql, BaseNumFunc::fintEql, a);
        a = new Context(aintNE, BaseNumFunc::fintNE, a);
        a = new Context(aintLT, BaseNumFunc::fintLT, a);
        a = new Context(aintGT, BaseNumFunc::fintGT, a);
        a = new Context(aintLE, BaseNumFunc::fintLE, a);
        a = new Context(aintGE, BaseNumFunc::fintGE, a);

        a = new Context(afloatNeg, BaseNumFunc::ffloatNeg, a);
        a = new Context(afloatPlus, BaseNumFunc::ffloatPlus, a);
        a = new Context(afloatMinus, BaseNumFunc::ffloatMinus, a);
        a = new Context(afloatProduct, BaseNumFunc::ffloatProduct, a);
        a = new Context(afloatDivision, BaseNumFunc::ffloatDivision, a);
        a = new Context(afloatp, BaseNumFunc::ffloatp, a);
        a = new Context(afloatEql, BaseNumFunc::ffloatEql, a);
        a = new Context(afloatNE, BaseNumFunc::ffloatNE, a);
        a = new Context(afloatLT, BaseNumFunc::ffloatLT, a);
        a = new Context(afloatGT, BaseNumFunc::ffloatGT, a);
        a = new Context(afloatLE, BaseNumFunc::ffloatLE, a);
        a = new Context(afloatGE, BaseNumFunc::ffloatGE, a);

        a = new Context(afloat2int, BaseNumFunc::ffloat2int, a);
        a = new Context(aint2float, BaseNumFunc::fint2float, a);

        a = new Context(avecp, VectorFunctions::fvecp, a);
        a = new Context(amkvec, VectorFunctions::fmkvec, a);
        a = new Context(avecel, VectorFunctions::fvecel, a);
        a = new Context(aveccat, VectorFunctions::fveccat, a);

        initTable();
    }

    Ob::Ptr parse(string _s) {
        s = _s;
        parseRes pr = parseExpression(s.begin());
        return pr.success ? pr.e : Ob::anil;
    }

    Ob::Ptr parseEval(string _s) {return parse(_s)->eval(a);}

    string evalToString(string _s) {
        stringstream ss;
        print(ss, parse(_s)->eval(a));
        return ss.str();
    }

    void print(ostream & ts, const Ob::Ptr & p) {printOb(ts, p);}

    void loadInitLibrary(string lib) {
        Ob::Ptr res = parseEval(lib);
        if(res->isEvaluator()) {
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
        if(p->isPair()) {
            ts << "(";
            return printList(ts, p->asPair());
        }
        if(p->isFunction()) {
            Function * f = p->asFunction();
            if(f->isBaseFunction())
                ts << f->toString();
            else
                ts << "{closure}";
        }
        else if(p->isLazy())
            ts << "{lazy}";
        else if(p->isLabel())
            ts << "{label}";
        else if(p->isSpecType()) {
            SpecType * spt = p->asSpecType();
            if(spt->is<SpecTypeTemp<int> >())
                ts << spt->as<SpecTypeTemp<int> >()->getValue();
            else if(spt->is<SpecTypeTemp<float> >())
                ts << spt->as<SpecTypeTemp<float> >()->getValue();
            else if(spt->is<Vector>()) {
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
        Symbol * sym = pcdr->asSymbol();
        if(sym != 0) {
            if(sym != Ob::anil->asSymbol()) {
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
        pr = parseSymbol(si);
        return pr.success ? pr : parseRes(Ob::anil, si, false);
    }

    parseRes parseSymbol(string::const_iterator si) {
        string symbol("");
        string::const_iterator sii = si;
        if(sii == s.end() || isspace(*sii) || (nosymbol.find(*sii) != string::npos)) {
            DBG("symbol fail first char ") << "\"" << *sii << "\"" << endl;
            if(sii == s.end()) DBG("isend");
            if(isspace(*sii)) DBG("isspace");
            if((nosymbol.find(*sii) != string::npos)) DBG("nosym");
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

    parseRes parseNumber(string::const_iterator si)
    {
        string number("");
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
                return parseRes(new SpecTypeTemp<int>(i), sii, true);
            else
                DBG("int is not int");
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
                return parseRes(new SpecTypeTemp<float>(f), sii, true);
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
