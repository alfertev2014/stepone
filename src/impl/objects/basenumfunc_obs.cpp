#include <impl/objects/basenumfunc_obs.h>

#include <impl/operations/cppoperators.h>
#include <impl/operations/value_operations.h>
#include <impl/base/operations.h>

namespace stepone { namespace objects {

using namespace base;
using namespace operations;

BaseNumFunc::BaseNumFunc() :
    fintNeg(new FUnaryOp<ValueUnOp<int, MinusUnOp<int> > >),
    fintPlus(new FBinaryOp<ValueBinOp<int, PlusBinOp<int> > >),
    fintMinus(new FBinaryOp<ValueBinOp<int, MinusBinOp<int> > >),
    fintProduct(new FBinaryOp<ValueBinOp<int, ProductBinOp<int> > >),
    fintDivision(new FBinaryOp<ValueBinOp<int, DivisionBinOp<int> > >),
    fintMod(new FBinaryOp<ValueBinOp<int, ModBinOp<int> > >),
    fintp(new FTypeP<Value<int> >),

    fintand(new FBinaryOp<ValueBinOp<int, BitAndBinOp<int> > >),
    fintor(new FBinaryOp<ValueBinOp<int, BitOrBinOp<int> > >),
    fintxor(new FBinaryOp<ValueBinOp<int, BitXorBinOp<int> > >),
    fintnot(new FUnaryOp<ValueUnOp<int, BitNotUnOp<int> > >),

    fintshl(new FBinaryOp<ValueBinOp<int, BitSHLBinOp<int> > >),
    fintshr(new FBinaryOp<ValueBinOp<int, BitSHRBinOp<int> > >),

    fintEql(new FBinaryOp<ValueCmpOp<int, EqlCmpOp<int> > >),
    fintNE(new FBinaryOp<ValueCmpOp<int, NECmpOp<int> > >),
    fintGT(new FBinaryOp<ValueCmpOp<int, GTCmpOp<int> > >),
    fintLT(new FBinaryOp<ValueCmpOp<int, LTCmpOp<int> > >),
    fintGE(new FBinaryOp<ValueCmpOp<int, GECmpOp<int> > >),
    fintLE(new FBinaryOp<ValueCmpOp<int, LECmpOp<int> > >),

    flongp(new FTypeP<Value<long long> >),
    flongand(new FBinaryOp<ValueBinOp<long long, BitAndBinOp<long long> > >),
    flongor(new FBinaryOp<ValueBinOp<long long, BitOrBinOp<long long> > >),
    flongxor(new FBinaryOp<ValueBinOp<long long, BitXorBinOp<long long> > >),
    flongnot(new FUnaryOp<ValueUnOp<long long, BitNotUnOp<long long> > >),

    flongshl(new FBinaryOp<ValueBinOp<long long, BitSHLBinOp<long long> > >),
    flongshr(new FBinaryOp<ValueBinOp<long long, BitSHRBinOp<long long> > >),

    flongEql(new FBinaryOp<ValueCmpOp<long long, EqlCmpOp<long long> > >),
    flongNE(new FBinaryOp<ValueCmpOp<long long, NECmpOp<long long> > >),
    flongGT(new FBinaryOp<ValueCmpOp<long long, LTCmpOp<long long> > >),
    flongLT(new FBinaryOp<ValueCmpOp<long long, GTCmpOp<long long> > >),
    flongGE(new FBinaryOp<ValueCmpOp<long long, LECmpOp<long long> > >),
    flongLE(new FBinaryOp<ValueCmpOp<long long, GECmpOp<long long> > >),

    ffloatNeg(new FUnaryOp<ValueUnOp<float, MinusUnOp<float> > >),
    ffloatPlus(new FBinaryOp<ValueBinOp<float, PlusBinOp<float> > >),
    ffloatMinus(new FBinaryOp<ValueBinOp<float, MinusBinOp<float> > >),
    ffloatProduct(new FBinaryOp<ValueBinOp<float, ProductBinOp<float> > >),
    ffloatDivision(new FBinaryOp<ValueBinOp<float, DivisionBinOp<float> > >),
    ffloatp(new FTypeP<Value<float> >),
    ffloatEql(new FBinaryOp<ValueCmpOp<float, EqlCmpOp<float> > >),
    ffloatNE(new FBinaryOp<ValueCmpOp<float, NECmpOp<float> > >),
    ffloatGT(new FBinaryOp<ValueCmpOp<float, GTCmpOp<float> > >),
    ffloatLT(new FBinaryOp<ValueCmpOp<float, LTCmpOp<float> > >),
    ffloatGE(new FBinaryOp<ValueCmpOp<float, GECmpOp<float> > >),
    ffloatLE(new FBinaryOp<ValueCmpOp<float, LECmpOp<float> > >),

    fint2long(new FUnaryOp<ValueCastUnOp<int, long long> >),
    flong2int(new FUnaryOp<ValueCastUnOp<long long, int> >),

    ffloat2int(new FUnaryOp<ValueCastUnOp<float, int> >),
    fint2float(new FUnaryOp<ValueCastUnOp<int, float> >),

    fchar2int(new FUnaryOp<ValueCastUnOp<char, long long> >),
    fint2char(new FUnaryOp<ValueCastUnOp<long long, char> >),

    fchar2long(new FUnaryOp<ValueCastUnOp<char, int> >),
    flong2char(new FUnaryOp<ValueCastUnOp<int, char> >),

    fcharp(new FTypeP<Value<char> >),
    fcharand(new FBinaryOp<ValueBinOp<char, BitAndBinOp<char> > >),
    fcharor(new FBinaryOp<ValueBinOp<char, BitOrBinOp<char> > >),
    fcharxor(new FBinaryOp<ValueBinOp<char, BitXorBinOp<char> > >),
    fcharnot(new FUnaryOp<ValueUnOp<char, BitNotUnOp<char> > >),

    fcharshl(new FBinaryOp<ValueBinOp<char, BitSHLBinOp<char> > >),
    fcharshr(new FBinaryOp<ValueBinOp<char, BitSHRBinOp<char> > >),

    fcharEql(new FBinaryOp<ValueCmpOp<char, EqlCmpOp<char> > >),
    fcharNE(new FBinaryOp<ValueCmpOp<char, NECmpOp<char> > >),
    fcharGT(new FBinaryOp<ValueCmpOp<char, GTCmpOp<char> > >),
    fcharLT(new FBinaryOp<ValueCmpOp<char, LTCmpOp<char> > >),
    fcharGE(new FBinaryOp<ValueCmpOp<char, GECmpOp<char> > >),
    fcharLE(new FBinaryOp<ValueCmpOp<char, LECmpOp<char> > >)
{}

const BaseNumFunc &BaseNumFunc::inst()
{
    static const BaseNumFunc instance;
    return instance;
}

}} // namespaces
