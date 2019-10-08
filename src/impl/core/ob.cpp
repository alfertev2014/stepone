#include <ptr.h>
#include <impl/core/ob.h>
#include <error_exception.h>

#include <type_traits>

namespace stepone {

const Ptr Ptr::anil() {
    static const Ptr p = new core::Ob(core::Symbol());
    return p;
}

const Ptr Ptr::at() {
    static const Ptr p = new core::Ob(core::Symbol());
    return p;
}

}

namespace stepone::core {

template <class Action>
void Ob::visit(Action action) const {
    switch(typeFlags.typeTag) {
        case BaseTypeTag::Pair:
            action(payload.pair);
            break;
        case BaseTypeTag::Symbol:
            action(payload.symbol);
            break;
        case BaseTypeTag::Lazy:
            action(payload.lazy);
            break;
        case BaseTypeTag::Label:
            action(payload.label);
            break;

        case BaseTypeTag::BaseMacro:
            action(payload.baseMacro);
            break;
        case BaseTypeTag::Evaluator:
            action(payload.evaluator);
            break;
        case BaseTypeTag::MacroClosure:
            action(payload.macroClosure);
            break;
        case BaseTypeTag::CurrentContext:
            action(payload.currentContext);
            break;

        case BaseTypeTag::BaseValue:
            action(payload.baseValue);
            break;
        case BaseTypeTag::ByteArray:
            action(payload.byteArray);
            break;
        case BaseTypeTag::Vector:
            action(payload.vector);
            break;

        case BaseTypeTag::Int:
            action(payload.valueInt);
            break;
        case BaseTypeTag::Float:
            action(payload.valueFloat);
            break;
        case BaseTypeTag::Char:
            action(payload.valueChar);
            break;
        case BaseTypeTag::Long:
            action(payload.valueLong);
            break;
    }
}

Ob::Ob(const Ob &ob) : Ob(TypeFlags{ob.typeFlags}) {
    ob.visit([this](const auto &p) {
        using T = typename std::decay<decltype(p)>::type;
        new (&unsafe_as<T>()) T(p);
    });
}

Ob::~Ob() {
    visit([](const auto &p) {
        using T = typename std::decay<decltype(p)>::type;
        p.~T();
    });
}


Ptr Ob::car() {
    return as<Pair>()->car();
}

Ptr Ob::cdr() {
    return as<Pair>()->cdr();
}

Ptr Ob::eval(const Ptr &a) {
    switch(typeFlags.typeTag) {
        case BaseTypeTag::Pair:
            return payload.pair.eval(a);
        case BaseTypeTag::Symbol:
            {
                Ptr p = a;
                while(p != Ptr::anil()) {
                    Ptr pair = p.car();
                    if(pair.car() == this)
                        return pair.cdr();
                    p = p.cdr();
                }
                throw SemanticError("Unknown symbol");
            }
        case BaseTypeTag::Lazy:
            return payload.lazy.eval(a);
        case BaseTypeTag::Label:
            return payload.label.eval(a);

        case BaseTypeTag::BaseMacro:
        case BaseTypeTag::Evaluator:
        case BaseTypeTag::MacroClosure:
        case BaseTypeTag::CurrentContext:

        case BaseTypeTag::BaseValue:
        case BaseTypeTag::ByteArray:
        case BaseTypeTag::Vector:
        case BaseTypeTag::Int:
        case BaseTypeTag::Float:
        case BaseTypeTag::Char:
        case BaseTypeTag::Long:
            return this;

        default:
            throw SemanticError("eval");
    }
}

Ptr Ob::apply(const Ptr &p, const Ptr &a) {
    if(p == Ptr::anil()) return this;
    switch(typeFlags.typeTag) {
        case BaseTypeTag::Lazy:
            return payload.lazy.apply(p, a);
        case BaseTypeTag::Label:
            return payload.label.apply(p, a);

        case BaseTypeTag::BaseMacro:
            return payload.baseMacro.apply(p, a);
        case BaseTypeTag::Evaluator:
            return payload.evaluator.apply(p, a);
        case BaseTypeTag::MacroClosure:
            return payload.macroClosure.apply(p, a);
        case BaseTypeTag::CurrentContext:
            return payload.currentContext.apply(p, a);

        default:
            throw SemanticError("apply of not applyable");
    }
}

Ptr Ob::unlazy() {
    switch(typeFlags.typeTag) {
        case BaseTypeTag::Lazy:
            return payload.lazy.unlazy();
        case BaseTypeTag::Label:
            return payload.label.unlazy();
        default:
            return this;
    }
}

Ptr Ob::assoc(const Ptr& s) const {
    if (typeFlags.typeTag != BaseTypeTag::Evaluator)
        throw SemanticError("throw assoc ");
    return payload.evaluator.assoc(s);
}

} // namespaces
