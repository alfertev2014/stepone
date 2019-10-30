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
            action(const_unsafe_as<Pair>());
            break;
        case BaseTypeTag::Symbol:
            action(const_unsafe_as<Symbol>());
            break;
        case BaseTypeTag::Lazy:
            action(const_unsafe_as<Lazy>());
            break;
        case BaseTypeTag::Label:
            action(const_unsafe_as<Label>());
            break;

        case BaseTypeTag::BaseMacro:
            action(const_unsafe_as<BaseMacro>());
            break;
        case BaseTypeTag::Evaluator:
            action(const_unsafe_as<Evaluator>());
            break;
        case BaseTypeTag::MacroClosure:
            action(const_unsafe_as<MacroClosure>());
            break;
        case BaseTypeTag::CurrentContext:
            action(const_unsafe_as<CurrentContext>());
            break;

        case BaseTypeTag::ByteArray:
            action(const_unsafe_as<ByteArray>());
            break;
        case BaseTypeTag::Vector:
            action(const_unsafe_as<Vector>());
            break;

        case BaseTypeTag::Int:
            action(const_unsafe_as<Value<int>>());
            break;
        case BaseTypeTag::Float:
            action(const_unsafe_as<Value<float>>());
            break;
        case BaseTypeTag::Char:
            action(const_unsafe_as<Value<char>>());
            break;
        case BaseTypeTag::Long:
            action(const_unsafe_as<Value<long long>>());
            break;
    }
}

Ob::Ob(const Ob &ob) : Ob(TypeFlags{ob.typeFlags}) {
    ob.visit([this](const auto &p) {
        using T = typename std::decay<decltype(p)>::type;
        static_assert(sizeof(T) <= sizeOfPayload);
        new (payload) T(p);
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
            return unsafe_as<Pair>().eval(a);
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
            return unsafe_as<Lazy>().eval(a);
        case BaseTypeTag::Label:
            return unsafe_as<Label>().eval(a);

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
            return unsafe_as<Lazy>().apply(p, a);
        case BaseTypeTag::Label:
            return unsafe_as<Label>().apply(p, a);

        case BaseTypeTag::BaseMacro:
            return unsafe_as<BaseMacro>().apply(p, a);
        case BaseTypeTag::Evaluator:
            return unsafe_as<Evaluator>().apply(p, a);
        case BaseTypeTag::MacroClosure:
            return unsafe_as<MacroClosure>().apply(p, a);
        case BaseTypeTag::CurrentContext:
            return unsafe_as<CurrentContext>().apply(p, a);

        default:
            throw SemanticError("apply of not applyable");
    }
}

Ptr Ob::unlazy() {
    switch(typeFlags.typeTag) {
        case BaseTypeTag::Lazy:
            return unsafe_as<Lazy>().unlazy();
        case BaseTypeTag::Label:
            return unsafe_as<Label>().unlazy();
        default:
            return this;
    }
}

Ptr Ob::assoc(const Ptr& s) const {
    if (typeFlags.typeTag != BaseTypeTag::Evaluator)
        throw SemanticError("throw assoc ");
    return const_unsafe_as<Evaluator>().assoc(s);
}

} // namespaces
