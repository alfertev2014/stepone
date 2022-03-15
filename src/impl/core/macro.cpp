#include <core/ob.h>
#include <ptr_impl.h>

namespace stepone::core {

Ptr Evaluator::eempty() {
    static Ptr e = Ptr::of<Evaluator>(Ptr::anil());
    return e;
}

Ptr Evaluator::getContext() const {return a;}

Ptr Evaluator::apply(const Ptr &p, const Ptr &a) {return p.eval(a).eval(this->a);}

Ptr Evaluator::assoc(const Ptr &s) const {return Context::assoc(a, s);}

Ptr Evaluator::push(const Ptr &s, const Ptr &p) const {
    return Ptr::of<Evaluator>(Context::make(s, p, a));
}

Ptr MacroClosure::apply(const Ptr &p, const Ptr &a) {
    return e.eval(Context::make(sp, p, this->a));
}

Ptr CurrentContext::apply(const Ptr &p, const Ptr &a) {
    return e.eval(Context::make(sa, Ptr::of<Evaluator>(a), this->a)).apply(p, this->a);
}

} // namespaces
