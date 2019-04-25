#include <init/initsymbols.h>

#include <impl/symbols/basesymbols.h>
#include <impl/core/bytearray.h>

namespace stepone::init {

using namespace symbols;

static inline void addSymbol(Ptr & symbolTable, const std::string & s, const Ptr & p) {
    symbolTable = new core::Pair(new core::Pair(p, core::ByteArray::fromChars(s.size(), s.data())), symbolTable);
}

Ptr BaseSymbolTable::createSymbolTable() {
    Ptr symbolTable(Ptr::anil);
    addSymbol(symbolTable, "-i", BaseNumFuncSymbols::inst().aintNeg);
    addSymbol(symbolTable, "i+", BaseNumFuncSymbols::inst().aintPlus);
    addSymbol(symbolTable, "i-", BaseNumFuncSymbols::inst().aintMinus);
    addSymbol(symbolTable, "i*", BaseNumFuncSymbols::inst().aintProduct);
    addSymbol(symbolTable, "i/", BaseNumFuncSymbols::inst().aintDivision);
    addSymbol(symbolTable, "i%", BaseNumFuncSymbols::inst().aintMod);
    addSymbol(symbolTable, "i?", BaseNumFuncSymbols::inst().aintp);
    addSymbol(symbolTable, "i-not", BaseNumFuncSymbols::inst().aintnot);
    addSymbol(symbolTable, "i-and", BaseNumFuncSymbols::inst().aintand);
    addSymbol(symbolTable, "i-or", BaseNumFuncSymbols::inst().aintor);
    addSymbol(symbolTable, "i-xor", BaseNumFuncSymbols::inst().aintxor);
    addSymbol(symbolTable, "i-shl", BaseNumFuncSymbols::inst().aintshl);
    addSymbol(symbolTable, "i-shr", BaseNumFuncSymbols::inst().aintshr);
    addSymbol(symbolTable, "i=", BaseNumFuncSymbols::inst().aintEql);
    addSymbol(symbolTable, "i!=", BaseNumFuncSymbols::inst().aintNE);
    addSymbol(symbolTable, "i<", BaseNumFuncSymbols::inst().aintLT);
    addSymbol(symbolTable, "i>", BaseNumFuncSymbols::inst().aintGT);
    addSymbol(symbolTable, "i<=", BaseNumFuncSymbols::inst().aintLE);
    addSymbol(symbolTable, "i>=", BaseNumFuncSymbols::inst().aintGE);

    addSymbol(symbolTable, "u?", BaseNumFuncSymbols::inst().alongp);
    addSymbol(symbolTable, "u-not", BaseNumFuncSymbols::inst().alongnot);
    addSymbol(symbolTable, "u-and", BaseNumFuncSymbols::inst().alongand);
    addSymbol(symbolTable, "u-or", BaseNumFuncSymbols::inst().alongor);
    addSymbol(symbolTable, "u-xor", BaseNumFuncSymbols::inst().alongxor);
    addSymbol(symbolTable, "u-shl", BaseNumFuncSymbols::inst().alongshl);
    addSymbol(symbolTable, "u-shr", BaseNumFuncSymbols::inst().alongshr);

    addSymbol(symbolTable, "u=", BaseNumFuncSymbols::inst().alongEql);
    addSymbol(symbolTable, "u!=", BaseNumFuncSymbols::inst().alongNE);
    addSymbol(symbolTable, "u<", BaseNumFuncSymbols::inst().alongLT);
    addSymbol(symbolTable, "u>", BaseNumFuncSymbols::inst().alongGT);
    addSymbol(symbolTable, "u<=", BaseNumFuncSymbols::inst().alongLE);
    addSymbol(symbolTable, "u>=", BaseNumFuncSymbols::inst().alongGE);

    addSymbol(symbolTable, "c?", BaseNumFuncSymbols::inst().acharp);
    addSymbol(symbolTable, "c-not", BaseNumFuncSymbols::inst().acharnot);
    addSymbol(symbolTable, "c-and", BaseNumFuncSymbols::inst().acharand);
    addSymbol(symbolTable, "c-or", BaseNumFuncSymbols::inst().acharor);
    addSymbol(symbolTable, "c-xor", BaseNumFuncSymbols::inst().acharxor);
    addSymbol(symbolTable, "c-shl", BaseNumFuncSymbols::inst().acharshl);
    addSymbol(symbolTable, "c-shr", BaseNumFuncSymbols::inst().acharshr);
    addSymbol(symbolTable, "c=", BaseNumFuncSymbols::inst().acharEql);
    addSymbol(symbolTable, "c!=", BaseNumFuncSymbols::inst().acharNE);
    addSymbol(symbolTable, "c<", BaseNumFuncSymbols::inst().acharLT);
    addSymbol(symbolTable, "c>", BaseNumFuncSymbols::inst().acharGT);
    addSymbol(symbolTable, "c<=", BaseNumFuncSymbols::inst().acharLE);
    addSymbol(symbolTable, "c>=", BaseNumFuncSymbols::inst().acharGE);

    addSymbol(symbolTable, "-f", BaseNumFuncSymbols::inst().afloatNeg);
    addSymbol(symbolTable, "f+", BaseNumFuncSymbols::inst().afloatPlus);
    addSymbol(symbolTable, "f-", BaseNumFuncSymbols::inst().afloatMinus);
    addSymbol(symbolTable, "f*", BaseNumFuncSymbols::inst().afloatProduct);
    addSymbol(symbolTable, "f/", BaseNumFuncSymbols::inst().afloatDivision);
    addSymbol(symbolTable, "f?", BaseNumFuncSymbols::inst().afloatp);
    addSymbol(symbolTable, "f=", BaseNumFuncSymbols::inst().afloatEql);
    addSymbol(symbolTable, "f!=", BaseNumFuncSymbols::inst().afloatNE);
    addSymbol(symbolTable, "f<", BaseNumFuncSymbols::inst().afloatLT);
    addSymbol(symbolTable, "f>", BaseNumFuncSymbols::inst().afloatGT);
    addSymbol(symbolTable, "f<=", BaseNumFuncSymbols::inst().afloatLE);
    addSymbol(symbolTable, "f>=", BaseNumFuncSymbols::inst().afloatGE);

    addSymbol(symbolTable, "u2i", BaseNumFuncSymbols::inst().along2int);
    addSymbol(symbolTable, "i2u", BaseNumFuncSymbols::inst().aint2long);
    addSymbol(symbolTable, "f2i", BaseNumFuncSymbols::inst().afloat2int);
    addSymbol(symbolTable, "i2f", BaseNumFuncSymbols::inst().aint2float);
    addSymbol(symbolTable, "c2i", BaseNumFuncSymbols::inst().achar2int);
    addSymbol(symbolTable, "i2c", BaseNumFuncSymbols::inst().aint2char);
    addSymbol(symbolTable, "c2u", BaseNumFuncSymbols::inst().achar2long);
    addSymbol(symbolTable, "u2c", BaseNumFuncSymbols::inst().along2char);

    addSymbol(symbolTable, "sz-i", BaseNumFuncSymbols::inst().aszi);
    addSymbol(symbolTable, "sz-f", BaseNumFuncSymbols::inst().aszf);
    addSymbol(symbolTable, "sz-c", BaseNumFuncSymbols::inst().aszc);
    addSymbol(symbolTable, "sz-u", BaseNumFuncSymbols::inst().aszu);

    addSymbol(symbolTable, "vec?", VectorFuncSymbols::inst().avecp);
    addSymbol(symbolTable, "mkvec", VectorFuncSymbols::inst().amkvec);
    addSymbol(symbolTable, "vec-clone", VectorFuncSymbols::inst().avecclone);
    addSymbol(symbolTable, "vec-len", VectorFuncSymbols::inst().aveclen);
    addSymbol(symbolTable, "vec-mid", VectorFuncSymbols::inst().avecmid);
    addSymbol(symbolTable, "vec-slice", VectorFuncSymbols::inst().avecslice);
    addSymbol(symbolTable, "vec-el", VectorFuncSymbols::inst().avecel);
    addSymbol(symbolTable, "vec-cat", VectorFuncSymbols::inst().aveccat);

    addSymbol(symbolTable, "input?", IOFuncSymbols::inst().ainputp);
    addSymbol(symbolTable, "output?", IOFuncSymbols::inst().aoutputp);
    addSymbol(symbolTable, "open-in", IOFuncSymbols::inst().aopenin);
    addSymbol(symbolTable, "open-out", IOFuncSymbols::inst().aopenout);
    addSymbol(symbolTable, "read", IOFuncSymbols::inst().aread);
    addSymbol(symbolTable, "write", IOFuncSymbols::inst().awrite);
    addSymbol(symbolTable, "stdin", IOFuncSymbols::inst().astdin);
    addSymbol(symbolTable, "stdout", IOFuncSymbols::inst().astdout);
    addSymbol(symbolTable, "stderr", IOFuncSymbols::inst().astderr);

    addSymbol(symbolTable, "b?", ByteArrayFuncSymbols::inst().abarrayp);
    addSymbol(symbolTable, "b-len", ByteArrayFuncSymbols::inst().abarraylen);
    addSymbol(symbolTable, "b-clone", ByteArrayFuncSymbols::inst().abarrayclone);
    addSymbol(symbolTable, "b-cmp", ByteArrayFuncSymbols::inst().abarraycmp);
    addSymbol(symbolTable, "b-ncmp", ByteArrayFuncSymbols::inst().abarrayncmp);
    addSymbol(symbolTable, "b-findch", ByteArrayFuncSymbols::inst().abarrayfindch);
    addSymbol(symbolTable, "b-find", ByteArrayFuncSymbols::inst().abarrayfind);
    addSymbol(symbolTable, "b-cat", ByteArrayFuncSymbols::inst().abarraycat);
    addSymbol(symbolTable, "b-mid", ByteArrayFuncSymbols::inst().abarraymid);
    addSymbol(symbolTable, "b-slice", ByteArrayFuncSymbols::inst().abarrayslice);
    addSymbol(symbolTable, "i2b", ByteArrayFuncSymbols::inst().aserint);
    addSymbol(symbolTable, "f2b", ByteArrayFuncSymbols::inst().aserfloat);
    addSymbol(symbolTable, "c2b", ByteArrayFuncSymbols::inst().aserchar);
    addSymbol(symbolTable, "b-geti", ByteArrayFuncSymbols::inst().agetint);
    addSymbol(symbolTable, "b-getf", ByteArrayFuncSymbols::inst().agetfloat);
    addSymbol(symbolTable, "b-getc", ByteArrayFuncSymbols::inst().agetchar);

    addSymbol(symbolTable, "pair?", BaseTypePredSymbols::inst().apairp);
    addSymbol(symbolTable, "lazy?", BaseTypePredSymbols::inst().alazyp);
    addSymbol(symbolTable, "label?", BaseTypePredSymbols::inst().alabelp);
    addSymbol(symbolTable, "atom?", BaseTypePredSymbols::inst().aatomp);
    addSymbol(symbolTable, "symbol?", BaseTypePredSymbols::inst().asymbolp);
    addSymbol(symbolTable, "const?", BaseTypePredSymbols::inst().aconstp);
    addSymbol(symbolTable, "macro?", BaseTypePredSymbols::inst().amacrop);
    addSymbol(symbolTable, "basemacro?", BaseTypePredSymbols::inst().abasemacrop);
    addSymbol(symbolTable, "usermacro?", BaseTypePredSymbols::inst().ausermacrop);
    addSymbol(symbolTable, "spectype?", BaseTypePredSymbols::inst().avaluep);

    addSymbol(symbolTable, "ctx-get", BaseFuncSymbols::inst().actxget);
    addSymbol(symbolTable, "ctx-push", BaseFuncSymbols::inst().actxpush);
    addSymbol(symbolTable, "empty-ctx", BaseFuncSymbols::inst().aeempty);
    addSymbol(symbolTable, "get-type", BaseFuncSymbols::inst().agettype);
    addSymbol(symbolTable, "cons", BaseFuncSymbols::inst().acons);
    addSymbol(symbolTable, "car", BaseFuncSymbols::inst().acar);
    addSymbol(symbolTable, "cdr", BaseFuncSymbols::inst().acdr);
    addSymbol(symbolTable, "eq", BaseFuncSymbols::inst().aeq);

    addSymbol(symbolTable, "t", Ptr::at);

    addSymbol(symbolTable, "^", BaseMacroSymbols::inst().agensym);
    addSymbol(symbolTable, "~", BaseMacroSymbols::inst().acurctx);
    addSymbol(symbolTable, "_", BaseMacroSymbols::inst().abot);
    addSymbol(symbolTable, "|", BaseMacroSymbols::inst().atry);
    addSymbol(symbolTable, "$", BaseMacroSymbols::inst().aunlazy);
    addSymbol(symbolTable, "#", BaseMacroSymbols::inst().alazy);
    addSymbol(symbolTable, "%", BaseMacroSymbols::inst().amacro);
    addSymbol(symbolTable, "`", BaseMacroSymbols::inst().aapply);
    addSymbol(symbolTable, "@", BaseMacroSymbols::inst().alabel);
    addSymbol(symbolTable, "?", BaseMacroSymbols::inst().aif);
    addSymbol(symbolTable, "\\", BaseMacroSymbols::inst().alambda);
    addSymbol(symbolTable, ">-", BaseMacroSymbols::inst().alet);
    addSymbol(symbolTable, "'", BaseMacroSymbols::inst().aquote);
    return symbolTable;
}

} // namespaces
