#include <objects/basefunc_obs.h>

#include <operations/basefunc_ops.h>
#include <base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseFunctions::BaseFunctions() :
    acar(Ob::of<Symbol>()),
    acdr(Ob::of<Symbol>()),
    acons(Ob::of<Symbol>()),
    aeq(Ob::of<Symbol>()),
    actxget(Ob::of<Symbol>()),
    actxpush(Ob::of<Symbol>()),

    aeempty(Ob::of<Symbol>())
{}

Ptr BaseFunctions::populateContext(const Ptr &a) const
{
    Ptr ctx = Context::make(acar, Ob::of<BaseMacro>(Function<CarUnOp>()), a);
    ctx = Context::make(acdr, Ob::of<BaseMacro>(Function<CdrUnOp>()), ctx);
    ctx = Context::make(acons, Ob::of<BaseMacro>(Function<ConsBinOp>()), ctx);
    ctx = Context::make(aeq, Ob::of<BaseMacro>(Function<EqBinOp>()), ctx);
    ctx = Context::make(actxget, Ob::of<BaseMacro>(Function<ContextGetBinOp>()), ctx);
    ctx = Context::make(actxpush, Ob::of<BaseMacro>(Function<ContextPushTerOp>()), ctx);
    ctx = Context::make(aeempty, core::Evaluator::eempty(), ctx);

    return ctx;
}

const BaseFunctions &BaseFunctions::inst()
{
    static const BaseFunctions instance;
    return instance;
}

} // namespaces
