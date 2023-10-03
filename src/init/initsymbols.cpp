#include "initsymbols.h"

#include <objects/basefunc_obs.h>
#include <objects/basenumfunc_obs.h>
#include <objects/basemacro_obs.h>
#include <objects/typepredicates_obs.h>
#include <objects/bytearray_obs.h>
#include <objects/vector_obs.h>

#include <core/bytearray.h>

#include <ptr_impl.h>
#include <logging.h>

using namespace stepone::core;
using namespace stepone::objects;

namespace stepone::init {


static inline void addSymbol(Ptr & symbolTable, const std::string & s, const Ptr & p) {
    logging::debug("Adding symbol", s, "to symbol table");
    symbolTable = Ptr::of<Pair>(Ptr::of<Pair>(p, Ptr::of<ByteArray>(s.data(), s.size())), symbolTable);
}

Ptr BaseSymbolTable::createSymbolTable() {
    logging::Logger l;
    l.debug("Initializing of symbol table...");
    Ptr symbolTable(Ptr::anil());

    addSymbol(symbolTable, "i?", BaseNumFunc::inst().longOps.aIs);
    addSymbol(symbolTable, "i-not", BaseNumFunc::inst().longOps.aNot);
    addSymbol(symbolTable, "i-and", BaseNumFunc::inst().longOps.aAnd);
    addSymbol(symbolTable, "i-or", BaseNumFunc::inst().longOps.aOr);
    addSymbol(symbolTable, "i-xor", BaseNumFunc::inst().longOps.aXor);
    addSymbol(symbolTable, "i-shl", BaseNumFunc::inst().longOps.aShl);
    addSymbol(symbolTable, "i-shr", BaseNumFunc::inst().longOps.aShr);

    addSymbol(symbolTable, "i=", BaseNumFunc::inst().longOps.aEql);
    addSymbol(symbolTable, "i!=", BaseNumFunc::inst().longOps.aNE);
    addSymbol(symbolTable, "i<", BaseNumFunc::inst().longOps.aLT);
    addSymbol(symbolTable, "i>", BaseNumFunc::inst().longOps.aGT);
    addSymbol(symbolTable, "i<=", BaseNumFunc::inst().longOps.aLE);
    addSymbol(symbolTable, "i>=", BaseNumFunc::inst().longOps.aGE);

    addSymbol(symbolTable, "c?", BaseNumFunc::inst().charOps.aIs);
    addSymbol(symbolTable, "c-not", BaseNumFunc::inst().charOps.aNot);
    addSymbol(symbolTable, "c-and", BaseNumFunc::inst().charOps.aAnd);
    addSymbol(symbolTable, "c-or", BaseNumFunc::inst().charOps.aOr);
    addSymbol(symbolTable, "c-xor", BaseNumFunc::inst().charOps.aXor);
    addSymbol(symbolTable, "c-shl", BaseNumFunc::inst().charOps.aShl);
    addSymbol(symbolTable, "c-shr", BaseNumFunc::inst().charOps.aShr);
    addSymbol(symbolTable, "c=", BaseNumFunc::inst().charOps.aEql);
    addSymbol(symbolTable, "c!=", BaseNumFunc::inst().charOps.aNE);
    addSymbol(symbolTable, "c<", BaseNumFunc::inst().charOps.aLT);
    addSymbol(symbolTable, "c>", BaseNumFunc::inst().charOps.aGT);
    addSymbol(symbolTable, "c<=", BaseNumFunc::inst().charOps.aLE);
    addSymbol(symbolTable, "c>=", BaseNumFunc::inst().charOps.aGE);

    addSymbol(symbolTable, "-f", BaseNumFunc::inst().floatOps.aNeg);
    addSymbol(symbolTable, "f+", BaseNumFunc::inst().floatOps.aPlus);
    addSymbol(symbolTable, "f-", BaseNumFunc::inst().floatOps.aMinus);
    addSymbol(symbolTable, "f*", BaseNumFunc::inst().floatOps.aProduct);
    addSymbol(symbolTable, "f/", BaseNumFunc::inst().floatOps.aDivision);
    addSymbol(symbolTable, "f?", BaseNumFunc::inst().floatOps.aIs);
    addSymbol(symbolTable, "f=", BaseNumFunc::inst().floatOps.aEql);
    addSymbol(symbolTable, "f!=", BaseNumFunc::inst().floatOps.aNE);
    addSymbol(symbolTable, "f<", BaseNumFunc::inst().floatOps.aLT);
    addSymbol(symbolTable, "f>", BaseNumFunc::inst().floatOps.aGT);
    addSymbol(symbolTable, "f<=", BaseNumFunc::inst().floatOps.aLE);
    addSymbol(symbolTable, "f>=", BaseNumFunc::inst().floatOps.aGE);

    addSymbol(symbolTable, "u2i", BaseNumFunc::inst().along2int);
    addSymbol(symbolTable, "i2u", BaseNumFunc::inst().aint2long);
    addSymbol(symbolTable, "f2i", BaseNumFunc::inst().afloat2int);
    addSymbol(symbolTable, "i2f", BaseNumFunc::inst().aint2float);
    addSymbol(symbolTable, "c2i", BaseNumFunc::inst().achar2int);
    addSymbol(symbolTable, "i2c", BaseNumFunc::inst().aint2char);
    addSymbol(symbolTable, "c2u", BaseNumFunc::inst().achar2long);
    addSymbol(symbolTable, "u2c", BaseNumFunc::inst().along2char);

    addSymbol(symbolTable, "sz-f", BaseNumFunc::inst().floatOps.aSz);
    addSymbol(symbolTable, "sz-c", BaseNumFunc::inst().charOps.aSz);
    addSymbol(symbolTable, "sz-i", BaseNumFunc::inst().longOps.aSz);

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
    l.debug("Symbol table is initialized");
    return symbolTable;
}

} // namespaces
