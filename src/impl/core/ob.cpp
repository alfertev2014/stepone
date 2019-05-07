#include <ptr.h>
#include <impl/core/ob.h>
#include <error_exception.h>

namespace stepone {

const Ptr Ptr::anil(new core::Ob(core::Symbol()));
const Ptr Ptr::at(new core::Ob(core::Symbol()));

}

namespace stepone::core {

Ob::~Ob() {
    switch(typeFlags.typeTag) {
        case BaseTypeTag::Pair:
            payload.pair.~Pair();
            break;
        case BaseTypeTag::Symbol:
            payload.symbol.~Symbol();
            break;
        case BaseTypeTag::Lazy:
            payload.lazy.~Lazy();
            break;
        case BaseTypeTag::Label:
            payload.label.~Label();
            break;

        case BaseTypeTag::BaseMacro:
            payload.baseMacro.~BaseMacro();
            break;
        case BaseTypeTag::Evaluator:
            payload.evaluator.~Evaluator();
            break;
        case BaseTypeTag::MacroClosure:
            payload.macroClosure.~MacroClosure();
            break;
        case BaseTypeTag::CurrentContext:
            payload.currentContext.~CurrentContext();
            break;

        case BaseTypeTag::BaseValue:
            payload.baseValue.~BaseValue();
            break;
        case BaseTypeTag::ByteArray:
            payload.byteArray.~ByteArray();
            break;
        case BaseTypeTag::Vector:
            payload.vector.~Vector();
            break;

        case BaseTypeTag::Int:
            payload.valueInt.~Value<int>();
            break;
        case BaseTypeTag::Float:
            payload.valueFloat.~Value<float>();
            break;
        case BaseTypeTag::Char:
            payload.valueChar.~Value<char>();
            break;
        case BaseTypeTag::Long:
            payload.valueLong.~Value<long long>();
            break;
    }
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
                while(p != Ptr::anil) {
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
    if(p == Ptr::anil) return this;
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
