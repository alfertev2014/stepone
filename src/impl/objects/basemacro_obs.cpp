#include <impl/objects/basemacro_obs.h>

#include <impl/core/ob.h>
#include <impl/base/basemacro.h>

namespace stepone::objects {

using namespace base;

BaseMacroses::BaseMacroses() :
    mquote(new Ob(BaseMacro(MQuote::apply))),
    mapply(new Ob(BaseMacro(MApply::apply))),
    mif(new Ob(BaseMacro(MIf::apply))),
    mlet(new Ob(BaseMacro(MLet::apply))),
    mlazy(new Ob(BaseMacro(MLazy::apply))),
    munlazy(new Ob(BaseMacro(MUnlazy::apply))),
    mlabel(new Ob(BaseMacro(MLabel::apply))),
    mmacro(new Ob(BaseMacro(MMacro::apply))),
    mcurctx(new Ob(BaseMacro(MCurrentContext::apply))),
    mtry(new Ob(BaseMacro(MTry::apply))),
    mbot(new Ob(BaseMacro(MBot::apply))),
    mgensym(new Ob(BaseMacro(MGenSymbol::apply)))
{}

const BaseMacroses &BaseMacroses::inst()
{
    static const BaseMacroses instance;
    return instance;
}

} // namespaces
