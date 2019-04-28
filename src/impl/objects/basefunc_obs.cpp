#include <impl/objects/basefunc_obs.h>

#include <impl/operations/basefunc_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseFunctions::BaseFunctions() :
    fcar(new FUnaryOp<CarUnOp>),
    fcdr(new FUnaryOp<CdrUnOp>),
    fcons(new FBinaryOp<ConsBinOp>),
    feq(new FBinaryOp<EqBinOp>),
    fctxget(new FBinaryOp<ContextGetBinOp>),
    fctxpush(new FTernaryOp<ContextPushTerOp>)
{}

const BaseFunctions &BaseFunctions::inst()
{
    static const BaseFunctions instance;
    return instance;
}

} // namespaces
