#include "basenumfunc.h"
#include "cppoperators.h"
#include "operations.h"
#include "valuetype.h"

const Ob::Ptr BaseNumFunc::fintNeg(new FUnaryOp<ValueTypeUnOp<int, MinusUnOp<int> > >);
const Ob::Ptr BaseNumFunc::fintPlus(new FBinaryOp<ValueTypeBinOp<int, PlusBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fintMinus(new FBinaryOp<ValueTypeBinOp<int, MinusBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fintProduct(new FBinaryOp<ValueTypeBinOp<int, ProductBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fintDivision(new FBinaryOp<ValueTypeBinOp<int, DivisionBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fintMod(new FBinaryOp<ValueTypeBinOp<int, ModBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fintp(new FTypeP<ValueType<int> >);

const Ob::Ptr BaseNumFunc::fintand(new FBinaryOp<ValueTypeBinOp<int, BitAndBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fintor(new FBinaryOp<ValueTypeBinOp<int, BitOrBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fintxor(new FBinaryOp<ValueTypeBinOp<int, BitXorBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fintnot(new FUnaryOp<ValueTypeUnOp<int, BitNotUnOp<int> > >);

const Ob::Ptr BaseNumFunc::fintshl(new FBinaryOp<ValueTypeBinOp<int, BitSHLBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fintshr(new FBinaryOp<ValueTypeBinOp<int, BitSHRBinOp<int> > >);

const Ob::Ptr BaseNumFunc::fintEql(new FBinaryOp<ValueTypeCmpOp<int, EqlCmpOp<int> > >);
const Ob::Ptr BaseNumFunc::fintNE(new FBinaryOp<ValueTypeCmpOp<int, NECmpOp<int> > >);
const Ob::Ptr BaseNumFunc::fintGT(new FBinaryOp<ValueTypeCmpOp<int, LTCmpOp<int> > >);
const Ob::Ptr BaseNumFunc::fintLT(new FBinaryOp<ValueTypeCmpOp<int, GTCmpOp<int> > >);
const Ob::Ptr BaseNumFunc::fintGE(new FBinaryOp<ValueTypeCmpOp<int, LECmpOp<int> > >);
const Ob::Ptr BaseNumFunc::fintLE(new FBinaryOp<ValueTypeCmpOp<int, GECmpOp<int> > >);

const Ob::Ptr BaseNumFunc::flongp(new FTypeP<ValueType<long long> >);
const Ob::Ptr BaseNumFunc::flongand(new FBinaryOp<ValueTypeBinOp<long long, BitAndBinOp<long long> > >);
const Ob::Ptr BaseNumFunc::flongor(new FBinaryOp<ValueTypeBinOp<long long, BitOrBinOp<long long> > >);
const Ob::Ptr BaseNumFunc::flongxor(new FBinaryOp<ValueTypeBinOp<long long, BitXorBinOp<long long> > >);
const Ob::Ptr BaseNumFunc::flongnot(new FUnaryOp<ValueTypeUnOp<long long, BitNotUnOp<long long> > >);

const Ob::Ptr BaseNumFunc::flongshl(new FBinaryOp<ValueTypeBinOp<long long, BitSHLBinOp<long long> > >);
const Ob::Ptr BaseNumFunc::flongshr(new FBinaryOp<ValueTypeBinOp<long long, BitSHRBinOp<long long> > >);

const Ob::Ptr BaseNumFunc::flongEql(new FBinaryOp<ValueTypeCmpOp<long long, EqlCmpOp<long long> > >);
const Ob::Ptr BaseNumFunc::flongNE(new FBinaryOp<ValueTypeCmpOp<long long, NECmpOp<long long> > >);
const Ob::Ptr BaseNumFunc::flongGT(new FBinaryOp<ValueTypeCmpOp<long long, LTCmpOp<long long> > >);
const Ob::Ptr BaseNumFunc::flongLT(new FBinaryOp<ValueTypeCmpOp<long long, GTCmpOp<long long> > >);
const Ob::Ptr BaseNumFunc::flongGE(new FBinaryOp<ValueTypeCmpOp<long long, LECmpOp<long long> > >);
const Ob::Ptr BaseNumFunc::flongLE(new FBinaryOp<ValueTypeCmpOp<long long, GECmpOp<long long> > >);

const Ob::Ptr BaseNumFunc::ffloatNeg(new FUnaryOp<ValueTypeUnOp<float, MinusUnOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatPlus(new FBinaryOp<ValueTypeBinOp<float, PlusBinOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatMinus(new FBinaryOp<ValueTypeBinOp<float, MinusBinOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatProduct(new FBinaryOp<ValueTypeBinOp<float, ProductBinOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatDivision(new FBinaryOp<ValueTypeBinOp<float, DivisionBinOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatp(new FTypeP<ValueType<float> >);
const Ob::Ptr BaseNumFunc::ffloatEql(new FBinaryOp<ValueTypeCmpOp<float, EqlCmpOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatNE(new FBinaryOp<ValueTypeCmpOp<float, NECmpOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatGT(new FBinaryOp<ValueTypeCmpOp<float, GTCmpOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatLT(new FBinaryOp<ValueTypeCmpOp<float, LTCmpOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatGE(new FBinaryOp<ValueTypeCmpOp<float, GECmpOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatLE(new FBinaryOp<ValueTypeCmpOp<float, LECmpOp<float> > >);

const Ob::Ptr BaseNumFunc::fint2long(new FValueTypeCast<int, long long>);
const Ob::Ptr BaseNumFunc::flong2int(new FValueTypeCast<long long, int>);

const Ob::Ptr BaseNumFunc::ffloat2int(new FValueTypeCast<float, int>);
const Ob::Ptr BaseNumFunc::fint2float(new FValueTypeCast<int, float>);

const Ob::Ptr BaseNumFunc::fchar2int(new FValueTypeCast<char, long long>);
const Ob::Ptr BaseNumFunc::fint2char(new FValueTypeCast<long long, char>);

const Ob::Ptr BaseNumFunc::fchar2long(new FValueTypeCast<char, int>);
const Ob::Ptr BaseNumFunc::flong2char(new FValueTypeCast<int, char>);

const Ob::Ptr BaseNumFunc::fcharp(new FTypeP<ValueType<char> >);
const Ob::Ptr BaseNumFunc::fcharand(new FBinaryOp<ValueTypeBinOp<char, BitAndBinOp<char> > >);
const Ob::Ptr BaseNumFunc::fcharor(new FBinaryOp<ValueTypeBinOp<char, BitOrBinOp<char> > >);
const Ob::Ptr BaseNumFunc::fcharxor(new FBinaryOp<ValueTypeBinOp<char, BitXorBinOp<char> > >);
const Ob::Ptr BaseNumFunc::fcharnot(new FUnaryOp<ValueTypeUnOp<char, BitNotUnOp<char> > >);

const Ob::Ptr BaseNumFunc::fcharshl(new FBinaryOp<ValueTypeBinOp<char, BitSHLBinOp<char> > >);
const Ob::Ptr BaseNumFunc::fcharshr(new FBinaryOp<ValueTypeBinOp<char, BitSHRBinOp<char> > >);

const Ob::Ptr BaseNumFunc::fcharEql(new FBinaryOp<ValueTypeCmpOp<char, EqlCmpOp<char> > >);
const Ob::Ptr BaseNumFunc::fcharNE(new FBinaryOp<ValueTypeCmpOp<char, NECmpOp<char> > >);
const Ob::Ptr BaseNumFunc::fcharGT(new FBinaryOp<ValueTypeCmpOp<char, LTCmpOp<char> > >);
const Ob::Ptr BaseNumFunc::fcharLT(new FBinaryOp<ValueTypeCmpOp<char, GTCmpOp<char> > >);
const Ob::Ptr BaseNumFunc::fcharGE(new FBinaryOp<ValueTypeCmpOp<char, LECmpOp<char> > >);
const Ob::Ptr BaseNumFunc::fcharLE(new FBinaryOp<ValueTypeCmpOp<char, GECmpOp<char> > >);
