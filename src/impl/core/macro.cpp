#include <impl/core/ob.h>

namespace stepone::core {

const Ptr Evaluator::eempty(new Ob(Evaluator(Ptr::anil)));

Ptr Evaluator::getContext() const {return a;}

Ptr Evaluator::apply(const Ptr &p, const Ptr &a) {return p.eval(a).eval(this->a);}

Ptr Evaluator::assoc(const Ptr &s) const {return s.eval(this->a);}


Ptr MacroClosure::apply(const Ptr &p, const Ptr &a) {
    return e.eval(Context::make(sp, p, this->a));
}

Ptr CurrentContext::apply(const Ptr &p, const Ptr &a) {
    return e.eval(Context::make(sa, new Ob(Evaluator(a)), this->a)).apply(p, this->a);
}

} // namespaces
