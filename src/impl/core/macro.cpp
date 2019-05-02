#include <impl/core/macro.h>

namespace stepone::core {

const Ptr Evaluator::eempty(new Evaluator(Ptr::anil));

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
