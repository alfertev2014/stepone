
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

} // namespaces
