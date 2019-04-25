#include <impl/objects/vector_obs.h>

#include <impl/operations/vector_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

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

} // namespaces
