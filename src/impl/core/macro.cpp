#include <impl/core/macro.h>

namespace stepone::core {

const Ptr Evaluator::eempty(new Evaluator(Ptr::anil));

template<>
Macro *Ob::as<Macro>() {return typeFlags.constType == TypeFlags::Macro ? dynamic_cast<Macro*>(this) : 0;}

template<>
Evaluator *Ob::as<Evaluator>() {return typeFlags.macroValueType == TypeFlags::Evaluator ? dynamic_cast<Evaluator*>(this) : 0;}

template<>
BaseMacro *Ob::as<BaseMacro>() {return typeFlags.macroValueType == TypeFlags::BaseMacro ? dynamic_cast<BaseMacro*>(this) : 0;}

template<>
MacroClosure *Ob::as<MacroClosure>() {return typeFlags.macroValueType == TypeFlags::MacroClosure ? dynamic_cast<MacroClosure*>(this) : 0;}

template<>
CurrentContext *Ob::as<CurrentContext>() {return typeFlags.macroValueType == TypeFlags::CurrentContext ? dynamic_cast<CurrentContext*>(this) : 0;}

Macro::~Macro() {}

Ptr Evaluator::getContext() const {return a;}

Ptr Evaluator::apply(const Ptr &p, const Ptr &a) {return p.eval(a).eval(this->a);}

BaseMacro::~BaseMacro(){}

Ptr Closure::apply(const Ptr &p, const Ptr &a) {
    if(p == Ptr::anil)
        return this;
    return e.eval(Context::make(sp, p.car().eval(a), this->a)).apply(p.cdr(), a);
}

Ptr MacroClosure::apply(const Ptr &p, const Ptr &a) {
    return e.eval(Context::make(sp, p, this->a));
}

Ptr CurrentContext::apply(const Ptr &p, const Ptr &a) {
    return e.eval(Context::make(sa, new Evaluator(a), this->a)).apply(p, this->a);
}

} // namespaces
