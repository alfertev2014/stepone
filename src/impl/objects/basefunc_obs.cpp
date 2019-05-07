#include <impl/objects/basefunc_obs.h>

#include <impl/operations/basefunc_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseFunctions::BaseFunctions() :
    fcar(Ob::of<BaseMacro>(FUnaryOp<CarUnOp>::apply)),
    fcdr(Ob::of<BaseMacro>(FUnaryOp<CdrUnOp>::apply)),
    fcons(Ob::of<BaseMacro>(FBinaryOp<ConsBinOp>::apply)),
    feq(Ob::of<BaseMacro>(FBinaryOp<EqBinOp>::apply)),
    fctxget(Ob::of<BaseMacro>(FBinaryOp<ContextGetBinOp>::apply)),
    fctxpush(Ob::of<BaseMacro>(FTernaryOp<ContextPushTerOp>::apply))
{}

const BaseFunctions &BaseFunctions::inst()
{
    static const BaseFunctions instance;
    return instance;
}

} // namespaces
