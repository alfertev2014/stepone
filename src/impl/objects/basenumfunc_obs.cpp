#include <impl/objects/basenumfunc_obs.h>

#include <impl/operations/cppoperators.h>
#include <impl/operations/value_operations.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseNumFunc::BaseNumFunc() :
    fintNeg(new Ob(BaseMacro(FUnaryOp<ValueUnOp<int, MinusUnOp<int> > >::apply))),
    fintPlus(new Ob(BaseMacro(FBinaryOp<ValueBinOp<int, PlusBinOp<int> > >::apply))),
    fintMinus(new Ob(BaseMacro(FBinaryOp<ValueBinOp<int, MinusBinOp<int> > >::apply))),
    fintProduct(new Ob(BaseMacro(FBinaryOp<ValueBinOp<int, ProductBinOp<int> > >::apply))),
    fintDivision(new Ob(BaseMacro(FBinaryOp<ValueBinOp<int, DivisionBinOp<int> > >::apply))),
    fintMod(new Ob(BaseMacro(FBinaryOp<ValueBinOp<int, ModBinOp<int> > >::apply))),
    fintp(new Ob(BaseMacro(FTypeP<Value<int> >::apply))),

    fintand(new Ob(BaseMacro(FBinaryOp<ValueBinOp<int, BitAndBinOp<int> > >::apply))),
    fintor(new Ob(BaseMacro(FBinaryOp<ValueBinOp<int, BitOrBinOp<int> > >::apply))),
    fintxor(new Ob(BaseMacro(FBinaryOp<ValueBinOp<int, BitXorBinOp<int> > >::apply))),
    fintnot(new Ob(BaseMacro(FUnaryOp<ValueUnOp<int, BitNotUnOp<int> > >::apply))),

    fintshl(new Ob(BaseMacro(FBinaryOp<ValueBinOp<int, BitSHLBinOp<int> > >::apply))),
    fintshr(new Ob(BaseMacro(FBinaryOp<ValueBinOp<int, BitSHRBinOp<int> > >::apply))),

    fintEql(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<int, EqlCmpOp<int> > >::apply))),
    fintNE(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<int, NECmpOp<int> > >::apply))),
    fintGT(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<int, GTCmpOp<int> > >::apply))),
    fintLT(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<int, LTCmpOp<int> > >::apply))),
    fintGE(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<int, GECmpOp<int> > >::apply))),
    fintLE(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<int, LECmpOp<int> > >::apply))),

    flongp(new Ob(BaseMacro(FTypeP<Value<long long> >::apply))),
    flongand(new Ob(BaseMacro(FBinaryOp<ValueBinOp<long long, BitAndBinOp<long long> > >::apply))),
    flongor(new Ob(BaseMacro(FBinaryOp<ValueBinOp<long long, BitOrBinOp<long long> > >::apply))),
    flongxor(new Ob(BaseMacro(FBinaryOp<ValueBinOp<long long, BitXorBinOp<long long> > >::apply))),
    flongnot(new Ob(BaseMacro(FUnaryOp<ValueUnOp<long long, BitNotUnOp<long long> > >::apply))),

    flongshl(new Ob(BaseMacro(FBinaryOp<ValueBinOp<long long, BitSHLBinOp<long long> > >::apply))),
    flongshr(new Ob(BaseMacro(FBinaryOp<ValueBinOp<long long, BitSHRBinOp<long long> > >::apply))),

    flongEql(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<long long, EqlCmpOp<long long> > >::apply))),
    flongNE(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<long long, NECmpOp<long long> > >::apply))),
    flongGT(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<long long, LTCmpOp<long long> > >::apply))),
    flongLT(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<long long, GTCmpOp<long long> > >::apply))),
    flongGE(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<long long, LECmpOp<long long> > >::apply))),
    flongLE(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<long long, GECmpOp<long long> > >::apply))),

    ffloatNeg(new Ob(BaseMacro(FUnaryOp<ValueUnOp<float, MinusUnOp<float> > >::apply))),
    ffloatPlus(new Ob(BaseMacro(FBinaryOp<ValueBinOp<float, PlusBinOp<float> > >::apply))),
    ffloatMinus(new Ob(BaseMacro(FBinaryOp<ValueBinOp<float, MinusBinOp<float> > >::apply))),
    ffloatProduct(new Ob(BaseMacro(FBinaryOp<ValueBinOp<float, ProductBinOp<float> > >::apply))),
    ffloatDivision(new Ob(BaseMacro(FBinaryOp<ValueBinOp<float, DivisionBinOp<float> > >::apply))),
    ffloatp(new Ob(BaseMacro(FTypeP<Value<float> >::apply))),
    ffloatEql(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<float, EqlCmpOp<float> > >::apply))),
    ffloatNE(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<float, NECmpOp<float> > >::apply))),
    ffloatGT(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<float, GTCmpOp<float> > >::apply))),
    ffloatLT(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<float, LTCmpOp<float> > >::apply))),
    ffloatGE(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<float, GECmpOp<float> > >::apply))),
    ffloatLE(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<float, LECmpOp<float> > >::apply))),

    fint2long(new Ob(BaseMacro(FUnaryOp<ValueCastUnOp<int, long long> >::apply))),
    flong2int(new Ob(BaseMacro(FUnaryOp<ValueCastUnOp<long long, int> >::apply))),

    ffloat2int(new Ob(BaseMacro(FUnaryOp<ValueCastUnOp<float, int> >::apply))),
    fint2float(new Ob(BaseMacro(FUnaryOp<ValueCastUnOp<int, float> >::apply))),

    fchar2int(new Ob(BaseMacro(FUnaryOp<ValueCastUnOp<char, long long> >::apply))),
    fint2char(new Ob(BaseMacro(FUnaryOp<ValueCastUnOp<long long, char> >::apply))),

    fchar2long(new Ob(BaseMacro(FUnaryOp<ValueCastUnOp<char, int> >::apply))),
    flong2char(new Ob(BaseMacro(FUnaryOp<ValueCastUnOp<int, char> >::apply))),

    fcharp(new Ob(BaseMacro(FTypeP<Value<char> >::apply))),
    fcharand(new Ob(BaseMacro(FBinaryOp<ValueBinOp<char, BitAndBinOp<char> > >::apply))),
    fcharor(new Ob(BaseMacro(FBinaryOp<ValueBinOp<char, BitOrBinOp<char> > >::apply))),
    fcharxor(new Ob(BaseMacro(FBinaryOp<ValueBinOp<char, BitXorBinOp<char> > >::apply))),
    fcharnot(new Ob(BaseMacro(FUnaryOp<ValueUnOp<char, BitNotUnOp<char> > >::apply))),

    fcharshl(new Ob(BaseMacro(FBinaryOp<ValueBinOp<char, BitSHLBinOp<char> > >::apply))),
    fcharshr(new Ob(BaseMacro(FBinaryOp<ValueBinOp<char, BitSHRBinOp<char> > >::apply))),

    fcharEql(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<char, EqlCmpOp<char> > >::apply))),
    fcharNE(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<char, NECmpOp<char> > >::apply))),
    fcharGT(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<char, GTCmpOp<char> > >::apply))),
    fcharLT(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<char, LTCmpOp<char> > >::apply))),
    fcharGE(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<char, GECmpOp<char> > >::apply))),
    fcharLE(new Ob(BaseMacro(FBinaryOp<ValueCmpOp<char, LECmpOp<char> > >::apply)))
{}

const BaseNumFunc &BaseNumFunc::inst()
{
    static const BaseNumFunc instance;
    return instance;
}

} // namespaces
