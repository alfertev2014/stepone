#include <impl/objects/basemacro_obs.h>

#include <impl/core/ob.h>
#include <impl/base/basemacro.h>

namespace stepone::objects {

using namespace base;

BaseMacroses::BaseMacroses() :
    mquote(Ob::of<BaseMacro>(MQuote::apply)),
    mapply(Ob::of<BaseMacro>(MApply::apply)),
    mif(Ob::of<BaseMacro>(MIf::apply)),
    mlet(Ob::of<BaseMacro>(MLet::apply)),
    mlazy(Ob::of<BaseMacro>(MLazy::apply)),
    munlazy(Ob::of<BaseMacro>(MUnlazy::apply)),
    mlabel(Ob::of<BaseMacro>(MLabel::apply)),
    mmacro(Ob::of<BaseMacro>(MMacro::apply)),
    mcurctx(Ob::of<BaseMacro>(MCurrentContext::apply)),
    mtry(Ob::of<BaseMacro>(MTry::apply)),
    mbot(Ob::of<BaseMacro>(MBot::apply)),
    mgensym(Ob::of<BaseMacro>(MGenSymbol::apply))
{}

const BaseMacroses &BaseMacroses::inst()
{
    static const BaseMacroses instance;
    return instance;
}

} // namespaces
