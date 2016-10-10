#include <macro.h>

const Ob::Ptr Evaluator::eempty(new Evaluator(Ob::anil));

Macro::~Macro() {}

const TypeInfoBase *Evaluator::getTypeInfo() const {return &TypeInfo<Evaluator>::instance;}

Ob::Ptr Evaluator::apply(const Ob::Ptr &p, const Ob::Ptr &a) {return p->eval(a)->eval(this->a);}

BaseMacro::~BaseMacro(){}

const TypeInfoBase *Closure::getTypeInfo() const {return &TypeInfo<Closure>::instance;}

Ob::Ptr Closure::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    if(p == Ob::anil)
        return this;
    return e->eval(Context::make(sp, p->car()->eval(a), this->a))->apply(p->cdr(), a);
}

const TypeInfoBase *MacroClosure::getTypeInfo() const {return &TypeInfo<MacroClosure>::instance;}

Ob::Ptr MacroClosure::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    return e->eval(Context::make(sp, p, this->a));
}

const TypeInfoBase *CurrentContext::getTypeInfo() const {return &TypeInfo<CurrentContext>::instance;}

Ob::Ptr CurrentContext::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    return e->eval(Context::make(sa, new Evaluator(a), this->a))->apply(p, this->a);
}
