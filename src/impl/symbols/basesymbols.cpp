#include <impl/symbols/basesymbols.h>

#include <impl/core/core.h>

namespace stepone::symbols {

using namespace core;

BaseMacroSymbols::BaseMacroSymbols() :
    aquote(new Ob(Symbol())),
    aapply(new Ob(Symbol())),
    aif(new Ob(Symbol())),
    alet(new Ob(Symbol())),
    alazy(new Ob(Symbol())),
    aunlazy(new Ob(Symbol())),
    alabel(new Ob(Symbol())),
    alambda(new Ob(Symbol())),
    amacro(new Ob(Symbol())),
    acurctx(new Ob(Symbol())),
    atry(new Ob(Symbol())),
    abot(new Ob(Symbol())),
    agensym(new Ob(Symbol()))
{}

const BaseMacroSymbols &BaseMacroSymbols::inst()
{
    static const BaseMacroSymbols instance;
    return instance;
}


BaseFuncSymbols::BaseFuncSymbols() :
    acar(new Ob(Symbol())),
    acdr(new Ob(Symbol())),
    acons(new Ob(Symbol())),
    aeq(new Ob(Symbol())),
    agettype(new Ob(Symbol())),
    actxget(new Ob(Symbol())),
    actxpush(new Ob(Symbol())),

    aeempty(new Ob(Symbol()))
{}

const BaseFuncSymbols &BaseFuncSymbols::inst()
{
    static const BaseFuncSymbols instance;
    return instance;
}


BaseTypePredSymbols::BaseTypePredSymbols() :
    apairp(new Ob(Symbol())),
    alazyp(new Ob(Symbol())),
    alabelp(new Ob(Symbol())),
    aatomp(new Ob(Symbol())),
    asymbolp(new Ob(Symbol())),
    aconstp(new Ob(Symbol())),
    amacrop(new Ob(Symbol())),
    aevalp(new Ob(Symbol())),
    abasemacrop(new Ob(Symbol())),
    ausermacrop(new Ob(Symbol())),
    avaluep(new Ob(Symbol()))
{}

const BaseTypePredSymbols &BaseTypePredSymbols::inst()
{
    static const BaseTypePredSymbols instance;
    return instance;
}


BaseNumFuncSymbols::BaseNumFuncSymbols() :
    aintNeg(new Ob(Symbol())),
    aintPlus(new Ob(Symbol())),
    aintMinus(new Ob(Symbol())),
    aintProduct(new Ob(Symbol())),
    aintDivision(new Ob(Symbol())),
    aintMod(new Ob(Symbol())),
    aintp(new Ob(Symbol())),

    aintand(new Ob(Symbol())),
    aintor(new Ob(Symbol())),
    aintxor(new Ob(Symbol())),
    aintnot(new Ob(Symbol())),

    aintshl(new Ob(Symbol())),
    aintshr(new Ob(Symbol())),

    aintEql(new Ob(Symbol())),
    aintNE(new Ob(Symbol())),
    aintGT(new Ob(Symbol())),
    aintLT(new Ob(Symbol())),
    aintGE(new Ob(Symbol())),
    aintLE(new Ob(Symbol())),

    alongp(new Ob(Symbol())),
    alongand(new Ob(Symbol())),
    alongor(new Ob(Symbol())),
    alongxor(new Ob(Symbol())),
    alongnot(new Ob(Symbol())),

    alongEql(new Ob(Symbol())),
    alongNE(new Ob(Symbol())),
    alongGT(new Ob(Symbol())),
    alongLT(new Ob(Symbol())),
    alongGE(new Ob(Symbol())),
    alongLE(new Ob(Symbol())),

    alongshl(new Ob(Symbol())),
    alongshr(new Ob(Symbol())),

    afloatNeg(new Ob(Symbol())),
    afloatPlus(new Ob(Symbol())),
    afloatMinus(new Ob(Symbol())),
    afloatProduct(new Ob(Symbol())),
    afloatDivision(new Ob(Symbol())),
    afloatp(new Ob(Symbol())),
    afloatEql(new Ob(Symbol())),
    afloatNE(new Ob(Symbol())),
    afloatGT(new Ob(Symbol())),
    afloatLT(new Ob(Symbol())),
    afloatGE(new Ob(Symbol())),
    afloatLE(new Ob(Symbol())),

    along2int(new Ob(Symbol())),
    aint2long(new Ob(Symbol())),

    afloat2int(new Ob(Symbol())),
    aint2float(new Ob(Symbol())),

    achar2int(new Ob(Symbol())),
    aint2char(new Ob(Symbol())),

    achar2long(new Ob(Symbol())),
    along2char(new Ob(Symbol())),

    acharp(new Ob(Symbol())),
    acharand(new Ob(Symbol())),
    acharor(new Ob(Symbol())),
    acharxor(new Ob(Symbol())),
    acharnot(new Ob(Symbol())),

    acharshl(new Ob(Symbol())),
    acharshr(new Ob(Symbol())),

    acharEql(new Ob(Symbol())),
    acharNE(new Ob(Symbol())),
    acharGT(new Ob(Symbol())),
    acharLT(new Ob(Symbol())),
    acharGE(new Ob(Symbol())),
    acharLE(new Ob(Symbol())),

    aszi(new Ob(Symbol())),
    aszf(new Ob(Symbol())),
    aszc(new Ob(Symbol())),
    aszu(new Ob(Symbol()))
{}

const BaseNumFuncSymbols &BaseNumFuncSymbols::inst()
{
    static const BaseNumFuncSymbols instance;
    return instance;
}


VectorFuncSymbols::VectorFuncSymbols() :
    avecp(new Ob(Symbol())),
    amkvec(new Ob(Symbol())),
    avecclone(new Ob(Symbol())),
    aveclen(new Ob(Symbol())),
    avecmid(new Ob(Symbol())),
    avecslice(new Ob(Symbol())),
    avecel(new Ob(Symbol())),
    aveccat(new Ob(Symbol()))
{}

const VectorFuncSymbols &VectorFuncSymbols::inst()
{
    static const VectorFuncSymbols instance;
    return instance;
}


ByteArrayFuncSymbols::ByteArrayFuncSymbols() :
    abarrayp(new Ob(Symbol())),
    abarraylen(new Ob(Symbol())),
    abarrayclone(new Ob(Symbol())),
    abarraycmp(new Ob(Symbol())),
    abarrayncmp(new Ob(Symbol())),
    abarrayfindch(new Ob(Symbol())),
    abarrayfind(new Ob(Symbol())),
    abarraycat(new Ob(Symbol())),
    abarraymid(new Ob(Symbol())),
    abarrayslice(new Ob(Symbol())),

    aserint(new Ob(Symbol())),
    aserfloat(new Ob(Symbol())),
    aserchar(new Ob(Symbol())),

    agetint(new Ob(Symbol())),
    agetfloat(new Ob(Symbol())),
    agetchar(new Ob(Symbol()))
{}

const ByteArrayFuncSymbols &ByteArrayFuncSymbols::inst()
{
    static const ByteArrayFuncSymbols instance;
    return instance;
}

} // namespaces
