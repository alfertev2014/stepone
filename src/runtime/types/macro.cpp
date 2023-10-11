
#include <ptr_impl.h>

namespace stepone::types {

Ptr Evaluator::eempty() {
    static Ptr e = Ptr::of<Evaluator>(Ptr::anil());
    return e;
}

Ptr Evaluator::apply(const Ptr &argument, const Ptr &context) const {return argument.eval(context).eval(this->context);}

Ptr Evaluator::assoc(const Ptr &symbol) const {return Context::assoc(context, symbol);}

Ptr Evaluator::push(const Ptr &symbol, const Ptr &value) const {
    return Ptr::of<Evaluator>(Context::make(symbol, value, context));
}

Ptr MacroClosure::apply(const Ptr &argument, const Ptr &context) const {
    return bodyExpression.eval(Context::make(argumentSymbol, argument, this->creationContext));
}

} // namespaces
