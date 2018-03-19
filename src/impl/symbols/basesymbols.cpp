#include <impl/symbols/basesymbols.h>

#include <impl/core/core.h>

BaseMacroSymbols::BaseMacroSymbols() :
    aquote(new Symbol),
    aapply(new Symbol),
    aif(new Symbol),
    alet(new Symbol),
    alazy(new Symbol),
    aunlazy(new Symbol),
    alabel(new Symbol),
    alambda(new Symbol),
    amacro(new Symbol),
    acurctx(new Symbol),
    atry(new Symbol),
    abot(new Symbol),
    agensym(new Symbol)
{}

const BaseMacroSymbols &BaseMacroSymbols::inst()
{
    static const BaseMacroSymbols instance;
    return instance;
}


BaseFuncSymbols::BaseFuncSymbols() :
    acar(new Symbol),
    acdr(new Symbol),
    acons(new Symbol),
    aeq(new Symbol),
    agettype(new Symbol),
    actxget(new Symbol),
    actxpush(new Symbol),

    aeempty(new Symbol)
{}

const BaseFuncSymbols &BaseFuncSymbols::inst()
{
    static const BaseFuncSymbols instance;
    return instance;
}


BaseTypePredSymbols::BaseTypePredSymbols() :
    apairp(new Symbol),
    alazyp(new Symbol),
    alabelp(new Symbol),
    aatomp(new Symbol),
    asymbolp(new Symbol),
    aconstp(new Symbol),
    amacrop(new Symbol),
    aevalp(new Symbol),
    abasemacrop(new Symbol),
    ausermacrop(new Symbol),
    avaluep(new Symbol)
{}

const BaseTypePredSymbols &BaseTypePredSymbols::inst()
{
    static const BaseTypePredSymbols instance;
    return instance;
}


BaseNumFuncSymbols::BaseNumFuncSymbols() :
    aintNeg(new Symbol),
    aintPlus(new Symbol),
    aintMinus(new Symbol),
    aintProduct(new Symbol),
    aintDivision(new Symbol),
    aintMod(new Symbol),
    aintp(new Symbol),

    aintand(new Symbol),
    aintor(new Symbol),
    aintxor(new Symbol),
    aintnot(new Symbol),

    aintshl(new Symbol),
    aintshr(new Symbol),

    aintEql(new Symbol),
    aintNE(new Symbol),
    aintGT(new Symbol),
    aintLT(new Symbol),
    aintGE(new Symbol),
    aintLE(new Symbol),

    alongp(new Symbol),
    alongand(new Symbol),
    alongor(new Symbol),
    alongxor(new Symbol),
    alongnot(new Symbol),

    alongEql(new Symbol),
    alongNE(new Symbol),
    alongGT(new Symbol),
    alongLT(new Symbol),
    alongGE(new Symbol),
    alongLE(new Symbol),

    alongshl(new Symbol),
    alongshr(new Symbol),

    afloatNeg(new Symbol),
    afloatPlus(new Symbol),
    afloatMinus(new Symbol),
    afloatProduct(new Symbol),
    afloatDivision(new Symbol),
    afloatp(new Symbol),
    afloatEql(new Symbol),
    afloatNE(new Symbol),
    afloatGT(new Symbol),
    afloatLT(new Symbol),
    afloatGE(new Symbol),
    afloatLE(new Symbol),

    along2int(new Symbol),
    aint2long(new Symbol),

    afloat2int(new Symbol),
    aint2float(new Symbol),

    achar2int(new Symbol),
    aint2char(new Symbol),

    achar2long(new Symbol),
    along2char(new Symbol),

    acharp(new Symbol),
    acharand(new Symbol),
    acharor(new Symbol),
    acharxor(new Symbol),
    acharnot(new Symbol),

    acharshl(new Symbol),
    acharshr(new Symbol),

    acharEql(new Symbol),
    acharNE(new Symbol),
    acharGT(new Symbol),
    acharLT(new Symbol),
    acharGE(new Symbol),
    acharLE(new Symbol),

    aszi(new Symbol),
    aszf(new Symbol),
    aszc(new Symbol),
    aszu(new Symbol)
{}

const BaseNumFuncSymbols &BaseNumFuncSymbols::inst()
{
    static const BaseNumFuncSymbols instance;
    return instance;
}


VectorFuncSymbols::VectorFuncSymbols() :
    avecp(new Symbol),
    amkvec(new Symbol),
    avecclone(new Symbol),
    aveclen(new Symbol),
    avecmid(new Symbol),
    avecslice(new Symbol),
    avecel(new Symbol),
    aveccat(new Symbol)
{}

const VectorFuncSymbols &VectorFuncSymbols::inst()
{
    static const VectorFuncSymbols instance;
    return instance;
}


ByteArrayFuncSymbols::ByteArrayFuncSymbols() :
    abarrayp(new Symbol),
    abarraylen(new Symbol),
    abarrayclone(new Symbol),
    abarraycmp(new Symbol),
    abarrayncmp(new Symbol),
    abarrayfindch(new Symbol),
    abarrayfind(new Symbol),
    abarraycat(new Symbol),
    abarraymid(new Symbol),
    abarrayslice(new Symbol),

    aserint(new Symbol),
    aserfloat(new Symbol),
    aserchar(new Symbol),

    agetint(new Symbol),
    agetfloat(new Symbol),
    agetchar(new Symbol)
{}

const ByteArrayFuncSymbols &ByteArrayFuncSymbols::inst()
{
    static const ByteArrayFuncSymbols instance;
    return instance;
}


IOFuncSymbols::IOFuncSymbols() :
    ainputp(new Symbol),
    aoutputp(new Symbol),
    aopenin(new Symbol),
    aopenout(new Symbol),
    aread(new Symbol),
    awrite(new Symbol),

    astdin(new Symbol),
    astdout(new Symbol),
    astderr(new Symbol)
{}

const IOFuncSymbols &IOFuncSymbols::inst()
{
    static const IOFuncSymbols instance;
    return instance;
}
