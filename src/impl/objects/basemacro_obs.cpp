#include <impl/objects/basemacro_obs.h>

#include <impl/core/ob.h>
#include <impl/base/basemacro.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;

BaseMacroses::BaseMacroses() :
    mquote(Ob::of<BaseMacro>(Function<MQuote>())),
    mapply(Ob::of<BaseMacro>(Function<MApply>())),
    mif(Ob::of<BaseMacro>(Function<MIf>())),
    mlet(Ob::of<BaseMacro>(Function<MLet>())),
    mlazy(Ob::of<BaseMacro>(Function<MLazy>())),
    munlazy(Ob::of<BaseMacro>(Function<MUnlazy>())),
    mlabel(Ob::of<BaseMacro>(Function<MLabel>())),
    mmacro(Ob::of<BaseMacro>(Function<MMacro>())),
    mcurctx(Ob::of<BaseMacro>(Function<MCurrentContext>())),
    mtry(Ob::of<BaseMacro>(Function<MTry>())),
    mbot(Ob::of<BaseMacro>(Function<MBot>())),
    mgensym(Ob::of<BaseMacro>(Function<MGenSymbol>()))
{}

const BaseMacroses &BaseMacroses::inst()
{
    static const BaseMacroses instance;
    return instance;
}

} // namespaces
