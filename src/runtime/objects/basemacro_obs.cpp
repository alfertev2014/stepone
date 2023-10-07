#include <objects/basemacro_obs.h>

#include <ob.h>
#include <base/basemacro.h>
#include <base/operations.h>

namespace stepone::objects {

using namespace base;

BaseMacroses::BaseMacroses() :
    aquote(Ptr::of<Symbol>()),
    aapply(Ptr::of<Symbol>()),
    aif(Ptr::of<Symbol>()),
    alet(Ptr::of<Symbol>()),
    alazy(Ptr::of<Symbol>()),
    aunlazy(Ptr::of<Symbol>()),
    alabel(Ptr::of<Symbol>()),
    alambda(Ptr::of<Symbol>()),
    amacro(Ptr::of<Symbol>()),
    acurctx(Ptr::of<Symbol>()),
    atry(Ptr::of<Symbol>()),
    abot(Ptr::of<Symbol>()),
    agensym(Ptr::of<Symbol>())

{}

Ptr BaseMacroses::populateContext(const Ptr &a) const
{
    Ptr ctx = Context::make(aquote, Ptr::of<BaseMacro>(MQuote()), a);
    ctx = Context::make(aapply, Ptr::of<BaseMacro>(MApply()), ctx);
    ctx = Context::make(aif, Ptr::of<BaseMacro>(MIf()), ctx);
    ctx = Context::make(alet, Ptr::of<BaseMacro>(MLet()), ctx);
    ctx = Context::make(alazy, Ptr::of<BaseMacro>(MLazy()), ctx);
    ctx = Context::make(aunlazy, Ptr::of<BaseMacro>(MUnlazy()), ctx);
    ctx = Context::make(alabel, Ptr::of<BaseMacro>(MLabel()), ctx);
    ctx = Context::make(amacro, Ptr::of<BaseMacro>(MMacro()), ctx);
    ctx = Context::make(acurctx, Ptr::of<BaseMacro>(MCurrentContext()), ctx);
    ctx = Context::make(atry, Ptr::of<BaseMacro>(MTry()), ctx);
    ctx = Context::make(abot, Ptr::of<BaseMacro>(MBot()), ctx);
    ctx = Context::make(agensym, Ptr::of<BaseMacro>(MGenSymbol()), ctx);

    return ctx;
}

const BaseMacroses &BaseMacroses::inst()
{
    static const BaseMacroses instance;
    return instance;
}

} // namespaces
