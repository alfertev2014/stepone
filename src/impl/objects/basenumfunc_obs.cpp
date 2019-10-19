#include <impl/objects/basenumfunc_obs.h>

#include <impl/operations/cppoperators.h>
#include <impl/operations/value_operations.h>
#include <impl/operations/typepredicates_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseNumFunc::BaseNumFunc() :
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

Ptr BaseNumFunc::populateContext(const Ptr &a) const
{
    Ptr ctx = Context::make(aintNeg, Ob::of<BaseMacro>(Function<ValueUnOp<int, MinusUnOp<int> >>()), a);
    Context::make(aintPlus, Ob::of<BaseMacro>(Function<ValueBinOp<int, PlusBinOp<int> >>()), ctx);
    Context::make(aintMinus, Ob::of<BaseMacro>(Function<ValueBinOp<int, MinusBinOp<int> >>()), ctx);
    Context::make(aintProduct, Ob::of<BaseMacro>(Function<ValueBinOp<int, ProductBinOp<int> >>()), ctx);
    Context::make(aintDivision, Ob::of<BaseMacro>(Function<ValueBinOp<int, DivisionBinOp<int> >>()), ctx);
    Context::make(aintMod, Ob::of<BaseMacro>(Function<ValueBinOp<int, ModBinOp<int> >>()), ctx);
    Context::make(aintp, Ob::of<BaseMacro>(Function<TypePUnOp<Value<int>>>()), ctx);

    Context::make(aintand, Ob::of<BaseMacro>(Function<ValueBinOp<int, BitAndBinOp<int> >>()), ctx);
    Context::make(aintor, Ob::of<BaseMacro>(Function<ValueBinOp<int, BitOrBinOp<int> >>()), ctx);
    Context::make(aintxor, Ob::of<BaseMacro>(Function<ValueBinOp<int, BitXorBinOp<int> >>()), ctx);
    Context::make(aintnot, Ob::of<BaseMacro>(Function<ValueUnOp<int, BitNotUnOp<int> >>()), ctx);

    Context::make(aintshl, Ob::of<BaseMacro>(Function<ValueBinOp<int, BitSHLBinOp<int> >>()), ctx);
    Context::make(aintshr, Ob::of<BaseMacro>(Function<ValueBinOp<int, BitSHRBinOp<int> >>()), ctx);

    Context::make(aintEql, Ob::of<BaseMacro>(Function<ValueCmpOp<int, EqlCmpOp<int> >>()), ctx);
    Context::make(aintNE, Ob::of<BaseMacro>(Function<ValueCmpOp<int, NECmpOp<int> >>()), ctx);
    Context::make(aintGT, Ob::of<BaseMacro>(Function<ValueCmpOp<int, GTCmpOp<int> >>()), ctx);
    Context::make(aintLT, Ob::of<BaseMacro>(Function<ValueCmpOp<int, LTCmpOp<int> >>()), ctx);
    Context::make(aintGE, Ob::of<BaseMacro>(Function<ValueCmpOp<int, GECmpOp<int> >>()), ctx);
    Context::make(aintLE, Ob::of<BaseMacro>(Function<ValueCmpOp<int, LECmpOp<int> >>()), ctx);

    Context::make(alongp, Ob::of<BaseMacro>(Function<TypePUnOp<Value<long long>>>()), ctx);
    Context::make(alongand, Ob::of<BaseMacro>(Function<ValueBinOp<long long, BitAndBinOp<long long> >>()), ctx);
    Context::make(alongor, Ob::of<BaseMacro>(Function<ValueBinOp<long long, BitOrBinOp<long long> >>()), ctx);
    Context::make(alongxor, Ob::of<BaseMacro>(Function<ValueBinOp<long long, BitXorBinOp<long long> >>()), ctx);
    Context::make(alongnot, Ob::of<BaseMacro>(Function<ValueUnOp<long long, BitNotUnOp<long long> >>()), ctx);

    Context::make(alongshl, Ob::of<BaseMacro>(Function<ValueBinOp<long long, BitSHLBinOp<long long> >>()), ctx);
    Context::make(alongshr, Ob::of<BaseMacro>(Function<ValueBinOp<long long, BitSHRBinOp<long long> >>()), ctx);

    Context::make(alongEql, Ob::of<BaseMacro>(Function<ValueCmpOp<long long, EqlCmpOp<long long> >>()), ctx);
    Context::make(alongNE, Ob::of<BaseMacro>(Function<ValueCmpOp<long long, NECmpOp<long long> >>()), ctx);
    Context::make(alongGT, Ob::of<BaseMacro>(Function<ValueCmpOp<long long, LTCmpOp<long long> >>()), ctx);
    Context::make(alongLT, Ob::of<BaseMacro>(Function<ValueCmpOp<long long, GTCmpOp<long long> >>()), ctx);
    Context::make(alongGE, Ob::of<BaseMacro>(Function<ValueCmpOp<long long, LECmpOp<long long> >>()), ctx);
    Context::make(alongLE, Ob::of<BaseMacro>(Function<ValueCmpOp<long long, GECmpOp<long long> >>()), ctx);

    Context::make(afloatNeg, Ob::of<BaseMacro>(Function<ValueUnOp<float, MinusUnOp<float> >>()), ctx);
    Context::make(afloatPlus, Ob::of<BaseMacro>(Function<ValueBinOp<float, PlusBinOp<float> >>()), ctx);
    Context::make(afloatMinus, Ob::of<BaseMacro>(Function<ValueBinOp<float, MinusBinOp<float> >>()), ctx);
    Context::make(afloatProduct, Ob::of<BaseMacro>(Function<ValueBinOp<float, ProductBinOp<float> >>()), ctx);
    Context::make(afloatDivision, Ob::of<BaseMacro>(Function<ValueBinOp<float, DivisionBinOp<float> >>()), ctx);
    Context::make(afloatp, Ob::of<BaseMacro>(Function<TypePUnOp<Value<float>>>()), ctx);
    Context::make(afloatEql, Ob::of<BaseMacro>(Function<ValueCmpOp<float, EqlCmpOp<float> >>()), ctx);
    Context::make(afloatNE, Ob::of<BaseMacro>(Function<ValueCmpOp<float, NECmpOp<float> >>()), ctx);
    Context::make(afloatGT, Ob::of<BaseMacro>(Function<ValueCmpOp<float, GTCmpOp<float> >>()), ctx);
    Context::make(afloatLT, Ob::of<BaseMacro>(Function<ValueCmpOp<float, LTCmpOp<float> >>()), ctx);
    Context::make(afloatGE, Ob::of<BaseMacro>(Function<ValueCmpOp<float, GECmpOp<float> >>()), ctx);
    Context::make(afloatLE, Ob::of<BaseMacro>(Function<ValueCmpOp<float, LECmpOp<float> >>()), ctx);

    Context::make(aint2long, Ob::of<BaseMacro>(Function<ValueCastUnOp<int, long long>>()), ctx);
    Context::make(along2int, Ob::of<BaseMacro>(Function<ValueCastUnOp<long long, int>>()), ctx);

    Context::make(afloat2int, Ob::of<BaseMacro>(Function<ValueCastUnOp<float, int>>()), ctx);
    Context::make(aint2float, Ob::of<BaseMacro>(Function<ValueCastUnOp<int, float>>()), ctx);

    Context::make(achar2int, Ob::of<BaseMacro>(Function<ValueCastUnOp<char, long long>>()), ctx);
    Context::make(aint2char, Ob::of<BaseMacro>(Function<ValueCastUnOp<long long, char>>()), ctx);

    Context::make(achar2long, Ob::of<BaseMacro>(Function<ValueCastUnOp<char, int>>()), ctx);
    Context::make(along2char, Ob::of<BaseMacro>(Function<ValueCastUnOp<int, char>>()), ctx);

    Context::make(acharp, Ob::of<BaseMacro>(Function<TypePUnOp<Value<char>>>()), ctx);
    Context::make(acharand, Ob::of<BaseMacro>(Function<ValueBinOp<char, BitAndBinOp<char> >>()), ctx);
    Context::make(acharor, Ob::of<BaseMacro>(Function<ValueBinOp<char, BitOrBinOp<char> >>()), ctx);
    Context::make(acharxor, Ob::of<BaseMacro>(Function<ValueBinOp<char, BitXorBinOp<char> >>()), ctx);
    Context::make(acharnot, Ob::of<BaseMacro>(Function<ValueUnOp<char, BitNotUnOp<char> >>()), ctx);

    Context::make(acharshl, Ob::of<BaseMacro>(Function<ValueBinOp<char, BitSHLBinOp<char> >>()), ctx);
    Context::make(acharshr, Ob::of<BaseMacro>(Function<ValueBinOp<char, BitSHRBinOp<char> >>()), ctx);

    Context::make(acharEql, Ob::of<BaseMacro>(Function<ValueCmpOp<char, EqlCmpOp<char> >>()), ctx);
    Context::make(acharNE, Ob::of<BaseMacro>(Function<ValueCmpOp<char, NECmpOp<char> >>()), ctx);
    Context::make(acharGT, Ob::of<BaseMacro>(Function<ValueCmpOp<char, GTCmpOp<char> >>()), ctx);
    Context::make(acharLT, Ob::of<BaseMacro>(Function<ValueCmpOp<char, LTCmpOp<char> >>()), ctx);
    Context::make(acharGE, Ob::of<BaseMacro>(Function<ValueCmpOp<char, GECmpOp<char> >>()), ctx);
    Context::make(acharLE, Ob::of<BaseMacro>(Function<ValueCmpOp<char, LECmpOp<char> >>()), ctx);

    Context::make(aszi, core::Ob::of<core::Value<int>>(sizeof(int)), ctx);
    Context::make(aszf, core::Ob::of<core::Value<int>>(sizeof(float)), ctx);
    Context::make(aszc, core::Ob::of<core::Value<int>>(sizeof(char)), ctx);
    Context::make(aszu, core::Ob::of<core::Value<int>>(sizeof(long long)), ctx);

    return ctx;
}

const BaseNumFunc &BaseNumFunc::inst()
{
    static const BaseNumFunc instance;
    return instance;
}

} // namespaces
