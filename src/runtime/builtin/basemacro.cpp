#include <builtin/basemacro.h>
#include <error_exception.h>

#include <ptr_impl.h>

namespace stepone::builtin {

using namespace types;

Ptr MQuote::operator()(const Ptr &p, const Ptr &a) const {
    return p;
}

Ptr MApply::operator()(const Ptr &p, const Ptr &a) const {
    return p.car().eval(a).apply(p.cdr(), a);
}

Ptr MIf::operator()(const Ptr &p, const Ptr &a) const {
    if(p.car().eval(a) == Ptr::anil())
        return p.cdr().cdr().eval(a);
    else
        return p.cdr().car().eval(a);
}

Ptr MLet::operator()(const Ptr &p, const Ptr &a) const {
    Ptr val = p.cdr();
    return val.cdr().eval(Context::make(p.car(), val.car().eval(a), a));
}

Ptr MMacro::operator()(const Ptr &p, const Ptr &a) const {
    return Ptr::of<MacroClosure>(p.car(), p.cdr().car(), p.cdr().cdr(), a);
}

Ptr MTry::operator()(const Ptr &p, const Ptr &a) const {
    try {
        return p.car().eval(a);
    } catch(TypeError &e) {
        return p.cdr().eval(a);
    }
}

Ptr MBot::operator()(const Ptr &p, const Ptr &a) const {
    throw TypeError("Bottom");
}

Ptr MGenSymbol::operator()(const Ptr &p, const Ptr &a) const {
    return Ptr::of<Symbol>();
}

} // namespaces
