#include <impl/objects/vector_obs.h>

#include <impl/core/ob.h>
#include <impl/operations/vector_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

VectorFunctions::VectorFunctions() :
    fvecp(Ob::of<BaseMacro>(FTypeP<Vector>::apply)),
    fmkvec(Ob::of<BaseMacro>(FMakeVector::apply)),
    fvecclone(Ob::of<BaseMacro>(FUnaryOp<VectorCloneUnOp>::apply)),
    fveclen(Ob::of<BaseMacro>(FUnaryOp<VectorLengthUnOp>::apply)),
    fvecmid(Ob::of<BaseMacro>(FTernaryOp<VectorMidTerOp>::apply)),
    fvecel(Ob::of<BaseMacro>(FBinaryOp<VectorElBinOp>::apply)),
    fveccat(Ob::of<BaseMacro>(FBinaryOp<VectorConcatBinOp>::apply))
{}

const VectorFunctions &VectorFunctions::inst()
{
    static const VectorFunctions instance;
    return instance;
}

} // namespaces
