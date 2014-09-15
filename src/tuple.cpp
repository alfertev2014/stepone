#include "tuple.h"

const Ob::Ptr VectorFunctions::fvecp(new FTypeP<Vector>);
const Ob::Ptr VectorFunctions::fmkvec(new FMakeVector);
const Ob::Ptr VectorFunctions::fveclen(new FVectorLength);
const Ob::Ptr VectorFunctions::fvecmid(new FTernaryOp<VectorMidTerOp>);
const Ob::Ptr VectorFunctions::fvecel(new FBinaryOp<VectorElBinOp>);
const Ob::Ptr VectorFunctions::fveccat(new FBinaryOp<VectorConcatBinOp>);
