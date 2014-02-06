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
    static const Ob::Ptr aintnot;
    static const Ob::Ptr aintand;
    static const Ob::Ptr aintor;
    static const Ob::Ptr aintxor;
    static const Ob::Ptr aintshl;
    static const Ob::Ptr aintshr;
    static const Ob::Ptr aintEql;
    static const Ob::Ptr aintNE;
    static const Ob::Ptr aintGT;
    static const Ob::Ptr aintLT;
    static const Ob::Ptr aintGE;
    static const Ob::Ptr aintLE;

    static const Ob::Ptr alongp;
    static const Ob::Ptr alongnot;
    static const Ob::Ptr alongand;
    static const Ob::Ptr alongor;
    static const Ob::Ptr alongxor;
    static const Ob::Ptr alongshl;
    static const Ob::Ptr alongshr;

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

    static const Ob::Ptr along2int;
    static const Ob::Ptr aint2long;

    static const Ob::Ptr afloat2int;
    static const Ob::Ptr aint2float;

    static const Ob::Ptr avecp;
    static const Ob::Ptr amkvec;
    static const Ob::Ptr aveclen;
    static const Ob::Ptr avecmid;
    static const Ob::Ptr avecel;
    static const Ob::Ptr aveccat;

    static const Ob::Ptr abytesp;
    static const Ob::Ptr abyteslen;
    static const Ob::Ptr abytescat;
    static const Ob::Ptr abytesmid;
    static const Ob::Ptr aserint;
    static const Ob::Ptr aserfloat;
    static const Ob::Ptr aserbyte;
    static const Ob::Ptr aser2bytes;
    static const Ob::Ptr aser4bytes;
    static const Ob::Ptr aser8bytes;
    static const Ob::Ptr agetint;
    static const Ob::Ptr agetfloat;
    static const Ob::Ptr agetbyte;
    static const Ob::Ptr aget2bytes;
    static const Ob::Ptr aget4bytes;
    static const Ob::Ptr aget8bytes;

    static const Ob::Ptr asizeofi;
    static const Ob::Ptr asizeoff;
    static const Ob::Ptr asizeofu;

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
        symbolTable.insert(pair<string, Ob::Ptr>("inot", aintnot));
        symbolTable.insert(pair<string, Ob::Ptr>("iand", aintand));
        symbolTable.insert(pair<string, Ob::Ptr>("ior", aintor));
        symbolTable.insert(pair<string, Ob::Ptr>("ixor", aintxor));
        symbolTable.insert(pair<string, Ob::Ptr>("ishl", aintshl));
        symbolTable.insert(pair<string, Ob::Ptr>("ishr", aintshr));
        symbolTable.insert(pair<string, Ob::Ptr>("i=", aintEql));
        symbolTable.insert(pair<string, Ob::Ptr>("i!=", aintNE));
        symbolTable.insert(pair<string, Ob::Ptr>("i<", aintLT));
        symbolTable.insert(pair<string, Ob::Ptr>("i>", aintGT));
        symbolTable.insert(pair<string, Ob::Ptr>("i<=", aintLE));
        symbolTable.insert(pair<string, Ob::Ptr>("i>=", aintGE));

        symbolTable.insert(pair<string, Ob::Ptr>("u?", alongp));
        symbolTable.insert(pair<string, Ob::Ptr>("unot", alongnot));
        symbolTable.insert(pair<string, Ob::Ptr>("uand", alongand));
        symbolTable.insert(pair<string, Ob::Ptr>("uor", alongor));
        symbolTable.insert(pair<string, Ob::Ptr>("uxor", alongxor));
        symbolTable.insert(pair<string, Ob::Ptr>("ushl", alongshl));
        symbolTable.insert(pair<string, Ob::Ptr>("ushr", alongshr));

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
        symbolTable.insert(pair<string, Ob::Ptr>("vec-mid", avecmid));
        symbolTable.insert(pair<string, Ob::Ptr>("vec-el", avecel));
        symbolTable.insert(pair<string, Ob::Ptr>("vec-cat", aveccat));

        symbolTable.insert(pair<string, Ob::Ptr>("b?", abytesp));
        symbolTable.insert(pair<string, Ob::Ptr>("b-len", abyteslen));
        symbolTable.insert(pair<string, Ob::Ptr>("b-cat", abytescat));
        symbolTable.insert(pair<string, Ob::Ptr>("b-mid", abytesmid));
        symbolTable.insert(pair<string, Ob::Ptr>("i2b", aserint));
        symbolTable.insert(pair<string, Ob::Ptr>("f2b", aserfloat));
        symbolTable.insert(pair<string, Ob::Ptr>("u1-2b", aserbyte));
        symbolTable.insert(pair<string, Ob::Ptr>("u2-2b", aser2bytes));
        symbolTable.insert(pair<string, Ob::Ptr>("u4-2b", aser4bytes));
        symbolTable.insert(pair<string, Ob::Ptr>("u8-2b", aser8bytes));
        symbolTable.insert(pair<string, Ob::Ptr>("b-geti", agetint));
        symbolTable.insert(pair<string, Ob::Ptr>("b-getf", agetfloat));
        symbolTable.insert(pair<string, Ob::Ptr>("b-getu1", agetbyte));
        symbolTable.insert(pair<string, Ob::Ptr>("b-getu2", aget2bytes));
        symbolTable.insert(pair<string, Ob::Ptr>("b-getu4", aget4bytes));
        symbolTable.insert(pair<string, Ob::Ptr>("b-getu8", aget8bytes));

        symbolTable.insert(pair<string, Ob::Ptr>("size-of-i", asizeofi));
        symbolTable.insert(pair<string, Ob::Ptr>("size-of-f", asizeoff));
        symbolTable.insert(pair<string, Ob::Ptr>("size-of-u", asizeofu));
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

        a = new Context(asizeofi, new SpecTypeTemp<int>(sizeof(int)), a);
        a = new Context(asizeoff, new SpecTypeTemp<int>(sizeof(float)), a);
        a = new Context(asizeofu, new SpecTypeTemp<int>(sizeof(long long)), a);

        a = new Context(aintNeg, BaseNumFunc::fintNeg, a);
        a = new Context(aintPlus, BaseNumFunc::fintPlus, a);
        a = new Context(aintMinus, BaseNumFunc::fintMinus, a);
        a = new Context(aintProduct, BaseNumFunc::fintProduct, a);
        a = new Context(aintDivision, BaseNumFunc::fintDivision, a);
        a = new Context(aintMod, BaseNumFunc::fintMod, a);
        a = new Context(aintp, BaseNumFunc::fintp, a);
        a = new Context(aintnot, BaseNumFunc::fintnot, a);
        a = new Context(aintand, BaseNumFunc::fintand, a);
        a = new Context(aintor, BaseNumFunc::fintor, a);
        a = new Context(aintxor, BaseNumFunc::fintxor, a);
        a = new Context(aintshl, BaseNumFunc::fintshl, a);
        a = new Context(aintshr, BaseNumFunc::fintshr, a);
        a = new Context(aintEql, BaseNumFunc::fintEql, a);
        a = new Context(aintNE, BaseNumFunc::fintNE, a);
        a = new Context(aintLT, BaseNumFunc::fintLT, a);
        a = new Context(aintGT, BaseNumFunc::fintGT, a);
        a = new Context(aintLE, BaseNumFunc::fintLE, a);
        a = new Context(aintGE, BaseNumFunc::fintGE, a);

        a = new Context(alongp, BaseNumFunc::flongp, a);
        a = new Context(alongnot, BaseNumFunc::flongnot, a);
        a = new Context(alongand, BaseNumFunc::flongand, a);
        a = new Context(alongor, BaseNumFunc::flongor, a);
        a = new Context(alongxor, BaseNumFunc::flongxor, a);
        a = new Context(alongshl, BaseNumFunc::flongshl, a);
        a = new Context(alongshr, BaseNumFunc::flongshr, a);

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
        a = new Context(avecmid, VectorFunctions::fvecmid, a);
        a = new Context(aveclen, VectorFunctions::fveclen, a);
        a = new Context(aveccat, VectorFunctions::fveccat, a);

        a = new Context(abytesp, ByteArrayFunctions::fbytesp, a);
        a = new Context(abyteslen, ByteArrayFunctions::fbyteslen, a);
        a = new Context(abytescat, ByteArrayFunctions::fbytescat, a);
        a = new Context(abytesmid, ByteArrayFunctions::fbytesmid, a);
        a = new Context(aserint, ByteArrayFunctions::fserint, a);
        a = new Context(aserfloat, ByteArrayFunctions::fserfloat, a);
        a = new Context(aserbyte, ByteArrayFunctions::fserbyte, a);
        a = new Context(aser2bytes, ByteArrayFunctions::fser2bytes, a);
        a = new Context(aser4bytes, ByteArrayFunctions::fser4bytes, a);
        a = new Context(aser8bytes, ByteArrayFunctions::fser8bytes, a);
        a = new Context(agetint, ByteArrayFunctions::fgetint, a);
        a = new Context(agetfloat, ByteArrayFunctions::fgetfloat, a);
        a = new Context(agetbyte, ByteArrayFunctions::fgetbyte, a);
        a = new Context(aget2bytes, ByteArrayFunctions::fget2bytes, a);
        a = new Context(aget4bytes, ByteArrayFunctions::fget4bytes, a);
        a = new Context(aget8bytes, ByteArrayFunctions::fget8bytes, a);

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
        pr = parseSymbol(si);
        return pr.success ? pr : parseRes(Ob::anil, si, false);
    }

    parseRes parseString(string::const_iterator si) {
        if(si == s.end() || *si != '\"')
            return parseRes(Ob::anil, si, false);
        string::const_iterator sii = si;
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

    parseRes parseNumber(string::const_iterator si) {
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
                return parseRes(new SpecTypeTemp<float>(f), sii, true);
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
