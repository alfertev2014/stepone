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
    T * unsafe_as();

    Ob(TypeFlags typeFlags) : typeFlags(typeFlags) {}

    template <class T>
    Ob(const T &t);
public:
    Ob() = delete;
    ~Ob();


    template <class T, class ...Args>
    static Ptr of(Args&&... args);

    Ptr car();
    Ptr cdr();

    Ptr eval(const Ptr & a);
    Ptr apply(const Ptr & p, const Ptr & a);
    Ptr unlazy();
    Ptr assoc(const Ptr & s) const;

    template <class T>
    T * as();

    template <class T>
    bool is() const {
        return typeFlags.typeTag == TypeTagOf<T>::typeTagValue;
    }

    template <class T>
    T * cast();
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
inline Vector *Ob::unsafe_as<Vector>() {
    return &payload.vector;
}

template <>
inline Value<int> *Ob::unsafe_as<Value<int>>() {
    return &payload.valueInt;
}

template <>
inline Value<float> *Ob::unsafe_as<Value<float>>() {
    return &payload.valueFloat;
}

template <>
inline Value<char> *Ob::unsafe_as<Value<char>>() {
    return &payload.valueChar;
}

template <>
inline Value<long long> *Ob::unsafe_as<Value<long long>>() {
    return &payload.valueLong;
}

template <class T>
inline Ob::Ob(const T &t) : Ob(TypeFlags{TypeTagOf<T>::typeTagValue}) {
    new (unsafe_as<T>()) T(t);
}

template <class T, class ...Args>
inline Ptr Ob::of(Args&&... args) {
    return new Ob(T(std::forward<Args>(args)...));
}


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

template <class T>
inline T * Ob::as() {
    if(! is<T>())
        return nullptr;
    return unsafe_as<T>();
}

template <class T>
T * Ob::cast() {
    T * res = as<T>();
    if (res == nullptr)
        throw SemanticError("error cast");
    return res;
}

} // namespaces
