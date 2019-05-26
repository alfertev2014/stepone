#include <impl/objects/basefunc_obs.h>

#include <impl/operations/basefunc_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseFunctions::BaseFunctions() :
    fcar(Ob::of<BaseMacro>(Function<CarUnOp>())),
    fcdr(Ob::of<BaseMacro>(Function<CdrUnOp>())),
    fcons(Ob::of<BaseMacro>(Function<ConsBinOp>())),
    feq(Ob::of<BaseMacro>(Function<EqBinOp>())),
    fctxget(Ob::of<BaseMacro>(Function<ContextGetBinOp>())),
    fctxpush(Ob::of<BaseMacro>(Function<ContextPushTerOp>()))
{}

const BaseFunctions &BaseFunctions::inst()
{
    static const BaseFunctions instance;
    return instance;
}

} // namespaces
