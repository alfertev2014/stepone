#include "tuple.h"

const Ob::Ptr VectorFunctions::fvecp(new FTypeP<Vector>);
const Ob::Ptr VectorFunctions::fmkvec(new FMakeNaryOp<MakeVectorNaryOp>);
const Ob::Ptr VectorFunctions::fveclen(new FVectorLength);
const Ob::Ptr VectorFunctions::fvecel(new FBinaryOp<VectorElBinOp>);
const Ob::Ptr VectorFunctions::fveccat(new FBinaryOp<VectorConcatBinOp>);
