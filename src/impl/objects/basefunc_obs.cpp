#include <impl/objects/basefunc_obs.h>

#include <impl/operations/basefunc_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseFunctions::BaseFunctions() :
    fcar(new Ob(BaseMacro(FUnaryOp<CarUnOp>::apply))),
    fcdr(new Ob(BaseMacro(FUnaryOp<CdrUnOp>::apply))),
    fcons(new Ob(BaseMacro(FBinaryOp<ConsBinOp>::apply))),
    feq(new Ob(BaseMacro(FBinaryOp<EqBinOp>::apply))),
    fctxget(new Ob(BaseMacro(FBinaryOp<ContextGetBinOp>::apply))),
    fctxpush(new Ob(BaseMacro(FTernaryOp<ContextPushTerOp>::apply)))
{}

const BaseFunctions &BaseFunctions::inst()
{
    static const BaseFunctions instance;
    return instance;
}

} // namespaces
