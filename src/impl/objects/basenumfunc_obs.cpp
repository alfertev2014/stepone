#include <impl/objects/basenumfunc_obs.h>

#include <impl/operations/cppoperators.h>
#include <impl/operations/value_operations.h>
#include <impl/operations/typepredicates_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseNumFunc::BaseNumFunc() :
    fintNeg(Ob::of<BaseMacro>(Function(ValueUnOp<int, MinusUnOp<int> >::op))),
    fintPlus(Ob::of<BaseMacro>(Function(ValueBinOp<int, PlusBinOp<int> >::op))),
    fintMinus(Ob::of<BaseMacro>(Function(ValueBinOp<int, MinusBinOp<int> >::op))),
    fintProduct(Ob::of<BaseMacro>(Function(ValueBinOp<int, ProductBinOp<int> >::op))),
    fintDivision(Ob::of<BaseMacro>(Function(ValueBinOp<int, DivisionBinOp<int> >::op))),
    fintMod(Ob::of<BaseMacro>(Function(ValueBinOp<int, ModBinOp<int> >::op))),
    fintp(Ob::of<BaseMacro>(Function(TypePUnOp<Value<int>>::op))),

    fintand(Ob::of<BaseMacro>(Function(ValueBinOp<int, BitAndBinOp<int> >::op))),
    fintor(Ob::of<BaseMacro>(Function(ValueBinOp<int, BitOrBinOp<int> >::op))),
    fintxor(Ob::of<BaseMacro>(Function(ValueBinOp<int, BitXorBinOp<int> >::op))),
    fintnot(Ob::of<BaseMacro>(Function(ValueUnOp<int, BitNotUnOp<int> >::op))),

    fintshl(Ob::of<BaseMacro>(Function(ValueBinOp<int, BitSHLBinOp<int> >::op))),
    fintshr(Ob::of<BaseMacro>(Function(ValueBinOp<int, BitSHRBinOp<int> >::op))),

    fintEql(Ob::of<BaseMacro>(Function(ValueCmpOp<int, EqlCmpOp<int> >::op))),
    fintNE(Ob::of<BaseMacro>(Function(ValueCmpOp<int, NECmpOp<int> >::op))),
    fintGT(Ob::of<BaseMacro>(Function(ValueCmpOp<int, GTCmpOp<int> >::op))),
    fintLT(Ob::of<BaseMacro>(Function(ValueCmpOp<int, LTCmpOp<int> >::op))),
    fintGE(Ob::of<BaseMacro>(Function(ValueCmpOp<int, GECmpOp<int> >::op))),
    fintLE(Ob::of<BaseMacro>(Function(ValueCmpOp<int, LECmpOp<int> >::op))),

    flongp(Ob::of<BaseMacro>(Function(TypePUnOp<Value<long long>>::op))),
    flongand(Ob::of<BaseMacro>(Function(ValueBinOp<long long, BitAndBinOp<long long> >::op))),
    flongor(Ob::of<BaseMacro>(Function(ValueBinOp<long long, BitOrBinOp<long long> >::op))),
    flongxor(Ob::of<BaseMacro>(Function(ValueBinOp<long long, BitXorBinOp<long long> >::op))),
    flongnot(Ob::of<BaseMacro>(Function(ValueUnOp<long long, BitNotUnOp<long long> >::op))),

    flongshl(Ob::of<BaseMacro>(Function(ValueBinOp<long long, BitSHLBinOp<long long> >::op))),
    flongshr(Ob::of<BaseMacro>(Function(ValueBinOp<long long, BitSHRBinOp<long long> >::op))),

    flongEql(Ob::of<BaseMacro>(Function(ValueCmpOp<long long, EqlCmpOp<long long> >::op))),
    flongNE(Ob::of<BaseMacro>(Function(ValueCmpOp<long long, NECmpOp<long long> >::op))),
    flongGT(Ob::of<BaseMacro>(Function(ValueCmpOp<long long, LTCmpOp<long long> >::op))),
    flongLT(Ob::of<BaseMacro>(Function(ValueCmpOp<long long, GTCmpOp<long long> >::op))),
    flongGE(Ob::of<BaseMacro>(Function(ValueCmpOp<long long, LECmpOp<long long> >::op))),
    flongLE(Ob::of<BaseMacro>(Function(ValueCmpOp<long long, GECmpOp<long long> >::op))),

    ffloatNeg(Ob::of<BaseMacro>(Function(ValueUnOp<float, MinusUnOp<float> >::op))),
    ffloatPlus(Ob::of<BaseMacro>(Function(ValueBinOp<float, PlusBinOp<float> >::op))),
    ffloatMinus(Ob::of<BaseMacro>(Function(ValueBinOp<float, MinusBinOp<float> >::op))),
    ffloatProduct(Ob::of<BaseMacro>(Function(ValueBinOp<float, ProductBinOp<float> >::op))),
    ffloatDivision(Ob::of<BaseMacro>(Function(ValueBinOp<float, DivisionBinOp<float> >::op))),
    ffloatp(Ob::of<BaseMacro>(Function(TypePUnOp<Value<float>>::op))),
    ffloatEql(Ob::of<BaseMacro>(Function(ValueCmpOp<float, EqlCmpOp<float> >::op))),
    ffloatNE(Ob::of<BaseMacro>(Function(ValueCmpOp<float, NECmpOp<float> >::op))),
    ffloatGT(Ob::of<BaseMacro>(Function(ValueCmpOp<float, GTCmpOp<float> >::op))),
    ffloatLT(Ob::of<BaseMacro>(Function(ValueCmpOp<float, LTCmpOp<float> >::op))),
    ffloatGE(Ob::of<BaseMacro>(Function(ValueCmpOp<float, GECmpOp<float> >::op))),
    ffloatLE(Ob::of<BaseMacro>(Function(ValueCmpOp<float, LECmpOp<float> >::op))),

    fint2long(Ob::of<BaseMacro>(Function(ValueCastUnOp<int, long long>::op))),
    flong2int(Ob::of<BaseMacro>(Function(ValueCastUnOp<long long, int>::op))),

    ffloat2int(Ob::of<BaseMacro>(Function(ValueCastUnOp<float, int>::op))),
    fint2float(Ob::of<BaseMacro>(Function(ValueCastUnOp<int, float>::op))),

    fchar2int(Ob::of<BaseMacro>(Function(ValueCastUnOp<char, long long>::op))),
    fint2char(Ob::of<BaseMacro>(Function(ValueCastUnOp<long long, char>::op))),

    fchar2long(Ob::of<BaseMacro>(Function(ValueCastUnOp<char, int>::op))),
    flong2char(Ob::of<BaseMacro>(Function(ValueCastUnOp<int, char>::op))),

    fcharp(Ob::of<BaseMacro>(Function(TypePUnOp<Value<char>>::op))),
    fcharand(Ob::of<BaseMacro>(Function(ValueBinOp<char, BitAndBinOp<char> >::op))),
    fcharor(Ob::of<BaseMacro>(Function(ValueBinOp<char, BitOrBinOp<char> >::op))),
    fcharxor(Ob::of<BaseMacro>(Function(ValueBinOp<char, BitXorBinOp<char> >::op))),
    fcharnot(Ob::of<BaseMacro>(Function(ValueUnOp<char, BitNotUnOp<char> >::op))),

    fcharshl(Ob::of<BaseMacro>(Function(ValueBinOp<char, BitSHLBinOp<char> >::op))),
    fcharshr(Ob::of<BaseMacro>(Function(ValueBinOp<char, BitSHRBinOp<char> >::op))),

    fcharEql(Ob::of<BaseMacro>(Function(ValueCmpOp<char, EqlCmpOp<char> >::op))),
    fcharNE(Ob::of<BaseMacro>(Function(ValueCmpOp<char, NECmpOp<char> >::op))),
    fcharGT(Ob::of<BaseMacro>(Function(ValueCmpOp<char, GTCmpOp<char> >::op))),
    fcharLT(Ob::of<BaseMacro>(Function(ValueCmpOp<char, LTCmpOp<char> >::op))),
    fcharGE(Ob::of<BaseMacro>(Function(ValueCmpOp<char, GECmpOp<char> >::op))),
    fcharLE(Ob::of<BaseMacro>(Function(ValueCmpOp<char, LECmpOp<char> >::op)))
{}

const BaseNumFunc &BaseNumFunc::inst()
{
    static const BaseNumFunc instance;
    return instance;
}

} // namespaces
