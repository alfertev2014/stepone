#include <impl/objects/vector_obs.h>

#include <impl/core/ob.h>
#include <impl/operations/vector_ops.h>
#include <impl/operations/typepredicates_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

VectorFunctions::VectorFunctions() :
    fvecp(Ob::of<BaseMacro>(Function(TypePUnOp<Vector>::op))),
    fmkvec(Ob::of<BaseMacro>(FMakeVector::apply)),
    fvecclone(Ob::of<BaseMacro>(Function(VectorCloneUnOp::op))),
    fveclen(Ob::of<BaseMacro>(Function(VectorLengthUnOp::op))),
    fvecmid(Ob::of<BaseMacro>(Function(VectorMidTerOp::op))),
    fvecel(Ob::of<BaseMacro>(Function(VectorElBinOp::op))),
    fveccat(Ob::of<BaseMacro>(Function(VectorConcatBinOp::op)))
{}

const VectorFunctions &VectorFunctions::inst()
{
    static const VectorFunctions instance;
    return instance;
}

} // namespaces
