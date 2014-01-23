#include "basenumfunc.h"
#include "numfunctemp.h"
#include "numbers.h"

const Ob::Ptr BaseNumFunc::fintPlus(new FIntBinOp<PlusBinOp<int> >);
const Ob::Ptr BaseNumFunc::fintMinus(new FIntBinOp<MinusBinOp<int> >);
const Ob::Ptr BaseNumFunc::fintProduct(new FIntBinOp<ProductBinOp<int> >);
const Ob::Ptr BaseNumFunc::fintDivision(new FIntBinOp<DivisionBinOp<int> >);
const Ob::Ptr BaseNumFunc::fintMod(new FIntBinOp<ModBinOp<int> >);
const Ob::Ptr BaseNumFunc::fintp(new FIntP);
const Ob::Ptr BaseNumFunc::fintEql(new FIntCmpOp<EqlCmpOp<int> >);
const Ob::Ptr BaseNumFunc::fintNE(new FIntCmpOp<NECmpOp<int> >);
const Ob::Ptr BaseNumFunc::fintGT(new FIntCmpOp<LTCmpOp<int> >);
const Ob::Ptr BaseNumFunc::fintLT(new FIntCmpOp<GTCmpOp<int> >);
const Ob::Ptr BaseNumFunc::fintGE(new FIntCmpOp<LECmpOp<int> >);
const Ob::Ptr BaseNumFunc::fintLE(new FIntCmpOp<GECmpOp<int> >);

const Ob::Ptr BaseNumFunc::ffloatPlus(new FFloatBinOp<PlusBinOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatMinus(new FFloatBinOp<MinusBinOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatProduct(new FFloatBinOp<ProductBinOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatDivision(new FFloatBinOp<DivisionBinOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatp(new FFloatP);
const Ob::Ptr BaseNumFunc::ffloatEql(new FFloatCmpOp<EqlCmpOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatNE(new FFloatCmpOp<NECmpOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatGT(new FFloatCmpOp<GTCmpOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatLT(new FFloatCmpOp<LTCmpOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatGE(new FFloatCmpOp<GECmpOp<float> >);
const Ob::Ptr BaseNumFunc::ffloatLE(new FFloatCmpOp<LECmpOp<float> >);

const Ob::Ptr BaseNumFunc::ffloat2int(new FFloatToInt);
const Ob::Ptr BaseNumFunc::fint2float(new FIntToFloat);
