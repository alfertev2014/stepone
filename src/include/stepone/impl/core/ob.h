#pragma once

#include <ptr.h>
#include "type_flags.h"
#include "error_exception.h"

#include "core.h"
#include "macro.h"
#include "value.h"
#include "bytearray.h"
#include "vector.h"

namespace stepone::core {

class Ob {
    friend class ::stepone::Ptr;
    int refcount {0};

    const TypeFlags typeFlags {};
    union Payload {
        Pair pair;
        Lazy lazy;
        Label label;
        Symbol symbol;

        Evaluator evaluator;
        BaseMacro baseMacro;
        MacroClosure macroClosure;
        CurrentContext currentContext;

        BaseValue baseValue;
        ByteArray byteArray;
        Vector vector;
        Value<int> valueInt;
        Value<float> valueFloat;
        Value<char> valueChar;
        Value<long long> valueLong;

        Payload() {}
        ~Payload() {}
    } payload;

    template <typename T>
    T * unsafe_as() {return nullptr;}

    Ob(TypeFlags typeFlags) : typeFlags(typeFlags) {}
public:
    Ob() = delete;
    Ob(const Pair &pair) : Ob(BaseTypeTag::Pair) {
        new (&payload.pair) Pair(pair);
    }
    Ob(const Lazy &lazy) : Ob(BaseTypeTag::Lazy) {
        new (&payload.lazy) Lazy(lazy);
    }
    Ob(const Label &label) : Ob(BaseTypeTag::Label) {
        new (&payload.label) Label(label);
    }
    Ob(const Symbol &symbol) : Ob(BaseTypeTag::Symbol) {
        new (&payload.symbol) Symbol(symbol);
    }
    Ob(const Evaluator &evaluator) : Ob(BaseTypeTag::Evaluator) {
        new (&payload.evaluator) Evaluator(evaluator);
    }
    Ob(const BaseMacro &baseMacro) : Ob(BaseTypeTag::BaseMacro) {
        new (&payload.baseMacro) BaseMacro(baseMacro);
    }
    Ob(const MacroClosure &macroClosure) : Ob(BaseTypeTag::MacroClosure) {
        new (&payload.macroClosure) MacroClosure(macroClosure);
    }
    Ob(const CurrentContext &currentContext) : Ob(BaseTypeTag::CurrentContext) {
        new (&payload.currentContext) CurrentContext(currentContext);
    }
    Ob(const BaseValue &baseValue) : Ob(BaseTypeTag::BaseValue) {
        new (&payload.baseValue) BaseValue(baseValue);
    }
    Ob(const ByteArray &byteArray) : Ob(BaseTypeTag::ByteArray) {
        new (&payload.byteArray) ByteArray(byteArray);
    }
    Ob(const Vector &vector) : Ob(BaseTypeTag::Vector) {
        new (&payload.vector) Vector(vector);
    }
    Ob(const Value<int> &v) : Ob(BaseTypeTag::Int) {
        new (&payload.valueInt) Value<int>(v);
    }
    Ob(const Value<float> &v) : Ob(BaseTypeTag::Float) {
        new (&payload.valueFloat) Value<float>(v);
    }
    Ob(const Value<char> &v) : Ob(BaseTypeTag::Char) {
        new (&payload.valueChar) Value<char>(v);
    }
    Ob(const Value<long long> &v) : Ob(BaseTypeTag::Long) {
        new (&payload.valueLong) Value<long long>(v);
    }
    ~Ob() {
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

    Ptr car();
    Ptr cdr();

    Ptr eval(const Ptr & a);
    Ptr apply(const Ptr & p, const Ptr & a);
    Ptr unlazy();
    Ptr assoc(const Ptr & s) const;

    template <class T>
    T * as() {
        if(! is<T>())
            return nullptr;
        return unsafe_as<T>();
    }

    template <class T>
    bool is() const {
        return typeFlags.typeTag == TypeTagOf<T>::typeTagValue;
    }

    template <class T>
    T * cast() {
        T * res = as<T>();
        if (res == nullptr)
            throw SemanticError("error cast");
        return res;
    }
};


template <>
inline Pair *Ob::unsafe_as<Pair>() {
    return &payload.pair;
}

template <>
inline Lazy *Ob::unsafe_as<Lazy>() {
    return &payload.lazy;
}

template <>
inline Label *Ob::unsafe_as<Label>() {
    return &payload.label;
}

template <>
inline Symbol *Ob::unsafe_as<Symbol>() {
    return &payload.symbol;
}

template <>
inline Evaluator *Ob::unsafe_as<Evaluator>() {
    return &payload.evaluator;
}

template <>
inline BaseMacro *Ob::unsafe_as<BaseMacro>() {
    return &payload.baseMacro;
}

template <>
inline MacroClosure *Ob::unsafe_as<MacroClosure>() {
    return &payload.macroClosure;
}

template <>
inline CurrentContext *Ob::unsafe_as<CurrentContext>() {
    return &payload.currentContext;
}

template <>
inline BaseValue *Ob::unsafe_as<BaseValue>() {
    return &payload.baseValue;
}

template <>
inline ByteArray *Ob::unsafe_as<ByteArray>() {
    return &payload.byteArray;
}


template <>
struct TypeTagOf<Pair> : TypeTagValue<BaseTypeTag::Pair> {};

template <>
struct TypeTagOf<Lazy> : TypeTagValue<BaseTypeTag::Lazy> {};

template <>
struct TypeTagOf<Label> : TypeTagValue<BaseTypeTag::Label> {};

template <>
struct TypeTagOf<Symbol> : TypeTagValue<BaseTypeTag::Symbol> {};

template <>
struct TypeTagOf<Evaluator> : TypeTagValue<BaseTypeTag::Evaluator> {};

template <>
struct TypeTagOf<BaseMacro> : TypeTagValue<BaseTypeTag::BaseMacro> {};

template <>
struct TypeTagOf<MacroClosure> : TypeTagValue<BaseTypeTag::MacroClosure> {};

template <>
struct TypeTagOf<CurrentContext> : TypeTagValue<BaseTypeTag::CurrentContext> {};

template <>
struct TypeTagOf<BaseValue> : TypeTagValue<BaseTypeTag::BaseValue> {};

template <>
struct TypeTagOf<ByteArray> : TypeTagValue<BaseTypeTag::ByteArray> {};

template <>
struct TypeTagOf<Vector> : TypeTagValue<BaseTypeTag::Vector> {};

template <>
struct TypeTagOf<Value<int>> : TypeTagValue<BaseTypeTag::Int> {};

template <>
struct TypeTagOf<Value<float>> : TypeTagValue<BaseTypeTag::Float> {};

template <>
struct TypeTagOf<Value<char>> : TypeTagValue<BaseTypeTag::Char> {};

template <>
struct TypeTagOf<Value<long long>> : TypeTagValue<BaseTypeTag::Long> {};


template <>
inline bool Ob::is<Atom>() const {
    return typeFlags.typeTag != BaseTypeTag::Pair;
}

template <>
inline bool Ob::is<Const>() const {
    return static_cast<int>(typeFlags.typeTag) > static_cast<int>(BaseTypeTag::Label);
}

template <>
inline bool Ob::is<Macro>() const {
    return typeFlags.isMacro();
}

template<>
inline bool Ob::is<ValueBase>() const {
    return typeFlags.isValue();
}

} // namespaces
