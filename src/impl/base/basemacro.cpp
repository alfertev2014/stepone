#include <impl/base/basemacro.h>
#include <error_exception.h>

#include <impl/core/ob.h>

namespace stepone::base {

using namespace core;

Ptr MQuote::apply(const Ptr &p, const Ptr &a) {
    return p;
}

Ptr MApply::apply(const Ptr &p, const Ptr &a) {
    return p.car().eval(a).apply(p.cdr(), a);
}

Ptr MIf::apply(const Ptr &p, const Ptr &a) {
    if(p.car().eval(a) == Ptr::anil)
        return p.cdr().cdr().eval(a);
    else
        return p.cdr().car().eval(a);
}

Ptr MLet::apply(const Ptr &p, const Ptr &a) {
    Ptr val = p.cdr();
    return val.cdr().eval(Context::make(p.car(), val.car().eval(a), a));
}

Ptr MLazy::apply(const Ptr &p, const Ptr &a) {
    return new Ob(Lazy(p, a));
}

Ptr MUnlazy::apply(const Ptr &p, const Ptr &a) {
    return p.eval(a).unlazy();
}

Ptr MLabel::apply(const Ptr &p, const Ptr &a) {
    return Label::loop(p.car(), p.cdr(), a);
}

Ptr MMacro::apply(const Ptr &p, const Ptr &a) {
    return new Ob(MacroClosure(p.car(), p.cdr(), a));
}

Ptr MCurrentContext::apply(const Ptr &p, const Ptr &a) {
    return new Ob(CurrentContext(p.car(), p.cdr(), a));
}

Ptr MTry::apply(const Ptr &p, const Ptr &a) {
    try {
        return p.car().eval(a);
    } catch(SemanticError e) {
        return p.cdr().eval(a);
    }
}

Ptr MBot::apply(const Ptr &p, const Ptr &a) {
    throw SemanticError("Bottom");
}

Ptr MGenSymbol::apply(const Ptr &p, const Ptr &a) {
    return new Ob(Symbol());
}

} // namespaces
