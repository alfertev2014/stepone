#include <impl/core/ob.h>
#include <impl/ptr_impl.h>

namespace stepone::core {

Ptr Evaluator::eempty() {
    static Ptr e = Ob::of<Evaluator>(Ptr::anil());
    return e;
}

Ptr Evaluator::getContext() const {return a;}

Ptr Evaluator::apply(const Ptr &p, const Ptr &a) {return p.eval(a).eval(this->a);}

Ptr Evaluator::assoc(const Ptr &s) const {return s.eval(this->a);}


Ptr MacroClosure::apply(const Ptr &p, const Ptr &a) {
    return e.eval(Context::make(sp, p, this->a));
}

Ptr CurrentContext::apply(const Ptr &p, const Ptr &a) {
    return e.eval(Context::make(sa, Ob::of<Evaluator>(a), this->a)).apply(p, this->a);
}

} // namespaces
