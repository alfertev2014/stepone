#include "basenumfunc.h"
#include "numfunctemp.h"

const Ob::Ptr BaseNumFunc::fintPlus(new FBinaryOp<int, PlusBinOp<int> >);
const Ob::Ptr BaseNumFunc::fintMinus(new FBinaryOp<int, MinusBinOp<int> >);
const Ob::Ptr BaseNumFunc::fintProduct(new FBinaryOp<int, ProductBinOp<int> >);
const Ob::Ptr BaseNumFunc::fintDivision(new FBinaryOp<int, DivisionBinOp<int> >);
const Ob::Ptr BaseNumFunc::fintMod(new FBinaryOp<int, ModBinOp<int> >);
const Ob::Ptr BaseNumFunc::fintp(new FSpecTypeP<int>);
const Ob::Ptr BaseNumFunc::fintEql(new FCompareOp<int, EqlCmpOp<int> >);
const Ob::Ptr BaseNumFunc::fintNE(new FCompareOp<int, NECmpOp<int> >);
const Ob::Ptr BaseNumFunc::fintGT(new FCompareOp<int, LTCmpOp<int> >);
const Ob::Ptr BaseNumFunc::fintLT(new FCompareOp<int, GTCmpOp<int> >);
const Ob::Ptr BaseNumFunc::fintGE(new FCompareOp<int, LECmpOp<int> >);
const Ob::Ptr BaseNumFunc::fintLE(new FCompareOp<int, GECmpOp<int> >);

const Ob::Ptr BaseNumFunc::ffloatPlus(new FBinaryOp<float, PlusBinOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatMinus(new FBinaryOp<float, MinusBinOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatProduct(new FBinaryOp<float, ProductBinOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatDivision(new FBinaryOp<float, DivisionBinOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatp(new FSpecTypeP<float>);
const Ob::Ptr BaseNumFunc::ffloatEql(new FCompareOp<float, EqlCmpOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatNE(new FCompareOp<float, NECmpOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatGT(new FCompareOp<float, GTCmpOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatLT(new FCompareOp<float, LTCmpOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatGE(new FCompareOp<float, GECmpOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatLE(new FCompareOp<float, LECmpOp<float> >);

const Ob::Ptr BaseNumFunc::ffloat2int(new FSpecTypeCast<float, int>);
const Ob::Ptr BaseNumFunc::fint2float(new FSpecTypeCast<int, float>);
