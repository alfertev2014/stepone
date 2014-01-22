#ifndef FASTPARSER_H
#define FASTPARSER_H

#include "stepone.h"
#include "typestemp.h"
#include "numfunctemp.h"
#include "basefunc.h"
#include "basenumfunc.h"

#include <string>
#include <map>

using namespace std;

class FastParser
{
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

    void initTable()
    {
        parsingTable.clear();
        parsingTable.insert("nil", Ob::anil);
        parsingTable.insert("t", Ob::at);
        parsingTable.insert("?", Ob::aif);
        parsingTable.insert("\'", Ob::aquote);
        parsingTable.insert(">-", Ob::alet);
        parsingTable.insert("~", Ob::aeval);
        parsingTable.insert("\\", Ob::alambda);
        parsingTable.insert("#", Ob::alazy);
        parsingTable.insert("$", Ob::aunlazy);
        parsingTable.insert("@", Ob::alabel);
        parsingTable.insert("|", Ob::atry);
        parsingTable.insert(";", Ob::ado);
        parsingTable.insert("_", Ob::abot);

        parsingTable.insert("car", acar);
        parsingTable.insert("cdr", acdr);
        parsingTable.insert("cons", acons);
        parsingTable.insert("atom", aatom);
        parsingTable.insert("eq", aeq);

        parsingTable.insert("i+", aintPlus);
        parsingTable.insert("i-", aintMinus);
        parsingTable.insert("i*", aintProduct);
        parsingTable.insert("i/", aintDivision);
        parsingTable.insert("i%", aintMod);
        parsingTable.insert("i?", aintp);
        parsingTable.insert("i=", aintEql);
        parsingTable.insert("i!=", aintNE);
        parsingTable.insert("i<", aintLT);
        parsingTable.insert("i>", aintGT);
        parsingTable.insert("i<=", aintLE);
        parsingTable.insert("i>=", aintGE);

        parsingTable.insert("f+", afloatPlus);
        parsingTable.insert("f-", afloatMinus);
        parsingTable.insert("f*", afloatProduct);
        parsingTable.insert("f/", afloatDivision);
        parsingTable.insert("f?", afloatp);
        parsingTable.insert("f=", afloatEql);
        parsingTable.insert("f!=", afloatNE);
        parsingTable.insert("f<", afloatLT);
        parsingTable.insert("f>", afloatGT);
        parsingTable.insert("f<=", afloatLE);
        parsingTable.insert("f>=", afloatGE);

        parsingTable.insert("f2i", afloat2int);
        parsingTable.insert("i2f", aint2float);
    }

public:
    FastParser()
        : s(""), nosymbol("(){}[].\""), a(Ob::anil)
    {
        a = new Context(Ob::abot, Ob::abot, a);

        a = new Context(acar, BaseFunc::fcar, a);
        a = new Context(acdr, BaseFunc::fcdr, a);
        a = new Context(acons, BaseFunc::fcons, a);
        a = new Context(aatom, BaseFunc::fatom, a);
        a = new Context(aeq, BaseFunc::feq, a);

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

    Ob::Ptr parse(string _s)
    {
        s = _s;
        parseRes pr = parseExpression(s.begin());
        return pr.success ? pr.e : Ob::abot;
    }

    Ob::Ptr parseEval(string _s)
    {
        return parse(_s)->eval(a);
    }

    string evalToString(string _s)
    {
        return print(parse(_s)->eval(a));
    }

    string print(const Ob::Ptr & p)
    {
        string res;
        QTextStream ts(&res, QIODevice::WriteOnly);
        printOb(ts, p);
        return res;
    }
private:

    QTextStream & printOb(QTextStream & ts, const Ob::Ptr & p)
    {
        //cout << "printOb";
        Symbol * sym = p->asSymbol();
        if(sym != 0)
            return printSymbol(ts, sym);
        Pair * pr = p->asPair();
        if(pr != 0)
        {
            ts << "(";
            return printList(ts, pr);
        }
        if(p->isFunction())
        {
            Function * f = p->asFunction();
            if(f->isOperation())
                ts << "{operation}";
            else
                ts << "{closure}";
        }
        else if(p->isLazy())
            ts << "{lazy}";
        else if(p->isLabel())
            ts << "{label}";
        else if(p->isSpecType())
        {
            SpecType * spt = p->asSpecType();
            if(spt->hasType(SpecTypeTemp<int>::type_id))
                ts << spt->cast<SpecTypeTemp<int> >()->getValue();
            else if(spt->hasType(SpecTypeTemp<float>::type_id))
                ts << spt->cast<SpecTypeTemp<float> >()->getValue();
            else
                ts << "{SpecType}";
        }
        return ts;
    }

    QTextStream & printSymbol(QTextStream & ts, Symbol * sym)
    {
        //cout << "printSymbol";
        if(sym == Ob::anil->asSymbol())
        {
            //cout << "print: ()";
            ts << "()";
        }
        else
        {
            for(map<string, Ob::Ptr>::iterator it = parsingTable.begin(); it != parsingTable.end(); ++it)
            {
                if(it.value() == sym)
                {
                    //cout << "print symbol:" << it.key();
                    ts << it.key();
                    break;
                }
            }
        }
        return ts;
    }

    QTextStream & printList(QTextStream & ts, Pair * pr)
    {
        //cout << "printList";
        printOb(ts, pr->car());
        Ob::Ptr pcdr = pr->cdr();
        Symbol * sym = pcdr->asSymbol();
        if(sym != 0)
        {
            if(sym != Ob::anil->asSymbol())
            {
                //cout << "print .";
                ts << " . ";
                printOb(ts, pcdr);
            }
            ts << ")";
        }
        else
        {
            ts << " ";
            printList(ts, pcdr->asPair());
        }
        return ts;
    }


    struct parseRes
    {
        Ob::Ptr e;
        string::const_iterator rest;
        bool success;

        parseRes(const Ob::Ptr & _e, string::const_iterator _rest, bool _success)
            :e(_e), rest(_rest), success(_success) {}
    };

    struct lexRes
    {
        string::const_iterator rest;
        bool success;

        lexRes(string::const_iterator _rest, bool _success)
            : rest(_rest), success(_success) {}
    };

    parseRes parseExpression(string::const_iterator si)
    {
        //cout << "parseExpression";
        lexRes lr = spaces(si);
        lr = lexem("(", lr.rest);
        if(lr.success)
        {
            return parseTail(lr.rest);
        }
        else
            return parseAtom(lr.rest);
    }

    parseRes parseTail(string::const_iterator si)
    {
        //cout << "parseTail";
        lexRes lr = spaces(si);
        lr = lexem(")", lr.rest);
        if(lr.success)
        {
            //cout << "ret nil";
            return parseRes(Ob::anil, lr.rest, true);
        }
        lr = lexem(".", lr.rest);
        if(lr.success)
        {
            lr = spaces(lr.rest);
            parseRes pr = parseExpression(lr.rest);
            if(!pr.success)
            {
                cout << "parseTail fail";
                return parseRes(Ob::anil, si, false);
            }
            lr = spaces(pr.rest);
            lr = lexem(")", lr.rest);
            if(lr.success)
            {
                //cout << "ret tail: " << print(pr.e);
                return parseRes(pr.e, lr.rest, true);
            }
            else
            {
                cout << "fail ) expected";
                parseRes(Ob::anil, si, false);
            }
        }
        parseRes pr1 = parseExpression(lr.rest);
        if(!pr1.success)
        {
            cout << "parseTail fail";
            return parseRes(Ob::anil, si, false);
        }
        parseRes pr2 = parseTail(pr1.rest);
        if(!pr2.success)
        {
            cout << "parseTail fail";
            return parseRes(Ob::anil, si, false);
        }
        Ob::Ptr e = new Pair(pr1.e, pr2.e);
        //cout << "ret pair: " << print(e);
        return parseRes(e, pr2.rest, true);
    }

    parseRes parseAtom(string::const_iterator si)
    {
        //cout << "parseAtom";
        parseRes pr = parseNumber(si);
        if(pr.success)
            return pr;
        pr = parseSymbol(si);
        return pr.success ? pr : parseRes(Ob::anil, si, false);
    }

    parseRes parseSymbol(string::const_iterator si)
    {
        string symbol("");
        string::const_iterator sii = si;
        if(sii == s.end() || sii->isSpace() || nosymbol.contains(*sii))
        {
            cout << "symbol fail first char" << *sii;
            return parseRes(Ob::anil, si, false);
        }
        symbol.push_back(*sii);
        ++sii;
        while(sii != s.end() && !sii->isSpace() && !nosymbol.contains(*sii))
        {
            symbol.push_back(*sii);
            ++sii;
        }
        Ob::Ptr e(Ob::anil);
        if(parsingTable.contains(symbol))
        {
            //cout << "already existing symbol: " << symbol;
            e = parsingTable[symbol];
        }
        else
        {
            Symbol * sym = new Symbol();
            parsingTable.insert(symbol, sym);
            //cout << "new symbol: " << symbol;
            e = sym;
        }
        //cout << "ret atom: " << print(e);
        return parseRes(e, sii, true);
    }

    parseRes parseNumber(string::const_iterator si)
    {
        string number("");
        string::const_iterator sii = si;
        if(sii == s.end() || !sii->isDigit() && *sii != '-' || sii->isSpace() || nosymbol.contains(*sii))
        {
            //cout << "number fail first char" << *sii;
            return parseRes(Ob::anil, si, false);
        }
        number.push_back(*sii);
        ++sii;
        while(sii != s.end() && sii->isDigit() && !sii->isSpace() && !nosymbol.contains(*sii))
        {
            number.push_back(*sii);
            ++sii;
        }
        if(sii == s.end() || *sii != '.')
        {
            bool b = false;
            int i = number.toInt(&b);
            if(b)
            {
                return parseRes(new SpecTypeTemp<int>(i), sii, true);
            }
        }
        else
        {
            number.push_back(*sii);
            ++sii;
            while(sii != s.end() && sii->isDigit() && !sii->isSpace() && !nosymbol.contains(*sii))
            {
                number.push_back(*sii);
                ++sii;
            }
            bool b = false;
            float f = number.toFloat(&b);
            if(b)
            {
                return parseRes(new SpecTypeTemp<float>(f), sii, true);
            }
        }
        return parseRes(Ob::anil, si, false);
    }

    lexRes lexem(string lex, string::const_iterator si)
    {
        string::const_iterator sii = si;
        foreach(QChar c, lex)
        {
            if(sii == s.end() || *sii != c)
            {
                //cout << "lexem fail: " << lex;
                return lexRes(si, false);
            }
            ++sii;
        }
        //cout << "lexem: " << lex;
        return lexRes(sii, true);
    }

    lexRes spaces(string::const_iterator si)
    {
        while(si != s.end() && si->isSpace())
            ++si;
        //cout << "spaces";
        return lexRes(si, true);
    }
};

#endif // FASTPARSER_H
