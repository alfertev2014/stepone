#include <impl/objects/basenumfunc_obs.h>

#include <impl/operations/cppoperators.h>
#include <impl/operations/value_operations.h>
#include <impl/operations/typepredicates_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseNumFunc::BaseNumFunc() :
    fintNeg(Ob::of<BaseMacro>(Function<ValueUnOp<int, MinusUnOp<int> >>())),
    fintPlus(Ob::of<BaseMacro>(Function<ValueBinOp<int, PlusBinOp<int> >>())),
    fintMinus(Ob::of<BaseMacro>(Function<ValueBinOp<int, MinusBinOp<int> >>())),
    fintProduct(Ob::of<BaseMacro>(Function<ValueBinOp<int, ProductBinOp<int> >>())),
    fintDivision(Ob::of<BaseMacro>(Function<ValueBinOp<int, DivisionBinOp<int> >>())),
    fintMod(Ob::of<BaseMacro>(Function<ValueBinOp<int, ModBinOp<int> >>())),
    fintp(Ob::of<BaseMacro>(Function<TypePUnOp<Value<int>>>())),

    fintand(Ob::of<BaseMacro>(Function<ValueBinOp<int, BitAndBinOp<int> >>())),
    fintor(Ob::of<BaseMacro>(Function<ValueBinOp<int, BitOrBinOp<int> >>())),
    fintxor(Ob::of<BaseMacro>(Function<ValueBinOp<int, BitXorBinOp<int> >>())),
    fintnot(Ob::of<BaseMacro>(Function<ValueUnOp<int, BitNotUnOp<int> >>())),

    fintshl(Ob::of<BaseMacro>(Function<ValueBinOp<int, BitSHLBinOp<int> >>())),
    fintshr(Ob::of<BaseMacro>(Function<ValueBinOp<int, BitSHRBinOp<int> >>())),

    fintEql(Ob::of<BaseMacro>(Function<ValueCmpOp<int, EqlCmpOp<int> >>())),
    fintNE(Ob::of<BaseMacro>(Function<ValueCmpOp<int, NECmpOp<int> >>())),
    fintGT(Ob::of<BaseMacro>(Function<ValueCmpOp<int, GTCmpOp<int> >>())),
    fintLT(Ob::of<BaseMacro>(Function<ValueCmpOp<int, LTCmpOp<int> >>())),
    fintGE(Ob::of<BaseMacro>(Function<ValueCmpOp<int, GECmpOp<int> >>())),
    fintLE(Ob::of<BaseMacro>(Function<ValueCmpOp<int, LECmpOp<int> >>())),

    flongp(Ob::of<BaseMacro>(Function<TypePUnOp<Value<long long>>>())),
    flongand(Ob::of<BaseMacro>(Function<ValueBinOp<long long, BitAndBinOp<long long> >>())),
    flongor(Ob::of<BaseMacro>(Function<ValueBinOp<long long, BitOrBinOp<long long> >>())),
    flongxor(Ob::of<BaseMacro>(Function<ValueBinOp<long long, BitXorBinOp<long long> >>())),
    flongnot(Ob::of<BaseMacro>(Function<ValueUnOp<long long, BitNotUnOp<long long> >>())),

    flongshl(Ob::of<BaseMacro>(Function<ValueBinOp<long long, BitSHLBinOp<long long> >>())),
    flongshr(Ob::of<BaseMacro>(Function<ValueBinOp<long long, BitSHRBinOp<long long> >>())),

    flongEql(Ob::of<BaseMacro>(Function<ValueCmpOp<long long, EqlCmpOp<long long> >>())),
    flongNE(Ob::of<BaseMacro>(Function<ValueCmpOp<long long, NECmpOp<long long> >>())),
    flongGT(Ob::of<BaseMacro>(Function<ValueCmpOp<long long, LTCmpOp<long long> >>())),
    flongLT(Ob::of<BaseMacro>(Function<ValueCmpOp<long long, GTCmpOp<long long> >>())),
    flongGE(Ob::of<BaseMacro>(Function<ValueCmpOp<long long, LECmpOp<long long> >>())),
    flongLE(Ob::of<BaseMacro>(Function<ValueCmpOp<long long, GECmpOp<long long> >>())),

    ffloatNeg(Ob::of<BaseMacro>(Function<ValueUnOp<float, MinusUnOp<float> >>())),
    ffloatPlus(Ob::of<BaseMacro>(Function<ValueBinOp<float, PlusBinOp<float> >>())),
    ffloatMinus(Ob::of<BaseMacro>(Function<ValueBinOp<float, MinusBinOp<float> >>())),
    ffloatProduct(Ob::of<BaseMacro>(Function<ValueBinOp<float, ProductBinOp<float> >>())),
    ffloatDivision(Ob::of<BaseMacro>(Function<ValueBinOp<float, DivisionBinOp<float> >>())),
    ffloatp(Ob::of<BaseMacro>(Function<TypePUnOp<Value<float>>>())),
    ffloatEql(Ob::of<BaseMacro>(Function<ValueCmpOp<float, EqlCmpOp<float> >>())),
    ffloatNE(Ob::of<BaseMacro>(Function<ValueCmpOp<float, NECmpOp<float> >>())),
    ffloatGT(Ob::of<BaseMacro>(Function<ValueCmpOp<float, GTCmpOp<float> >>())),
    ffloatLT(Ob::of<BaseMacro>(Function<ValueCmpOp<float, LTCmpOp<float> >>())),
    ffloatGE(Ob::of<BaseMacro>(Function<ValueCmpOp<float, GECmpOp<float> >>())),
    ffloatLE(Ob::of<BaseMacro>(Function<ValueCmpOp<float, LECmpOp<float> >>())),

    fint2long(Ob::of<BaseMacro>(Function<ValueCastUnOp<int, long long>>())),
    flong2int(Ob::of<BaseMacro>(Function<ValueCastUnOp<long long, int>>())),

    ffloat2int(Ob::of<BaseMacro>(Function<ValueCastUnOp<float, int>>())),
    fint2float(Ob::of<BaseMacro>(Function<ValueCastUnOp<int, float>>())),

    fchar2int(Ob::of<BaseMacro>(Function<ValueCastUnOp<char, long long>>())),
    fint2char(Ob::of<BaseMacro>(Function<ValueCastUnOp<long long, char>>())),

    fchar2long(Ob::of<BaseMacro>(Function<ValueCastUnOp<char, int>>())),
    flong2char(Ob::of<BaseMacro>(Function<ValueCastUnOp<int, char>>())),

    fcharp(Ob::of<BaseMacro>(Function<TypePUnOp<Value<char>>>())),
    fcharand(Ob::of<BaseMacro>(Function<ValueBinOp<char, BitAndBinOp<char> >>())),
    fcharor(Ob::of<BaseMacro>(Function<ValueBinOp<char, BitOrBinOp<char> >>())),
    fcharxor(Ob::of<BaseMacro>(Function<ValueBinOp<char, BitXorBinOp<char> >>())),
    fcharnot(Ob::of<BaseMacro>(Function<ValueUnOp<char, BitNotUnOp<char> >>())),

    fcharshl(Ob::of<BaseMacro>(Function<ValueBinOp<char, BitSHLBinOp<char> >>())),
    fcharshr(Ob::of<BaseMacro>(Function<ValueBinOp<char, BitSHRBinOp<char> >>())),

    fcharEql(Ob::of<BaseMacro>(Function<ValueCmpOp<char, EqlCmpOp<char> >>())),
    fcharNE(Ob::of<BaseMacro>(Function<ValueCmpOp<char, NECmpOp<char> >>())),
    fcharGT(Ob::of<BaseMacro>(Function<ValueCmpOp<char, GTCmpOp<char> >>())),
    fcharLT(Ob::of<BaseMacro>(Function<ValueCmpOp<char, LTCmpOp<char> >>())),
    fcharGE(Ob::of<BaseMacro>(Function<ValueCmpOp<char, GECmpOp<char> >>())),
    fcharLE(Ob::of<BaseMacro>(Function<ValueCmpOp<char, LECmpOp<char> >>()))
{}

const BaseNumFunc &BaseNumFunc::inst()
{
    static const BaseNumFunc instance;
    return instance;
}

} // namespaces
