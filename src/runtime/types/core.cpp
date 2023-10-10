
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

} // namespaces
