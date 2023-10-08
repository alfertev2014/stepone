
#include <ptr_impl.h>

namespace stepone::types {

Ptr Pair::car() {return pcar;}

Ptr Pair::cdr() {return pcdr;}

Ptr Pair::eval(const Ptr &context) {return pcar.eval(context).apply(pcdr, context);}

Ptr Context::make(const Ptr & symbol, const Ptr & value, const Ptr & next) {
    return Ptr::of<Pair>(Ptr::of<Pair>(symbol, value), next);
}

Ptr Context::assoc(const Ptr & context, const Ptr & symbol) {
    Ptr p = context;
    while (p != Ptr::anil()) {
        Ptr pair = p.car();
        if(pair.car() == symbol)
            return pair.cdr();
        p = p.cdr();
    }
    throw SemanticError("assoc");
}

inline void Lazy::ev() {
    if(!(context == Ptr::anil())) {
        expression = expression.eval(context);
        context = Ptr::anil();
    }
}

inline void Lazy::evw() {
    ev();
    Lazy * l = expression.as<Lazy>();
    while(l != 0) {
        l->ev();
        expression = l->expression;
        l = expression.as<Lazy>();
    }
}

Ptr Lazy::car() {evw(); return expression.car();}

Ptr Lazy::cdr() {evw(); return expression.cdr();}

Ptr Lazy::eval(const Ptr &a) {evw(); return expression.eval(a);}

Ptr Lazy::apply(const Ptr &p, const Ptr &a) {
    evw(); return expression.apply(p, a);
}

Ptr Lazy::unlazy() {evw(); return expression;}

inline Ptr Loop::ptr() {
    if(pa) {
        return v.eval(*pa);
    }
    return v;
}

Ptr Loop::loop(const Ptr &f, const Ptr &e, const Ptr &a) {
    Ptr lbl = Ptr::of<Loop>(e, &a);
    Loop &l = lbl.cast<Loop>();
    Ptr res = e.eval(Context::make(f, lbl, a));
    l.v = res;
    l.pa = 0;
    return res;
}



Ptr Loop::car() {return ptr().car();}

Ptr Loop::cdr() {return ptr().cdr();}

Ptr Loop::eval(const Ptr &a) {return ptr().eval(a);}

Ptr Loop::apply(const Ptr &p, const Ptr &a) {return ptr().apply(p, a);}

Ptr Loop::unlazy() {return ptr().unlazy();}


} // namespaces
