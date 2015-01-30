#pragma once

#include "basesymbols.h"
#include "bytearray.h"

class BaseSymbolTable {
    BaseSymbolTable(){}

    static void addInSymbols(Ob::Ptr & symbols, const string & s, const Ob::Ptr & p) {
        symbols = new Pair(new Pair(p, ByteArray::fromChars(s.size(), s.data())), symbols);
    }

public:
    static Ob::Ptr createSymbolTable() {
        Ob::Ptr symbols;
        addInSymbols(symbols, "-i", BaseNumFuncSymbols::inst().aintNeg);
        addInSymbols(symbols, "i+", BaseNumFuncSymbols::inst().aintPlus);
        addInSymbols(symbols, "i-", BaseNumFuncSymbols::inst().aintMinus);
        addInSymbols(symbols, "i*", BaseNumFuncSymbols::inst().aintProduct);
        addInSymbols(symbols, "i/", BaseNumFuncSymbols::inst().aintDivision);
        addInSymbols(symbols, "i%", BaseNumFuncSymbols::inst().aintMod);
        addInSymbols(symbols, "i?", BaseNumFuncSymbols::inst().aintp);
        addInSymbols(symbols, "i-not", BaseNumFuncSymbols::inst().aintnot);
        addInSymbols(symbols, "i-and", BaseNumFuncSymbols::inst().aintand);
        addInSymbols(symbols, "i-or", BaseNumFuncSymbols::inst().aintor);
        addInSymbols(symbols, "i-xor", BaseNumFuncSymbols::inst().aintxor);
        addInSymbols(symbols, "i-shl", BaseNumFuncSymbols::inst().aintshl);
        addInSymbols(symbols, "i-shr", BaseNumFuncSymbols::inst().aintshr);
        addInSymbols(symbols, "i=", BaseNumFuncSymbols::inst().aintEql);
        addInSymbols(symbols, "i!=", BaseNumFuncSymbols::inst().aintNE);
        addInSymbols(symbols, "i<", BaseNumFuncSymbols::inst().aintLT);
        addInSymbols(symbols, "i>", BaseNumFuncSymbols::inst().aintGT);
        addInSymbols(symbols, "i<=", BaseNumFuncSymbols::inst().aintLE);
        addInSymbols(symbols, "i>=", BaseNumFuncSymbols::inst().aintGE);

        addInSymbols(symbols, "u?", BaseNumFuncSymbols::inst().alongp);
        addInSymbols(symbols, "u-not", BaseNumFuncSymbols::inst().alongnot);
        addInSymbols(symbols, "u-and", BaseNumFuncSymbols::inst().alongand);
        addInSymbols(symbols, "u-or", BaseNumFuncSymbols::inst().alongor);
        addInSymbols(symbols, "u-xor", BaseNumFuncSymbols::inst().alongxor);
        addInSymbols(symbols, "u-shl", BaseNumFuncSymbols::inst().alongshl);
        addInSymbols(symbols, "u-shr", BaseNumFuncSymbols::inst().alongshr);

        addInSymbols(symbols, "u=", BaseNumFuncSymbols::inst().alongEql);
        addInSymbols(symbols, "u!=", BaseNumFuncSymbols::inst().alongNE);
        addInSymbols(symbols, "u<", BaseNumFuncSymbols::inst().alongLT);
        addInSymbols(symbols, "u>", BaseNumFuncSymbols::inst().alongGT);
        addInSymbols(symbols, "u<=", BaseNumFuncSymbols::inst().alongLE);
        addInSymbols(symbols, "u>=", BaseNumFuncSymbols::inst().alongGE);

        addInSymbols(symbols, "c?", BaseNumFuncSymbols::inst().acharp);
        addInSymbols(symbols, "c-not", BaseNumFuncSymbols::inst().acharnot);
        addInSymbols(symbols, "c-and", BaseNumFuncSymbols::inst().acharand);
        addInSymbols(symbols, "c-or", BaseNumFuncSymbols::inst().acharor);
        addInSymbols(symbols, "c-xor", BaseNumFuncSymbols::inst().acharxor);
        addInSymbols(symbols, "c-shl", BaseNumFuncSymbols::inst().acharshl);
        addInSymbols(symbols, "c-shr", BaseNumFuncSymbols::inst().acharshr);
        addInSymbols(symbols, "c=", BaseNumFuncSymbols::inst().acharEql);
        addInSymbols(symbols, "c!=", BaseNumFuncSymbols::inst().acharNE);
        addInSymbols(symbols, "c<", BaseNumFuncSymbols::inst().acharLT);
        addInSymbols(symbols, "c>", BaseNumFuncSymbols::inst().acharGT);
        addInSymbols(symbols, "c<=", BaseNumFuncSymbols::inst().acharLE);
        addInSymbols(symbols, "c>=", BaseNumFuncSymbols::inst().acharGE);

        addInSymbols(symbols, "-f", BaseNumFuncSymbols::inst().afloatNeg);
        addInSymbols(symbols, "f+", BaseNumFuncSymbols::inst().afloatPlus);
        addInSymbols(symbols, "f-", BaseNumFuncSymbols::inst().afloatMinus);
        addInSymbols(symbols, "f*", BaseNumFuncSymbols::inst().afloatProduct);
        addInSymbols(symbols, "f/", BaseNumFuncSymbols::inst().afloatDivision);
        addInSymbols(symbols, "f?", BaseNumFuncSymbols::inst().afloatp);
        addInSymbols(symbols, "f=", BaseNumFuncSymbols::inst().afloatEql);
        addInSymbols(symbols, "f!=", BaseNumFuncSymbols::inst().afloatNE);
        addInSymbols(symbols, "f<", BaseNumFuncSymbols::inst().afloatLT);
        addInSymbols(symbols, "f>", BaseNumFuncSymbols::inst().afloatGT);
        addInSymbols(symbols, "f<=", BaseNumFuncSymbols::inst().afloatLE);
        addInSymbols(symbols, "f>=", BaseNumFuncSymbols::inst().afloatGE);

        addInSymbols(symbols, "u2i", BaseNumFuncSymbols::inst().along2int);
        addInSymbols(symbols, "i2u", BaseNumFuncSymbols::inst().aint2long);
        addInSymbols(symbols, "f2i", BaseNumFuncSymbols::inst().afloat2int);
        addInSymbols(symbols, "i2f", BaseNumFuncSymbols::inst().aint2float);
        addInSymbols(symbols, "c2i", BaseNumFuncSymbols::inst().achar2int);
        addInSymbols(symbols, "i2c", BaseNumFuncSymbols::inst().aint2char);
        addInSymbols(symbols, "c2u", BaseNumFuncSymbols::inst().achar2long);
        addInSymbols(symbols, "u2c", BaseNumFuncSymbols::inst().along2char);

        addInSymbols(symbols, "sz-i", BaseNumFuncSymbols::inst().aszi);
        addInSymbols(symbols, "sz-f", BaseNumFuncSymbols::inst().aszf);
        addInSymbols(symbols, "sz-c", BaseNumFuncSymbols::inst().aszc);
        addInSymbols(symbols, "sz-u", BaseNumFuncSymbols::inst().aszu);

        addInSymbols(symbols, "vec?", VectorFuncSymbols::inst().avecp);
        addInSymbols(symbols, "mkvec", VectorFuncSymbols::inst().amkvec);
        addInSymbols(symbols, "vec-clone", VectorFuncSymbols::inst().avecclone);
        addInSymbols(symbols, "vec-len", VectorFuncSymbols::inst().aveclen);
        addInSymbols(symbols, "vec-mid", VectorFuncSymbols::inst().avecmid);
        addInSymbols(symbols, "vec-slice", VectorFuncSymbols::inst().avecslice);
        addInSymbols(symbols, "vec-el", VectorFuncSymbols::inst().avecel);
        addInSymbols(symbols, "vec-cat", VectorFuncSymbols::inst().aveccat);

        addInSymbols(symbols, "input?", IOFuncSymbols::inst().ainputp);
        addInSymbols(symbols, "output?", IOFuncSymbols::inst().aoutputp);
        addInSymbols(symbols, "open-in", IOFuncSymbols::inst().aopenin);
        addInSymbols(symbols, "open-out", IOFuncSymbols::inst().aopenout);
        addInSymbols(symbols, "read", IOFuncSymbols::inst().aread);
        addInSymbols(symbols, "write", IOFuncSymbols::inst().awrite);
        addInSymbols(symbols, "stdin", IOFuncSymbols::inst().astdin);
        addInSymbols(symbols, "stdout", IOFuncSymbols::inst().astdout);
        addInSymbols(symbols, "stderr", IOFuncSymbols::inst().astderr);

        addInSymbols(symbols, "b?", ByteArrayFuncSymbols::inst().abarrayp);
        addInSymbols(symbols, "b-len", ByteArrayFuncSymbols::inst().abarraylen);
        addInSymbols(symbols, "b-clone", ByteArrayFuncSymbols::inst().abarrayclone);
        addInSymbols(symbols, "b-cmp", ByteArrayFuncSymbols::inst().abarraycmp);
        addInSymbols(symbols, "b-ncmp", ByteArrayFuncSymbols::inst().abarrayncmp);
        addInSymbols(symbols, "b-findch", ByteArrayFuncSymbols::inst().abarrayfindch);
        addInSymbols(symbols, "b-find", ByteArrayFuncSymbols::inst().abarrayfind);
        addInSymbols(symbols, "b-cat", ByteArrayFuncSymbols::inst().abarraycat);
        addInSymbols(symbols, "b-mid", ByteArrayFuncSymbols::inst().abarraymid);
        addInSymbols(symbols, "b-slice", ByteArrayFuncSymbols::inst().abarrayslice);
        addInSymbols(symbols, "i2b", ByteArrayFuncSymbols::inst().aserint);
        addInSymbols(symbols, "f2b", ByteArrayFuncSymbols::inst().aserfloat);
        addInSymbols(symbols, "c2b", ByteArrayFuncSymbols::inst().aserchar);
        addInSymbols(symbols, "b-geti", ByteArrayFuncSymbols::inst().agetint);
        addInSymbols(symbols, "b-getf", ByteArrayFuncSymbols::inst().agetfloat);
        addInSymbols(symbols, "b-getc", ByteArrayFuncSymbols::inst().agetchar);

        addInSymbols(symbols, "pair?", BaseTypePredSymbols::inst().apairp);
        addInSymbols(symbols, "lazy?", BaseTypePredSymbols::inst().alazyp);
        addInSymbols(symbols, "label?", BaseTypePredSymbols::inst().alabelp);
        addInSymbols(symbols, "atom?", BaseTypePredSymbols::inst().aatomp);
        addInSymbols(symbols, "symbol?", BaseTypePredSymbols::inst().asymbolp);
        addInSymbols(symbols, "const?", BaseTypePredSymbols::inst().aconstp);
        addInSymbols(symbols, "macro?", BaseTypePredSymbols::inst().amacrop);
        addInSymbols(symbols, "basemacro?", BaseTypePredSymbols::inst().abasemacrop);
        addInSymbols(symbols, "usermacro?", BaseTypePredSymbols::inst().ausermacrop);
        addInSymbols(symbols, "spectype?", BaseTypePredSymbols::inst().avaluep);

        addInSymbols(symbols, "ctx-get", BaseFuncSymbols::inst().actxget);
        addInSymbols(symbols, "ctx-push", BaseFuncSymbols::inst().actxpush);
        addInSymbols(symbols, "empty-ctx", Evaluator::eempty);
        addInSymbols(symbols, "get-type", BaseFuncSymbols::inst().agettype);
        addInSymbols(symbols, "cons", BaseFuncSymbols::inst().acons);
        addInSymbols(symbols, "car", BaseFuncSymbols::inst().acar);
        addInSymbols(symbols, "cdr", BaseFuncSymbols::inst().acdr);
        addInSymbols(symbols, "eq", BaseFuncSymbols::inst().aeq);

        addInSymbols(symbols, "t", Ob::at);

        addInSymbols(symbols, "^", BaseMacroSymbols::inst().agensym);
        addInSymbols(symbols, "~", BaseMacroSymbols::inst().acurctx);
        addInSymbols(symbols, "_", BaseMacroSymbols::inst().abot);
        addInSymbols(symbols, "|", BaseMacroSymbols::inst().atry);
        addInSymbols(symbols, "$", BaseMacroSymbols::inst().aunlazy);
        addInSymbols(symbols, "#", BaseMacroSymbols::inst().alazy);
        addInSymbols(symbols, "%", BaseMacroSymbols::inst().amacro);
        addInSymbols(symbols, "`", BaseMacroSymbols::inst().aapply);
        addInSymbols(symbols, "@", BaseMacroSymbols::inst().alabel);
        addInSymbols(symbols, "?", BaseMacroSymbols::inst().aif);
        addInSymbols(symbols, "\\", BaseMacroSymbols::inst().alambda);
        addInSymbols(symbols, ">-", BaseMacroSymbols::inst().alet);
        addInSymbols(symbols, "'", BaseMacroSymbols::inst().aquote);
        return symbols;
    }
};
