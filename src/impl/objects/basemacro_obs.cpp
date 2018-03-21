#include <impl/objects/basemacro_obs.h>

#include <impl/base/basemacro.h>

namespace stepone { namespace objects {

using namespace base;

BaseMacroses::BaseMacroses() :
    mquote(new MQuote()),
    mapply(new MApply()),
    mif(new MIf()),
    mlet(new MLet()),
    mlazy(new MLazy()),
    munlazy(new MUnlazy()),
    mlabel(new MLabel()),
    mlambda(new MLambda()),
    mmacro(new MMacro()),
    mcurctx(new MCurrentContext()),
    mtry(new MTry()),
    mbot(new MBot()),
    mgensym(new MGenSymbol())
{}

const BaseMacroses &BaseMacroses::inst()
{
    static const BaseMacroses instance;
    return instance;
}

}} // namespaces
