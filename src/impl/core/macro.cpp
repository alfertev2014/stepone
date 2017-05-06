#include <impl/core/macro.h>
#include <impl/core/type_info_inst.h>

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

const TypeInfoBase *Evaluator::getTypeInfo() const {return &TypeInfo<Evaluator>::instance;}

Ptr Evaluator::getContext() const {return a;}

Ptr Evaluator::apply(const Ptr &p, const Ptr &a) {return p.eval(a).eval(this->a);}

const TypeInfoBase *BaseMacro::getTypeInfo() const {return &TypeInfo<BaseMacro>::instance;}

BaseMacro::~BaseMacro(){}

const TypeInfoBase *Closure::getTypeInfo() const {return &TypeInfo<Closure>::instance;}

Ptr Closure::apply(const Ptr &p, const Ptr &a) {
    if(p == Ptr::anil)
        return this;
    return e.eval(Context::make(sp, p.car().eval(a), this->a)).apply(p.cdr(), a);
}

const TypeInfoBase *MacroClosure::getTypeInfo() const {return &TypeInfo<MacroClosure>::instance;}

Ptr MacroClosure::apply(const Ptr &p, const Ptr &a) {
    return e.eval(Context::make(sp, p, this->a));
}

const TypeInfoBase *CurrentContext::getTypeInfo() const {return &TypeInfo<CurrentContext>::instance;}

Ptr CurrentContext::apply(const Ptr &p, const Ptr &a) {
    return e.eval(Context::make(sa, new Evaluator(a), this->a)).apply(p, this->a);
}
