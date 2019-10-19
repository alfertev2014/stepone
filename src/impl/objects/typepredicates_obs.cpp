#include <impl/objects/typepredicates_obs.h>

#include <impl/operations/typepredicates_ops.h>
#include <impl/base/operations.h>
#include <impl/core/macro.h>
#include <impl/core/value.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseTypePredicates::BaseTypePredicates() :
    apairp(Ob::of<Symbol>()),
    alazyp(Ob::of<Symbol>()),
    alabelp(Ob::of<Symbol>()),
    aatomp(Ob::of<Symbol>()),
    asymbolp(Ob::of<Symbol>()),
    aconstp(Ob::of<Symbol>()),
    amacrop(Ob::of<Symbol>()),
    aevalp(Ob::of<Symbol>()),
    abasemacrop(Ob::of<Symbol>()),
    ausermacrop(Ob::of<Symbol>()),
    avaluep(Ob::of<Symbol>())
{}

Ptr BaseTypePredicates::populateContext(const Ptr &a) const
{
    Ptr ctx = Context::make(apairp, Ob::of<BaseMacro>(Function<TypePUnOp<Pair>>()), a);
    Context::make(alazyp, Ob::of<BaseMacro>(Function<TypePUnOp<Lazy>>()), ctx);
    Context::make(alabelp, Ob::of<BaseMacro>(Function<TypePUnOp<Lazy>>()), ctx);
    Context::make(aatomp, Ob::of<BaseMacro>(Function<TypePUnOp<Atom>>()), ctx);
    Context::make(asymbolp, Ob::of<BaseMacro>(Function<TypePUnOp<Symbol>>()), ctx);
    Context::make(aconstp, Ob::of<BaseMacro>(Function<TypePUnOp<Const>>()), ctx);
    Context::make(amacrop, Ob::of<BaseMacro>(Function<TypePUnOp<Macro>>()), ctx);
    Context::make(aevalp, Ob::of<BaseMacro>(Function<TypePUnOp<Evaluator>>()), ctx);
    Context::make(abasemacrop, Ob::of<BaseMacro>(Function<TypePUnOp<BaseMacro>>()), ctx);
    Context::make(ausermacrop, Ob::of<BaseMacro>(Function<TypePUnOp<MacroClosure>>()), ctx);
    Context::make(avaluep, Ob::of<BaseMacro>(Function<TypePUnOp<ValueBase>>()), ctx);

    return ctx;
}

const BaseTypePredicates &BaseTypePredicates::inst()
{
    static const BaseTypePredicates instance;
    return instance;
}

} // namespaces
