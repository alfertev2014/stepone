#include <impl/objects/vector_obs.h>

#include <impl/core/ob.h>
#include <impl/operations/vector_ops.h>
#include <impl/operations/typepredicates_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

VectorFunctions::VectorFunctions() :
    fvecp(Ob::of<BaseMacro>(Function<TypePUnOp<Vector>>())),
    fmkvec(Ob::of<BaseMacro>(Function<FMakeVector>())),
    fvecclone(Ob::of<BaseMacro>(Function<VectorCloneUnOp>())),
    fveclen(Ob::of<BaseMacro>(Function<VectorLengthUnOp>())),
    fvecmid(Ob::of<BaseMacro>(Function<VectorMidTerOp>())),
    fvecel(Ob::of<BaseMacro>(Function<VectorElBinOp>())),
    fveccat(Ob::of<BaseMacro>(Function<VectorConcatBinOp>()))
{}

const VectorFunctions &VectorFunctions::inst()
{
    static const VectorFunctions instance;
    return instance;
}

} // namespaces
