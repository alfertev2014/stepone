#include <objects/basemacro_obs.h>

#include <core/ob.h>
#include <base/basemacro.h>
#include <base/operations.h>

namespace stepone::objects {

using namespace base;

BaseMacroses::BaseMacroses() :
    aquote(Ob::of<Symbol>()),
    aapply(Ob::of<Symbol>()),
    aif(Ob::of<Symbol>()),
    alet(Ob::of<Symbol>()),
    alazy(Ob::of<Symbol>()),
    aunlazy(Ob::of<Symbol>()),
    alabel(Ob::of<Symbol>()),
    alambda(Ob::of<Symbol>()),
    amacro(Ob::of<Symbol>()),
    acurctx(Ob::of<Symbol>()),
    atry(Ob::of<Symbol>()),
    abot(Ob::of<Symbol>()),
    agensym(Ob::of<Symbol>())

{}

Ptr BaseMacroses::populateContext(const Ptr &a) const
{
    Ptr ctx = Context::make(aquote, Ob::of<BaseMacro>(MQuote()), a);
    ctx = Context::make(aapply, Ob::of<BaseMacro>(MApply()), ctx);
    ctx = Context::make(aif, Ob::of<BaseMacro>(MIf()), ctx);
    ctx = Context::make(alet, Ob::of<BaseMacro>(MLet()), ctx);
    ctx = Context::make(alazy, Ob::of<BaseMacro>(MLazy()), ctx);
    ctx = Context::make(aunlazy, Ob::of<BaseMacro>(MUnlazy()), ctx);
    ctx = Context::make(alabel, Ob::of<BaseMacro>(MLabel()), ctx);
    ctx = Context::make(amacro, Ob::of<BaseMacro>(MMacro()), ctx);
    ctx = Context::make(acurctx, Ob::of<BaseMacro>(MCurrentContext()), ctx);
    ctx = Context::make(atry, Ob::of<BaseMacro>(MTry()), ctx);
    ctx = Context::make(abot, Ob::of<BaseMacro>(MBot()), ctx);
    ctx = Context::make(agensym, Ob::of<BaseMacro>(MGenSymbol()), ctx);

    return ctx;
}

const BaseMacroses &BaseMacroses::inst()
{
    static const BaseMacroses instance;
    return instance;
}

} // namespaces
