#include <init/initsymbols.h>

#include <impl/objects/basefunc_obs.h>
#include <impl/objects/basenumfunc_obs.h>
#include <impl/objects/basemacro_obs.h>
#include <impl/objects/typepredicates_obs.h>
#include <impl/objects/bytearray_obs.h>
#include <impl/objects/vector_obs.h>

#include <impl/core/bytearray.h>

#include <impl/ptr_impl.h>

using namespace stepone::core;
using namespace stepone::objects;

namespace stepone::init {


static inline void addSymbol(Ptr & symbolTable, const std::string & s, const Ptr & p) {
    symbolTable = Ob::of<Pair>(Ob::of<Pair>(p, Ob::of<ByteArray>(s.data(), s.size())), symbolTable);
}

Ptr BaseSymbolTable::createSymbolTable() {
    Ptr symbolTable(Ptr::anil());
    addSymbol(symbolTable, "-i", BaseNumFunc::inst().aintNeg);
    addSymbol(symbolTable, "i+", BaseNumFunc::inst().aintPlus);
    addSymbol(symbolTable, "i-", BaseNumFunc::inst().aintMinus);
    addSymbol(symbolTable, "i*", BaseNumFunc::inst().aintProduct);
    addSymbol(symbolTable, "i/", BaseNumFunc::inst().aintDivision);
    addSymbol(symbolTable, "i%", BaseNumFunc::inst().aintMod);
    addSymbol(symbolTable, "i?", BaseNumFunc::inst().aintp);
    addSymbol(symbolTable, "i-not", BaseNumFunc::inst().aintnot);
    addSymbol(symbolTable, "i-and", BaseNumFunc::inst().aintand);
    addSymbol(symbolTable, "i-or", BaseNumFunc::inst().aintor);
    addSymbol(symbolTable, "i-xor", BaseNumFunc::inst().aintxor);
    addSymbol(symbolTable, "i-shl", BaseNumFunc::inst().aintshl);
    addSymbol(symbolTable, "i-shr", BaseNumFunc::inst().aintshr);
    addSymbol(symbolTable, "i=", BaseNumFunc::inst().aintEql);
    addSymbol(symbolTable, "i!=", BaseNumFunc::inst().aintNE);
    addSymbol(symbolTable, "i<", BaseNumFunc::inst().aintLT);
    addSymbol(symbolTable, "i>", BaseNumFunc::inst().aintGT);
    addSymbol(symbolTable, "i<=", BaseNumFunc::inst().aintLE);
    addSymbol(symbolTable, "i>=", BaseNumFunc::inst().aintGE);

    addSymbol(symbolTable, "u?", BaseNumFunc::inst().alongp);
    addSymbol(symbolTable, "u-not", BaseNumFunc::inst().alongnot);
    addSymbol(symbolTable, "u-and", BaseNumFunc::inst().alongand);
    addSymbol(symbolTable, "u-or", BaseNumFunc::inst().alongor);
    addSymbol(symbolTable, "u-xor", BaseNumFunc::inst().alongxor);
    addSymbol(symbolTable, "u-shl", BaseNumFunc::inst().alongshl);
    addSymbol(symbolTable, "u-shr", BaseNumFunc::inst().alongshr);

    addSymbol(symbolTable, "u=", BaseNumFunc::inst().alongEql);
    addSymbol(symbolTable, "u!=", BaseNumFunc::inst().alongNE);
    addSymbol(symbolTable, "u<", BaseNumFunc::inst().alongLT);
    addSymbol(symbolTable, "u>", BaseNumFunc::inst().alongGT);
    addSymbol(symbolTable, "u<=", BaseNumFunc::inst().alongLE);
    addSymbol(symbolTable, "u>=", BaseNumFunc::inst().alongGE);

    addSymbol(symbolTable, "c?", BaseNumFunc::inst().acharp);
    addSymbol(symbolTable, "c-not", BaseNumFunc::inst().acharnot);
    addSymbol(symbolTable, "c-and", BaseNumFunc::inst().acharand);
    addSymbol(symbolTable, "c-or", BaseNumFunc::inst().acharor);
    addSymbol(symbolTable, "c-xor", BaseNumFunc::inst().acharxor);
    addSymbol(symbolTable, "c-shl", BaseNumFunc::inst().acharshl);
    addSymbol(symbolTable, "c-shr", BaseNumFunc::inst().acharshr);
    addSymbol(symbolTable, "c=", BaseNumFunc::inst().acharEql);
    addSymbol(symbolTable, "c!=", BaseNumFunc::inst().acharNE);
    addSymbol(symbolTable, "c<", BaseNumFunc::inst().acharLT);
    addSymbol(symbolTable, "c>", BaseNumFunc::inst().acharGT);
    addSymbol(symbolTable, "c<=", BaseNumFunc::inst().acharLE);
    addSymbol(symbolTable, "c>=", BaseNumFunc::inst().acharGE);

    addSymbol(symbolTable, "-f", BaseNumFunc::inst().afloatNeg);
    addSymbol(symbolTable, "f+", BaseNumFunc::inst().afloatPlus);
    addSymbol(symbolTable, "f-", BaseNumFunc::inst().afloatMinus);
    addSymbol(symbolTable, "f*", BaseNumFunc::inst().afloatProduct);
    addSymbol(symbolTable, "f/", BaseNumFunc::inst().afloatDivision);
    addSymbol(symbolTable, "f?", BaseNumFunc::inst().afloatp);
    addSymbol(symbolTable, "f=", BaseNumFunc::inst().afloatEql);
    addSymbol(symbolTable, "f!=", BaseNumFunc::inst().afloatNE);
    addSymbol(symbolTable, "f<", BaseNumFunc::inst().afloatLT);
    addSymbol(symbolTable, "f>", BaseNumFunc::inst().afloatGT);
    addSymbol(symbolTable, "f<=", BaseNumFunc::inst().afloatLE);
    addSymbol(symbolTable, "f>=", BaseNumFunc::inst().afloatGE);

    addSymbol(symbolTable, "u2i", BaseNumFunc::inst().along2int);
    addSymbol(symbolTable, "i2u", BaseNumFunc::inst().aint2long);
    addSymbol(symbolTable, "f2i", BaseNumFunc::inst().afloat2int);
    addSymbol(symbolTable, "i2f", BaseNumFunc::inst().aint2float);
    addSymbol(symbolTable, "c2i", BaseNumFunc::inst().achar2int);
    addSymbol(symbolTable, "i2c", BaseNumFunc::inst().aint2char);
    addSymbol(symbolTable, "c2u", BaseNumFunc::inst().achar2long);
    addSymbol(symbolTable, "u2c", BaseNumFunc::inst().along2char);

    addSymbol(symbolTable, "sz-i", BaseNumFunc::inst().aszi);
    addSymbol(symbolTable, "sz-f", BaseNumFunc::inst().aszf);
    addSymbol(symbolTable, "sz-c", BaseNumFunc::inst().aszc);
    addSymbol(symbolTable, "sz-u", BaseNumFunc::inst().aszu);

    addSymbol(symbolTable, "vec?", VectorFunctions::inst().avecp);
    addSymbol(symbolTable, "mkvec", VectorFunctions::inst().amkvec);
    addSymbol(symbolTable, "vec-clone", VectorFunctions::inst().avecclone);
    addSymbol(symbolTable, "vec-len", VectorFunctions::inst().aveclen);
    addSymbol(symbolTable, "vec-mid", VectorFunctions::inst().avecmid);
    addSymbol(symbolTable, "vec-slice", VectorFunctions::inst().avecslice);
    addSymbol(symbolTable, "vec-el", VectorFunctions::inst().avecel);
    addSymbol(symbolTable, "vec-cat", VectorFunctions::inst().aveccat);

    addSymbol(symbolTable, "b?", ByteArrayFunctions::inst().abarrayp);
    addSymbol(symbolTable, "b-len", ByteArrayFunctions::inst().abarraylen);
    addSymbol(symbolTable, "b-clone", ByteArrayFunctions::inst().abarrayclone);
    addSymbol(symbolTable, "b-cmp", ByteArrayFunctions::inst().abarraycmp);
    addSymbol(symbolTable, "b-ncmp", ByteArrayFunctions::inst().abarrayncmp);
    addSymbol(symbolTable, "b-findch", ByteArrayFunctions::inst().abarrayfindch);
    addSymbol(symbolTable, "b-find", ByteArrayFunctions::inst().abarrayfind);
    addSymbol(symbolTable, "b-cat", ByteArrayFunctions::inst().abarraycat);
    addSymbol(symbolTable, "b-mid", ByteArrayFunctions::inst().abarraymid);
    addSymbol(symbolTable, "b-slice", ByteArrayFunctions::inst().abarrayslice);
    addSymbol(symbolTable, "i2b", ByteArrayFunctions::inst().aserint);
    addSymbol(symbolTable, "f2b", ByteArrayFunctions::inst().aserfloat);
    addSymbol(symbolTable, "c2b", ByteArrayFunctions::inst().aserchar);
    addSymbol(symbolTable, "b-geti", ByteArrayFunctions::inst().agetint);
    addSymbol(symbolTable, "b-getf", ByteArrayFunctions::inst().agetfloat);
    addSymbol(symbolTable, "b-getc", ByteArrayFunctions::inst().agetchar);

    addSymbol(symbolTable, "pair?", BaseTypePredicates::inst().apairp);
    addSymbol(symbolTable, "lazy?", BaseTypePredicates::inst().alazyp);
    addSymbol(symbolTable, "label?", BaseTypePredicates::inst().alabelp);
    addSymbol(symbolTable, "atom?", BaseTypePredicates::inst().aatomp);
    addSymbol(symbolTable, "symbol?", BaseTypePredicates::inst().asymbolp);
    addSymbol(symbolTable, "const?", BaseTypePredicates::inst().aconstp);
    addSymbol(symbolTable, "macro?", BaseTypePredicates::inst().amacrop);
    addSymbol(symbolTable, "basemacro?", BaseTypePredicates::inst().abasemacrop);
    addSymbol(symbolTable, "usermacro?", BaseTypePredicates::inst().ausermacrop);
    addSymbol(symbolTable, "spectype?", BaseTypePredicates::inst().avaluep);

    addSymbol(symbolTable, "ctx-get", BaseFunctions::inst().actxget);
    addSymbol(symbolTable, "ctx-push", BaseFunctions::inst().actxpush);
    addSymbol(symbolTable, "empty-ctx", BaseFunctions::inst().aeempty);
    addSymbol(symbolTable, "get-type", BaseFunctions::inst().agettype);
    addSymbol(symbolTable, "cons", BaseFunctions::inst().acons);
    addSymbol(symbolTable, "car", BaseFunctions::inst().acar);
    addSymbol(symbolTable, "cdr", BaseFunctions::inst().acdr);
    addSymbol(symbolTable, "eq", BaseFunctions::inst().aeq);

    addSymbol(symbolTable, "t", Ptr::at());

    addSymbol(symbolTable, "^", BaseMacroses::inst().agensym);
    addSymbol(symbolTable, "~", BaseMacroses::inst().acurctx);
    addSymbol(symbolTable, "_", BaseMacroses::inst().abot);
    addSymbol(symbolTable, "|", BaseMacroses::inst().atry);
    addSymbol(symbolTable, "$", BaseMacroses::inst().aunlazy);
    addSymbol(symbolTable, "#", BaseMacroses::inst().alazy);
    addSymbol(symbolTable, "%", BaseMacroses::inst().amacro);
    addSymbol(symbolTable, "`", BaseMacroses::inst().aapply);
    addSymbol(symbolTable, "@", BaseMacroses::inst().alabel);
    addSymbol(symbolTable, "?", BaseMacroses::inst().aif);
    addSymbol(symbolTable, "\\", BaseMacroses::inst().alambda);
    addSymbol(symbolTable, ">-", BaseMacroses::inst().alet);
    addSymbol(symbolTable, "'", BaseMacroses::inst().aquote);
    return symbolTable;
}

} // namespaces
