#include <objects/typepredicates_obs.h>

#include <operations/typepredicates_ops.h>
#include <builtin/operations.h>
#include <types/macro.h>
#include <types/value.h>

namespace stepone::objects {

using namespace builtin;
using namespace operations;

BaseTypePredicates::BaseTypePredicates() :
    apairp(Ptr::of<Symbol>()),
    aatomp(Ptr::of<Symbol>()),
    asymbolp(Ptr::of<Symbol>()),
    aconstp(Ptr::of<Symbol>()),
    amacrop(Ptr::of<Symbol>()),
    aevalp(Ptr::of<Symbol>()),
    abuiltinmacrop(Ptr::of<Symbol>()),
    amacroclosurep(Ptr::of<Symbol>()),
    avaluep(Ptr::of<Symbol>())
{}

Ptr BaseTypePredicates::populateContext(const Ptr &a) const
{
    Ptr ctx = Context::make(apairp, Ptr::of<BuiltInMacro>(Function<TypePUnOp<Pair>>()), a);
    ctx = Context::make(aatomp, Ptr::of<BuiltInMacro>(Function<TypePUnOp<Atom>>()), ctx);
    ctx = Context::make(asymbolp, Ptr::of<BuiltInMacro>(Function<TypePUnOp<Symbol>>()), ctx);
    ctx = Context::make(aconstp, Ptr::of<BuiltInMacro>(Function<TypePUnOp<Const>>()), ctx);
    ctx = Context::make(amacrop, Ptr::of<BuiltInMacro>(Function<TypePUnOp<Macro>>()), ctx);
    ctx = Context::make(aevalp, Ptr::of<BuiltInMacro>(Function<TypePUnOp<Evaluator>>()), ctx);
    ctx = Context::make(abuiltinmacrop, Ptr::of<BuiltInMacro>(Function<TypePUnOp<BuiltInMacro>>()), ctx);
    ctx = Context::make(amacroclosurep, Ptr::of<BuiltInMacro>(Function<TypePUnOp<MacroClosure>>()), ctx);
    ctx = Context::make(avaluep, Ptr::of<BuiltInMacro>(Function<TypePUnOp<ValueBase>>()), ctx);

    return ctx;
}

const BaseTypePredicates &BaseTypePredicates::inst()
{
    static const BaseTypePredicates instance;
    return instance;
}

} // namespaces
