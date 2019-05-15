#include <impl/objects/basefunc_obs.h>

#include <impl/operations/basefunc_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseFunctions::BaseFunctions() :
    fcar(Ob::of<BaseMacro>(Function(CarUnOp::op))),
    fcdr(Ob::of<BaseMacro>(Function(CdrUnOp::op))),
    fcons(Ob::of<BaseMacro>(Function(ConsBinOp::op))),
    feq(Ob::of<BaseMacro>(Function(EqBinOp::op))),
    fctxget(Ob::of<BaseMacro>(Function(ContextGetBinOp::op))),
    fctxpush(Ob::of<BaseMacro>(Function(ContextPushTerOp::op)))
{}

const BaseFunctions &BaseFunctions::inst()
{
    static const BaseFunctions instance;
    return instance;
}

} // namespaces
