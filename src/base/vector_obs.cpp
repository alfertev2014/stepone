#include "vector_obs.h"
#include "vector_ops.h"

#include <operations.h>

VectorFunctions::VectorFunctions() :
    fvecp(new FTypeP<Vector>),
    fmkvec(new FMakeVector),
    fvecclone(new FUnaryOp<VectorCloneUnOp>),
    fveclen(new FUnaryOp<VectorLengthUnOp>),
    fvecmid(new FTernaryOp<VectorMidTerOp>),
    fvecslice(new FTernaryOp<VectorSliceTerOp>),
    fvecel(new FBinaryOp<VectorElBinOp>),
    fveccat(new FBinaryOp<VectorConcatBinOp>)
{}

const VectorFunctions &VectorFunctions::inst()
{
    static const VectorFunctions instance;
    return instance;
}
