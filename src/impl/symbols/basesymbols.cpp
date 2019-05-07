#include <impl/symbols/basesymbols.h>

#include <impl/core/core.h>

namespace stepone::symbols {

using namespace core;

BaseMacroSymbols::BaseMacroSymbols() :
    aquote(Ob::of<Symbol>()),
    aapply(Ob::of<Symbol>()),
    aif(Ob::of<Symbol>()),
    alet(Ob::of<Symbol>()),
    alazy(Ob::of<Symbol>()),
    aunlazy(Ob::of<Symbol>()),
    alabel(Ob::of<Symbol>()),
    alambda(Ob::of<Symbol>()),
    amacro(Ob::of<Symbol>()),
    acurctx(Ob::of<Symbol>()),
    atry(Ob::of<Symbol>()),
    abot(Ob::of<Symbol>()),
    agensym(Ob::of<Symbol>())
{}

const BaseMacroSymbols &BaseMacroSymbols::inst()
{
    static const BaseMacroSymbols instance;
    return instance;
}


BaseFuncSymbols::BaseFuncSymbols() :
    acar(Ob::of<Symbol>()),
    acdr(Ob::of<Symbol>()),
    acons(Ob::of<Symbol>()),
    aeq(Ob::of<Symbol>()),
    agettype(Ob::of<Symbol>()),
    actxget(Ob::of<Symbol>()),
    actxpush(Ob::of<Symbol>()),

    aeempty(Ob::of<Symbol>())
{}

const BaseFuncSymbols &BaseFuncSymbols::inst()
{
    static const BaseFuncSymbols instance;
    return instance;
}


BaseTypePredSymbols::BaseTypePredSymbols() :
    apairp(Ob::of<Symbol>()),
    alazyp(Ob::of<Symbol>()),
    alabelp(Ob::of<Symbol>()),
    aatomp(Ob::of<Symbol>()),
    asymbolp(Ob::of<Symbol>()),
    aconstp(Ob::of<Symbol>()),
    amacrop(Ob::of<Symbol>()),
    aevalp(Ob::of<Symbol>()),
    abasemacrop(Ob::of<Symbol>()),
    ausermacrop(Ob::of<Symbol>()),
    avaluep(Ob::of<Symbol>())
{}

const BaseTypePredSymbols &BaseTypePredSymbols::inst()
{
    static const BaseTypePredSymbols instance;
    return instance;
}


BaseNumFuncSymbols::BaseNumFuncSymbols() :
    aintNeg(Ob::of<Symbol>()),
    aintPlus(Ob::of<Symbol>()),
    aintMinus(Ob::of<Symbol>()),
    aintProduct(Ob::of<Symbol>()),
    aintDivision(Ob::of<Symbol>()),
    aintMod(Ob::of<Symbol>()),
    aintp(Ob::of<Symbol>()),

    aintand(Ob::of<Symbol>()),
    aintor(Ob::of<Symbol>()),
    aintxor(Ob::of<Symbol>()),
    aintnot(Ob::of<Symbol>()),

    aintshl(Ob::of<Symbol>()),
    aintshr(Ob::of<Symbol>()),

    aintEql(Ob::of<Symbol>()),
    aintNE(Ob::of<Symbol>()),
    aintGT(Ob::of<Symbol>()),
    aintLT(Ob::of<Symbol>()),
    aintGE(Ob::of<Symbol>()),
    aintLE(Ob::of<Symbol>()),

    alongp(Ob::of<Symbol>()),
    alongand(Ob::of<Symbol>()),
    alongor(Ob::of<Symbol>()),
    alongxor(Ob::of<Symbol>()),
    alongnot(Ob::of<Symbol>()),

    alongEql(Ob::of<Symbol>()),
    alongNE(Ob::of<Symbol>()),
    alongGT(Ob::of<Symbol>()),
    alongLT(Ob::of<Symbol>()),
    alongGE(Ob::of<Symbol>()),
    alongLE(Ob::of<Symbol>()),

    alongshl(Ob::of<Symbol>()),
    alongshr(Ob::of<Symbol>()),

    afloatNeg(Ob::of<Symbol>()),
    afloatPlus(Ob::of<Symbol>()),
    afloatMinus(Ob::of<Symbol>()),
    afloatProduct(Ob::of<Symbol>()),
    afloatDivision(Ob::of<Symbol>()),
    afloatp(Ob::of<Symbol>()),
    afloatEql(Ob::of<Symbol>()),
    afloatNE(Ob::of<Symbol>()),
    afloatGT(Ob::of<Symbol>()),
    afloatLT(Ob::of<Symbol>()),
    afloatGE(Ob::of<Symbol>()),
    afloatLE(Ob::of<Symbol>()),

    along2int(Ob::of<Symbol>()),
    aint2long(Ob::of<Symbol>()),

    afloat2int(Ob::of<Symbol>()),
    aint2float(Ob::of<Symbol>()),

    achar2int(Ob::of<Symbol>()),
    aint2char(Ob::of<Symbol>()),

    achar2long(Ob::of<Symbol>()),
    along2char(Ob::of<Symbol>()),

    acharp(Ob::of<Symbol>()),
    acharand(Ob::of<Symbol>()),
    acharor(Ob::of<Symbol>()),
    acharxor(Ob::of<Symbol>()),
    acharnot(Ob::of<Symbol>()),

    acharshl(Ob::of<Symbol>()),
    acharshr(Ob::of<Symbol>()),

    acharEql(Ob::of<Symbol>()),
    acharNE(Ob::of<Symbol>()),
    acharGT(Ob::of<Symbol>()),
    acharLT(Ob::of<Symbol>()),
    acharGE(Ob::of<Symbol>()),
    acharLE(Ob::of<Symbol>()),

    aszi(Ob::of<Symbol>()),
    aszf(Ob::of<Symbol>()),
    aszc(Ob::of<Symbol>()),
    aszu(Ob::of<Symbol>())
{}

const BaseNumFuncSymbols &BaseNumFuncSymbols::inst()
{
    static const BaseNumFuncSymbols instance;
    return instance;
}


VectorFuncSymbols::VectorFuncSymbols() :
    avecp(Ob::of<Symbol>()),
    amkvec(Ob::of<Symbol>()),
    avecclone(Ob::of<Symbol>()),
    aveclen(Ob::of<Symbol>()),
    avecmid(Ob::of<Symbol>()),
    avecslice(Ob::of<Symbol>()),
    avecel(Ob::of<Symbol>()),
    aveccat(Ob::of<Symbol>())
{}

const VectorFuncSymbols &VectorFuncSymbols::inst()
{
    static const VectorFuncSymbols instance;
    return instance;
}


ByteArrayFuncSymbols::ByteArrayFuncSymbols() :
    abarrayp(Ob::of<Symbol>()),
    abarraylen(Ob::of<Symbol>()),
    abarrayclone(Ob::of<Symbol>()),
    abarraycmp(Ob::of<Symbol>()),
    abarrayncmp(Ob::of<Symbol>()),
    abarrayfindch(Ob::of<Symbol>()),
    abarrayfind(Ob::of<Symbol>()),
    abarraycat(Ob::of<Symbol>()),
    abarraymid(Ob::of<Symbol>()),
    abarrayslice(Ob::of<Symbol>()),

    aserint(Ob::of<Symbol>()),
    aserfloat(Ob::of<Symbol>()),
    aserchar(Ob::of<Symbol>()),

    agetint(Ob::of<Symbol>()),
    agetfloat(Ob::of<Symbol>()),
    agetchar(Ob::of<Symbol>())
{}

const ByteArrayFuncSymbols &ByteArrayFuncSymbols::inst()
{
    static const ByteArrayFuncSymbols instance;
    return instance;
}

} // namespaces
