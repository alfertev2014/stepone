#include <objects/typepredicates_obs.h>

#include <operations/typepredicates_ops.h>
#include <base/operations.h>
#include <types/macro.h>
#include <types/value.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseTypePredicates::BaseTypePredicates() :
    apairp(Ptr::of<Symbol>()),
    alazyp(Ptr::of<Symbol>()),
    alabelp(Ptr::of<Symbol>()),
    aatomp(Ptr::of<Symbol>()),
    asymbolp(Ptr::of<Symbol>()),
    aconstp(Ptr::of<Symbol>()),
    amacrop(Ptr::of<Symbol>()),
    aevalp(Ptr::of<Symbol>()),
    abasemacrop(Ptr::of<Symbol>()),
    ausermacrop(Ptr::of<Symbol>()),
    avaluep(Ptr::of<Symbol>())
{}

Ptr BaseTypePredicates::populateContext(const Ptr &a) const
{
    Ptr ctx = Context::make(apairp, Ptr::of<BaseMacro>(Function<TypePUnOp<Pair>>()), a);
    ctx = Context::make(alazyp, Ptr::of<BaseMacro>(Function<TypePUnOp<Lazy>>()), ctx);
    ctx = Context::make(alabelp, Ptr::of<BaseMacro>(Function<TypePUnOp<Lazy>>()), ctx);
    ctx = Context::make(aatomp, Ptr::of<BaseMacro>(Function<TypePUnOp<Atom>>()), ctx);
    ctx = Context::make(asymbolp, Ptr::of<BaseMacro>(Function<TypePUnOp<Symbol>>()), ctx);
    ctx = Context::make(aconstp, Ptr::of<BaseMacro>(Function<TypePUnOp<Const>>()), ctx);
    ctx = Context::make(amacrop, Ptr::of<BaseMacro>(Function<TypePUnOp<Macro>>()), ctx);
    ctx = Context::make(aevalp, Ptr::of<BaseMacro>(Function<TypePUnOp<Evaluator>>()), ctx);
    ctx = Context::make(abasemacrop, Ptr::of<BaseMacro>(Function<TypePUnOp<BaseMacro>>()), ctx);
    ctx = Context::make(ausermacrop, Ptr::of<BaseMacro>(Function<TypePUnOp<MacroClosure>>()), ctx);
    ctx = Context::make(avaluep, Ptr::of<BaseMacro>(Function<TypePUnOp<ValueBase>>()), ctx);

    return ctx;
}

const BaseTypePredicates &BaseTypePredicates::inst()
{
    static const BaseTypePredicates instance;
    return instance;
}

} // namespaces
