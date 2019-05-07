#include <impl/objects/basenumfunc_obs.h>

#include <impl/operations/cppoperators.h>
#include <impl/operations/value_operations.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseNumFunc::BaseNumFunc() :
    fintNeg(Ob::of<BaseMacro>(FUnaryOp<ValueUnOp<int, MinusUnOp<int> > >::apply)),
    fintPlus(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<int, PlusBinOp<int> > >::apply)),
    fintMinus(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<int, MinusBinOp<int> > >::apply)),
    fintProduct(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<int, ProductBinOp<int> > >::apply)),
    fintDivision(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<int, DivisionBinOp<int> > >::apply)),
    fintMod(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<int, ModBinOp<int> > >::apply)),
    fintp(Ob::of<BaseMacro>(FTypeP<Value<int> >::apply)),

    fintand(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<int, BitAndBinOp<int> > >::apply)),
    fintor(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<int, BitOrBinOp<int> > >::apply)),
    fintxor(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<int, BitXorBinOp<int> > >::apply)),
    fintnot(Ob::of<BaseMacro>(FUnaryOp<ValueUnOp<int, BitNotUnOp<int> > >::apply)),

    fintshl(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<int, BitSHLBinOp<int> > >::apply)),
    fintshr(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<int, BitSHRBinOp<int> > >::apply)),

    fintEql(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<int, EqlCmpOp<int> > >::apply)),
    fintNE(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<int, NECmpOp<int> > >::apply)),
    fintGT(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<int, GTCmpOp<int> > >::apply)),
    fintLT(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<int, LTCmpOp<int> > >::apply)),
    fintGE(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<int, GECmpOp<int> > >::apply)),
    fintLE(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<int, LECmpOp<int> > >::apply)),

    flongp(Ob::of<BaseMacro>(FTypeP<Value<long long> >::apply)),
    flongand(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<long long, BitAndBinOp<long long> > >::apply)),
    flongor(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<long long, BitOrBinOp<long long> > >::apply)),
    flongxor(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<long long, BitXorBinOp<long long> > >::apply)),
    flongnot(Ob::of<BaseMacro>(FUnaryOp<ValueUnOp<long long, BitNotUnOp<long long> > >::apply)),

    flongshl(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<long long, BitSHLBinOp<long long> > >::apply)),
    flongshr(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<long long, BitSHRBinOp<long long> > >::apply)),

    flongEql(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<long long, EqlCmpOp<long long> > >::apply)),
    flongNE(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<long long, NECmpOp<long long> > >::apply)),
    flongGT(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<long long, LTCmpOp<long long> > >::apply)),
    flongLT(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<long long, GTCmpOp<long long> > >::apply)),
    flongGE(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<long long, LECmpOp<long long> > >::apply)),
    flongLE(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<long long, GECmpOp<long long> > >::apply)),

    ffloatNeg(Ob::of<BaseMacro>(FUnaryOp<ValueUnOp<float, MinusUnOp<float> > >::apply)),
    ffloatPlus(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<float, PlusBinOp<float> > >::apply)),
    ffloatMinus(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<float, MinusBinOp<float> > >::apply)),
    ffloatProduct(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<float, ProductBinOp<float> > >::apply)),
    ffloatDivision(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<float, DivisionBinOp<float> > >::apply)),
    ffloatp(Ob::of<BaseMacro>(FTypeP<Value<float> >::apply)),
    ffloatEql(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<float, EqlCmpOp<float> > >::apply)),
    ffloatNE(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<float, NECmpOp<float> > >::apply)),
    ffloatGT(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<float, GTCmpOp<float> > >::apply)),
    ffloatLT(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<float, LTCmpOp<float> > >::apply)),
    ffloatGE(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<float, GECmpOp<float> > >::apply)),
    ffloatLE(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<float, LECmpOp<float> > >::apply)),

    fint2long(Ob::of<BaseMacro>(FUnaryOp<ValueCastUnOp<int, long long> >::apply)),
    flong2int(Ob::of<BaseMacro>(FUnaryOp<ValueCastUnOp<long long, int> >::apply)),

    ffloat2int(Ob::of<BaseMacro>(FUnaryOp<ValueCastUnOp<float, int> >::apply)),
    fint2float(Ob::of<BaseMacro>(FUnaryOp<ValueCastUnOp<int, float> >::apply)),

    fchar2int(Ob::of<BaseMacro>(FUnaryOp<ValueCastUnOp<char, long long> >::apply)),
    fint2char(Ob::of<BaseMacro>(FUnaryOp<ValueCastUnOp<long long, char> >::apply)),

    fchar2long(Ob::of<BaseMacro>(FUnaryOp<ValueCastUnOp<char, int> >::apply)),
    flong2char(Ob::of<BaseMacro>(FUnaryOp<ValueCastUnOp<int, char> >::apply)),

    fcharp(Ob::of<BaseMacro>(FTypeP<Value<char> >::apply)),
    fcharand(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<char, BitAndBinOp<char> > >::apply)),
    fcharor(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<char, BitOrBinOp<char> > >::apply)),
    fcharxor(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<char, BitXorBinOp<char> > >::apply)),
    fcharnot(Ob::of<BaseMacro>(FUnaryOp<ValueUnOp<char, BitNotUnOp<char> > >::apply)),

    fcharshl(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<char, BitSHLBinOp<char> > >::apply)),
    fcharshr(Ob::of<BaseMacro>(FBinaryOp<ValueBinOp<char, BitSHRBinOp<char> > >::apply)),

    fcharEql(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<char, EqlCmpOp<char> > >::apply)),
    fcharNE(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<char, NECmpOp<char> > >::apply)),
    fcharGT(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<char, GTCmpOp<char> > >::apply)),
    fcharLT(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<char, LTCmpOp<char> > >::apply)),
    fcharGE(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<char, GECmpOp<char> > >::apply)),
    fcharLE(Ob::of<BaseMacro>(FBinaryOp<ValueCmpOp<char, LECmpOp<char> > >::apply))
{}

const BaseNumFunc &BaseNumFunc::inst()
{
    static const BaseNumFunc instance;
    return instance;
}

} // namespaces
