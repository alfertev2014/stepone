#pragma once

#include <ptr.h>
#include "error_exception.h"
#include "type_tag_map.h"

namespace stepone::core {

class Ob {
    friend class ::stepone::Ptr;

    static constexpr std::size_t sizeOfPayload = 4 * sizeof(void*); // TODO: It can be less

    int refcount {0};

    const TypeFlags typeFlags {};
    unsigned char payload[sizeOfPayload];

    template <class Action>
    void visit(Action action = Action()) const;

    template <typename T>
    T &unsafe_as() { return *reinterpret_cast<T*>(payload); }

    template <typename T>
    const T &const_unsafe_as() const { return *reinterpret_cast<const T*>(payload); }

    Ob(TypeFlags typeFlags) : typeFlags(typeFlags) {}

    template <class T>
    Ob(const T &t);
    template <class T>
    Ob(T&& t);
public:
    Ob() = delete;
    Ob(const Ob &ob);
    Ob(Ob&&) = delete;
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
    T &cast();
};


template <class T>
inline Ob::Ob(const T &t) : Ob(TypeFlags{TypeTagOf<T>::typeTagValue}) {
    static_assert(sizeof(T) <= sizeOfPayload);
    new (payload) T(t);
}

template <class T>
inline Ob::Ob(T&& t) : Ob(TypeFlags{TypeTagOf<T>::typeTagValue}) {
    static_assert(sizeof(T) <= sizeOfPayload);
    new (payload) T(std::move(t));
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
    if (! is<T>())
        return nullptr;
    return &unsafe_as<T>();
}

template <class T>
inline T &Ob::cast() {
    if (! is<T>())
        throw SemanticError("error cast");
    return unsafe_as<T>();
}

} // namespaces
