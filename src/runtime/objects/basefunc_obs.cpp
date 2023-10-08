#include <objects/basefunc_obs.h>

#include <operations/basefunc_ops.h>
#include <builtin/operations.h>

namespace stepone::objects {

using namespace builtin;
using namespace operations;

BaseFunctions::BaseFunctions() :
    acar(Ptr::of<Symbol>()),
    acdr(Ptr::of<Symbol>()),
    acons(Ptr::of<Symbol>()),
    aeq(Ptr::of<Symbol>()),
    actxget(Ptr::of<Symbol>()),
    actxpush(Ptr::of<Symbol>()),

    aeempty(Ptr::of<Symbol>())
{}

Ptr BaseFunctions::populateContext(const Ptr &a) const
{
    Ptr ctx = Context::make(acar, Ptr::of<BaseMacro>(Function<CarUnOp>()), a);
    ctx = Context::make(acdr, Ptr::of<BaseMacro>(Function<CdrUnOp>()), ctx);
    ctx = Context::make(acons, Ptr::of<BaseMacro>(Function<ConsBinOp>()), ctx);
    ctx = Context::make(aeq, Ptr::of<BaseMacro>(Function<EqBinOp>()), ctx);
    ctx = Context::make(actxget, Ptr::of<BaseMacro>(Function<ContextGetBinOp>()), ctx);
    ctx = Context::make(actxpush, Ptr::of<BaseMacro>(Function<ContextPushTerOp>()), ctx);
    ctx = Context::make(aeempty, types::Evaluator::eempty(), ctx);

    return ctx;
}

const BaseFunctions &BaseFunctions::inst()
{
    static const BaseFunctions instance;
    return instance;
}

} // namespaces
