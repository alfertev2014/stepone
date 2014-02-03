#include "basenumfunc.h"
#include "numfunctemp.h"
#include "funcstemp.h"
#include "typestemp.h"

const Ob::Ptr BaseNumFunc::fintNeg(new FNeg<int>);
const Ob::Ptr BaseNumFunc::fintPlus(new FBinaryOp<SpecTypeBinOp<int, PlusBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fintMinus(new FBinaryOp<SpecTypeBinOp<int, MinusBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fintProduct(new FBinaryOp<SpecTypeBinOp<int, ProductBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fintDivision(new FBinaryOp<SpecTypeBinOp<int, DivisionBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fintMod(new FBinaryOp<SpecTypeBinOp<int, ModBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fintp(new FTypeP<SpecTypeTemp<int> >);

const Ob::Ptr BaseNumFunc::fbitand(new FBinaryOp<SpecTypeBinOp<int, BitAndBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fbitor(new FBinaryOp<SpecTypeBinOp<int, BitOrBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fbitxor(new FBinaryOp<SpecTypeBinOp<int, BitXorBinOp<int> > >);
const Ob::Ptr BaseNumFunc::fbitnot(new FBitNot<int>);

const Ob::Ptr BaseNumFunc::fintEql(new FBinaryOp<SpecTypeCmpOp<int, EqlCmpOp<int> > >);
const Ob::Ptr BaseNumFunc::fintNE(new FBinaryOp<SpecTypeCmpOp<int, NECmpOp<int> > >);
const Ob::Ptr BaseNumFunc::fintGT(new FBinaryOp<SpecTypeCmpOp<int, LTCmpOp<int> > >);
const Ob::Ptr BaseNumFunc::fintLT(new FBinaryOp<SpecTypeCmpOp<int, GTCmpOp<int> > >);
const Ob::Ptr BaseNumFunc::fintGE(new FBinaryOp<SpecTypeCmpOp<int, LECmpOp<int> > >);
const Ob::Ptr BaseNumFunc::fintLE(new FBinaryOp<SpecTypeCmpOp<int, GECmpOp<int> > >);


const Ob::Ptr BaseNumFunc::ffloatNeg(new FNeg<float>);
const Ob::Ptr BaseNumFunc::ffloatPlus(new FBinaryOp<SpecTypeBinOp<float, PlusBinOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatMinus(new FBinaryOp<SpecTypeBinOp<float, MinusBinOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatProduct(new FBinaryOp<SpecTypeBinOp<float, ProductBinOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatDivision(new FBinaryOp<SpecTypeBinOp<float, DivisionBinOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatp(new FTypeP<SpecTypeTemp<float> >);
const Ob::Ptr BaseNumFunc::ffloatEql(new FBinaryOp<SpecTypeCmpOp<float, EqlCmpOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatNE(new FBinaryOp<SpecTypeCmpOp<float, NECmpOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatGT(new FBinaryOp<SpecTypeCmpOp<float, GTCmpOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatLT(new FBinaryOp<SpecTypeCmpOp<float, LTCmpOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatGE(new FBinaryOp<SpecTypeCmpOp<float, GECmpOp<float> > >);
const Ob::Ptr BaseNumFunc::ffloatLE(new FBinaryOp<SpecTypeCmpOp<float, LECmpOp<float> > >);

const Ob::Ptr BaseNumFunc::ffloat2int(new FSpecTypeCast<float, int>);
const Ob::Ptr BaseNumFunc::fint2float(new FSpecTypeCast<int, float>);
