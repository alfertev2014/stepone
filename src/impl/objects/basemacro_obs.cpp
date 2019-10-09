#include <impl/objects/basemacro_obs.h>

#include <impl/core/ob.h>
#include <impl/base/basemacro.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;

BaseMacroses::BaseMacroses() :
    mquote(Ob::of<BaseMacro>(MQuote())),
    mapply(Ob::of<BaseMacro>(MApply())),
    mif(Ob::of<BaseMacro>(MIf())),
    mlet(Ob::of<BaseMacro>(MLet())),
    mlazy(Ob::of<BaseMacro>(MLazy())),
    munlazy(Ob::of<BaseMacro>(MUnlazy())),
    mlabel(Ob::of<BaseMacro>(MLabel())),
    mmacro(Ob::of<BaseMacro>(MMacro())),
    mcurctx(Ob::of<BaseMacro>(MCurrentContext())),
    mtry(Ob::of<BaseMacro>(MTry())),
    mbot(Ob::of<BaseMacro>(MBot())),
    mgensym(Ob::of<BaseMacro>(MGenSymbol()))
{}

const BaseMacroses &BaseMacroses::inst()
{
    static const BaseMacroses instance;
    return instance;
}

} // namespaces
