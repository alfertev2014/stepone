#ifndef FASTPARSER_H
#define FASTPARSER_H

#include "stepone.h"
#include "basemacro.h"
#include "basefunc.h"
#include "basenumfunc.h"
#include "numbers.h"

#include <string>
#include <map>

using namespace std;

class FastParser {
    map<string, Ob::Ptr> parsingTable;

    string s;

    string nosymbol;

    Ob::Ptr a;

    static const Ob::Ptr acar;
    static const Ob::Ptr acdr;
    static const Ob::Ptr acons;
    static const Ob::Ptr aatom;
    static const Ob::Ptr aeq;

    static const Ob::Ptr aintPlus;
    static const Ob::Ptr aintMinus;
    static const Ob::Ptr aintProduct;
    static const Ob::Ptr aintDivision;
    static const Ob::Ptr aintMod;
    static const Ob::Ptr aintp;
    static const Ob::Ptr aintEql;
    static const Ob::Ptr aintNE;
    static const Ob::Ptr aintGT;
    static const Ob::Ptr aintLT;
    static const Ob::Ptr aintGE;
    static const Ob::Ptr aintLE;

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

    void initTable() {
        parsingTable.clear();
        parsingTable.insert(pair<string, Ob::Ptr>("nil", Ob::anil));
        parsingTable.insert(pair<string, Ob::Ptr>("t", Ob::at));
        parsingTable.insert(pair<string, Ob::Ptr>("?", Ob::aif));
        parsingTable.insert(pair<string, Ob::Ptr>("\'", Ob::aquote));
        parsingTable.insert(pair<string, Ob::Ptr>(">-", Ob::alet));
        parsingTable.insert(pair<string, Ob::Ptr>("~", Ob::aeval));
        parsingTable.insert(pair<string, Ob::Ptr>("\\", Ob::alambda));
        parsingTable.insert(pair<string, Ob::Ptr>("#", Ob::alazy));
        parsingTable.insert(pair<string, Ob::Ptr>("$", Ob::aunlazy));
        parsingTable.insert(pair<string, Ob::Ptr>("@", Ob::alabel));

        parsingTable.insert(pair<string, Ob::Ptr>("car", acar));
        parsingTable.insert(pair<string, Ob::Ptr>("cdr", acdr));
        parsingTable.insert(pair<string, Ob::Ptr>("cons", acons));
        parsingTable.insert(pair<string, Ob::Ptr>("atom", aatom));
        parsingTable.insert(pair<string, Ob::Ptr>("eq", aeq));

        parsingTable.insert(pair<string, Ob::Ptr>("i+", aintPlus));
        parsingTable.insert(pair<string, Ob::Ptr>("i-", aintMinus));
        parsingTable.insert(pair<string, Ob::Ptr>("i*", aintProduct));
        parsingTable.insert(pair<string, Ob::Ptr>("i/", aintDivision));
        parsingTable.insert(pair<string, Ob::Ptr>("i%", aintMod));
        parsingTable.insert(pair<string, Ob::Ptr>("i?", aintp));
        parsingTable.insert(pair<string, Ob::Ptr>("i=", aintEql));
        parsingTable.insert(pair<string, Ob::Ptr>("i!=", aintNE));
        parsingTable.insert(pair<string, Ob::Ptr>("i<", aintLT));
        parsingTable.insert(pair<string, Ob::Ptr>("i>", aintGT));
        parsingTable.insert(pair<string, Ob::Ptr>("i<=", aintLE));
        parsingTable.insert(pair<string, Ob::Ptr>("i>=", aintGE));

        parsingTable.insert(pair<string, Ob::Ptr>("f+", afloatPlus));
        parsingTable.insert(pair<string, Ob::Ptr>("f-", afloatMinus));
        parsingTable.insert(pair<string, Ob::Ptr>("f*", afloatProduct));
        parsingTable.insert(pair<string, Ob::Ptr>("f/", afloatDivision));
        parsingTable.insert(pair<string, Ob::Ptr>("f?", afloatp));
        parsingTable.insert(pair<string, Ob::Ptr>("f=", afloatEql));
        parsingTable.insert(pair<string, Ob::Ptr>("f!=", afloatNE));
        parsingTable.insert(pair<string, Ob::Ptr>("f<", afloatLT));
        parsingTable.insert(pair<string, Ob::Ptr>("f>", afloatGT));
        parsingTable.insert(pair<string, Ob::Ptr>("f<=", afloatLE));
        parsingTable.insert(pair<string, Ob::Ptr>("f>=", afloatGE));

        parsingTable.insert(pair<string, Ob::Ptr>("f2i", afloat2int));
        parsingTable.insert(pair<string, Ob::Ptr>("i2f", aint2float));
    }

public:
    FastParser() : s(""), nosymbol("(){}[].\""), a(Ob::anil) {
        a = new Context(Ob::aif, BaseMacroses::mif, a);
        a = new Context(Ob::aquote, BaseMacroses::mquote, a);
        a = new Context(Ob::alambda, BaseMacroses::mlambda, a);
        a = new Context(Ob::alet, BaseMacroses::mlet, a);
        a = new Context(Ob::alabel, BaseMacroses::mlabel, a);
        a = new Context(Ob::alazy, BaseMacroses::mlazy, a);
        a = new Context(Ob::aunlazy, BaseMacroses::munlazy, a);
        a = new Context(Ob::aeval, BaseMacroses::meval, a);

        a = new Context(acar, BaseFunctions::fcar, a);
        a = new Context(acdr, BaseFunctions::fcdr, a);
        a = new Context(acons, BaseFunctions::fcons, a);
        a = new Context(aatom, BaseFunctions::fatom, a);
        a = new Context(aeq, BaseFunctions::feq, a);

        a = new Context(aintPlus, BaseNumFunc::fintPlus, a);
        a = new Context(aintMinus, BaseNumFunc::fintMinus, a);
        a = new Context(aintProduct, BaseNumFunc::fintProduct, a);
        a = new Context(aintDivision, BaseNumFunc::fintDivision, a);
        a = new Context(aintMod, BaseNumFunc::fintMod, a);
        a = new Context(aintp, BaseNumFunc::fintp, a);
        a = new Context(aintEql, BaseNumFunc::fintEql, a);
        a = new Context(aintNE, BaseNumFunc::fintNE, a);
        a = new Context(aintLT, BaseNumFunc::fintLT, a);
        a = new Context(aintGT, BaseNumFunc::fintGT, a);
        a = new Context(aintLE, BaseNumFunc::fintLE, a);
        a = new Context(aintGE, BaseNumFunc::fintGE, a);

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
            if(f->isOperation())
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
            if(spt->isInteger())
                ts << spt->asInteger()->getInteger();
            else if(spt->isFloat())
                ts << spt->asFloat()->getFloat();
            else
                ts << "{SpecType}";
        }
        return ts;
    }

    ostream & printSymbol(ostream & ts, Symbol * sym) {
        if(sym == Ob::anil->asSymbol()) {
            ts << "()";
        } else {
            for(map<string, Ob::Ptr>::iterator it = parsingTable.begin(); it != parsingTable.end(); ++it) {
                if(it->second == sym) {
                    ts << it->first;
                    break;
                }
            }
        }
        return ts;
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
        if(parsingTable.count(symbol) > 0) {
            e = parsingTable[symbol];
        } else {
            Symbol * sym = new Symbol();
            parsingTable.insert(pair<string, Ob::Ptr>(symbol, sym));
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
                return parseRes(new Integer(i), sii, true);
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
                return parseRes(new Float(f), sii, true);
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
