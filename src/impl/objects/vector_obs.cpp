#include <impl/objects/vector_obs.h>

#include <impl/core/ob.h>
#include <impl/operations/vector_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

VectorFunctions::VectorFunctions() :
    fvecp(new Ob(FTypeP<Vector>::apply)),
    fmkvec(new Ob(FMakeVector::apply)),
    fvecclone(new Ob(FUnaryOp<VectorCloneUnOp>::apply)),
    fveclen(new Ob(FUnaryOp<VectorLengthUnOp>::apply)),
    fvecmid(new Ob(FTernaryOp<VectorMidTerOp>::apply)),
    fvecslice(new Ob(FTernaryOp<VectorSliceTerOp>::apply)),
    fvecel(new Ob(FBinaryOp<VectorElBinOp>::apply)),
    fveccat(new Ob(FBinaryOp<VectorConcatBinOp>::apply))
{}

const VectorFunctions &VectorFunctions::inst()
{
    static const VectorFunctions instance;
    return instance;
}

} // namespaces
