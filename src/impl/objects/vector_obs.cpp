#include <impl/objects/vector_obs.h>

#include <impl/core/ob.h>
#include <impl/operations/vector_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

VectorFunctions::VectorFunctions() :
    fvecp(new Ob(BaseMacro(FTypeP<Vector>::apply))),
    fmkvec(new Ob(BaseMacro(FMakeVector::apply))),
    fvecclone(new Ob(BaseMacro(FUnaryOp<VectorCloneUnOp>::apply))),
    fveclen(new Ob(BaseMacro(FUnaryOp<VectorLengthUnOp>::apply))),
    fvecmid(new Ob(BaseMacro(FTernaryOp<VectorMidTerOp>::apply))),
    fvecslice(new Ob(BaseMacro(FTernaryOp<VectorSliceTerOp>::apply))),
    fvecel(new Ob(BaseMacro(FBinaryOp<VectorElBinOp>::apply))),
    fveccat(new Ob(BaseMacro(FBinaryOp<VectorConcatBinOp>::apply)))
{}

const VectorFunctions &VectorFunctions::inst()
{
    static const VectorFunctions instance;
    return instance;
}

} // namespaces
