#include "basenumfunc.h"
#include "cppoperators.h"
#include "operations.h"
#include "valuetype.h"

BaseNumFunc::BaseNumFunc() :
    fintNeg(new FUnaryOp<ValueTypeUnOp<int, MinusUnOp<int> > >),
    fintPlus(new FBinaryOp<ValueTypeBinOp<int, PlusBinOp<int> > >),
    fintMinus(new FBinaryOp<ValueTypeBinOp<int, MinusBinOp<int> > >),
    fintProduct(new FBinaryOp<ValueTypeBinOp<int, ProductBinOp<int> > >),
    fintDivision(new FBinaryOp<ValueTypeBinOp<int, DivisionBinOp<int> > >),
    fintMod(new FBinaryOp<ValueTypeBinOp<int, ModBinOp<int> > >),
    fintp(new FTypeP<ValueType<int> >),

    fintand(new FBinaryOp<ValueTypeBinOp<int, BitAndBinOp<int> > >),
    fintor(new FBinaryOp<ValueTypeBinOp<int, BitOrBinOp<int> > >),
    fintxor(new FBinaryOp<ValueTypeBinOp<int, BitXorBinOp<int> > >),
    fintnot(new FUnaryOp<ValueTypeUnOp<int, BitNotUnOp<int> > >),

    fintshl(new FBinaryOp<ValueTypeBinOp<int, BitSHLBinOp<int> > >),
    fintshr(new FBinaryOp<ValueTypeBinOp<int, BitSHRBinOp<int> > >),

    fintEql(new FBinaryOp<ValueTypeCmpOp<int, EqlCmpOp<int> > >),
    fintNE(new FBinaryOp<ValueTypeCmpOp<int, NECmpOp<int> > >),
    fintGT(new FBinaryOp<ValueTypeCmpOp<int, GTCmpOp<int> > >),
    fintLT(new FBinaryOp<ValueTypeCmpOp<int, LTCmpOp<int> > >),
    fintGE(new FBinaryOp<ValueTypeCmpOp<int, GECmpOp<int> > >),
    fintLE(new FBinaryOp<ValueTypeCmpOp<int, LECmpOp<int> > >),

    flongp(new FTypeP<ValueType<long long> >),
    flongand(new FBinaryOp<ValueTypeBinOp<long long, BitAndBinOp<long long> > >),
    flongor(new FBinaryOp<ValueTypeBinOp<long long, BitOrBinOp<long long> > >),
    flongxor(new FBinaryOp<ValueTypeBinOp<long long, BitXorBinOp<long long> > >),
    flongnot(new FUnaryOp<ValueTypeUnOp<long long, BitNotUnOp<long long> > >),

    flongshl(new FBinaryOp<ValueTypeBinOp<long long, BitSHLBinOp<long long> > >),
    flongshr(new FBinaryOp<ValueTypeBinOp<long long, BitSHRBinOp<long long> > >),

    flongEql(new FBinaryOp<ValueTypeCmpOp<long long, EqlCmpOp<long long> > >),
    flongNE(new FBinaryOp<ValueTypeCmpOp<long long, NECmpOp<long long> > >),
    flongGT(new FBinaryOp<ValueTypeCmpOp<long long, LTCmpOp<long long> > >),
    flongLT(new FBinaryOp<ValueTypeCmpOp<long long, GTCmpOp<long long> > >),
    flongGE(new FBinaryOp<ValueTypeCmpOp<long long, LECmpOp<long long> > >),
    flongLE(new FBinaryOp<ValueTypeCmpOp<long long, GECmpOp<long long> > >),

    ffloatNeg(new FUnaryOp<ValueTypeUnOp<float, MinusUnOp<float> > >),
    ffloatPlus(new FBinaryOp<ValueTypeBinOp<float, PlusBinOp<float> > >),
    ffloatMinus(new FBinaryOp<ValueTypeBinOp<float, MinusBinOp<float> > >),
    ffloatProduct(new FBinaryOp<ValueTypeBinOp<float, ProductBinOp<float> > >),
    ffloatDivision(new FBinaryOp<ValueTypeBinOp<float, DivisionBinOp<float> > >),
    ffloatp(new FTypeP<ValueType<float> >),
    ffloatEql(new FBinaryOp<ValueTypeCmpOp<float, EqlCmpOp<float> > >),
    ffloatNE(new FBinaryOp<ValueTypeCmpOp<float, NECmpOp<float> > >),
    ffloatGT(new FBinaryOp<ValueTypeCmpOp<float, GTCmpOp<float> > >),
    ffloatLT(new FBinaryOp<ValueTypeCmpOp<float, LTCmpOp<float> > >),
    ffloatGE(new FBinaryOp<ValueTypeCmpOp<float, GECmpOp<float> > >),
    ffloatLE(new FBinaryOp<ValueTypeCmpOp<float, LECmpOp<float> > >),

    fint2long(new FUnaryOp<ValueTypeCastUnOp<int, long long> >),
    flong2int(new FUnaryOp<ValueTypeCastUnOp<long long, int> >),

    ffloat2int(new FUnaryOp<ValueTypeCastUnOp<float, int> >),
    fint2float(new FUnaryOp<ValueTypeCastUnOp<int, float> >),

    fchar2int(new FUnaryOp<ValueTypeCastUnOp<char, long long> >),
    fint2char(new FUnaryOp<ValueTypeCastUnOp<long long, char> >),

    fchar2long(new FUnaryOp<ValueTypeCastUnOp<char, int> >),
    flong2char(new FUnaryOp<ValueTypeCastUnOp<int, char> >),

    fcharp(new FTypeP<ValueType<char> >),
    fcharand(new FBinaryOp<ValueTypeBinOp<char, BitAndBinOp<char> > >),
    fcharor(new FBinaryOp<ValueTypeBinOp<char, BitOrBinOp<char> > >),
    fcharxor(new FBinaryOp<ValueTypeBinOp<char, BitXorBinOp<char> > >),
    fcharnot(new FUnaryOp<ValueTypeUnOp<char, BitNotUnOp<char> > >),

    fcharshl(new FBinaryOp<ValueTypeBinOp<char, BitSHLBinOp<char> > >),
    fcharshr(new FBinaryOp<ValueTypeBinOp<char, BitSHRBinOp<char> > >),

    fcharEql(new FBinaryOp<ValueTypeCmpOp<char, EqlCmpOp<char> > >),
    fcharNE(new FBinaryOp<ValueTypeCmpOp<char, NECmpOp<char> > >),
    fcharGT(new FBinaryOp<ValueTypeCmpOp<char, GTCmpOp<char> > >),
    fcharLT(new FBinaryOp<ValueTypeCmpOp<char, LTCmpOp<char> > >),
    fcharGE(new FBinaryOp<ValueTypeCmpOp<char, GECmpOp<char> > >),
    fcharLE(new FBinaryOp<ValueTypeCmpOp<char, LECmpOp<char> > >)
{}

const BaseNumFunc &BaseNumFunc::inst()
{
    static const BaseNumFunc instance;
    return instance;
}

