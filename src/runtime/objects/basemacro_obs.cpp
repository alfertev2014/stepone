#include <objects/basemacro_obs.h>

#include <ptr_impl.h>
#include <builtin/basemacro.h>

namespace stepone::objects {

using namespace types;
using namespace builtin;

BaseMacroses::BaseMacroses() :
    aquote(Ptr::of<Symbol>()),
    aapply(Ptr::of<Symbol>()),
    aif(Ptr::of<Symbol>()),
    alet(Ptr::of<Symbol>()),
    amacro(Ptr::of<Symbol>()),
    atry(Ptr::of<Symbol>()),
    abot(Ptr::of<Symbol>()),
    agensym(Ptr::of<Symbol>())

{}

Ptr BaseMacroses::populateContext(const Ptr &a) const
{
    Ptr ctx = Context::make(aquote, Ptr::of<BuiltInMacro>(MQuote()), a);
    ctx = Context::make(aapply, Ptr::of<BuiltInMacro>(MApply()), ctx);
    ctx = Context::make(aif, Ptr::of<BuiltInMacro>(MIf()), ctx);
    ctx = Context::make(alet, Ptr::of<BuiltInMacro>(MLet()), ctx);
    ctx = Context::make(amacro, Ptr::of<BuiltInMacro>(MMacro()), ctx);
    ctx = Context::make(atry, Ptr::of<BuiltInMacro>(MTry()), ctx);
    ctx = Context::make(abot, Ptr::of<BuiltInMacro>(MBot()), ctx);
    ctx = Context::make(agensym, Ptr::of<BuiltInMacro>(MGenSymbol()), ctx);

    return ctx;
}

const BaseMacroses &BaseMacroses::inst()
{
    static const BaseMacroses instance;
    return instance;
}

} // namespaces
