#pragma once

#include <ptr.h>
#include <ob.h>

namespace stepone {

struct Ptr::RefCounter final {
    int refcount {0};
    Ob ob;

    template <class T>
    inline RefCounter(T&& t): ob(std::forward<T>(t)) {}
};

template <class T, class ...Args>
inline Ptr Ptr::of(Args&&... args) {
    return new RefCounter(T(std::forward<Args>(args)...));
}

inline void Ptr::acquire() const {
    rcob->refcount++;
}

inline void Ptr::release() const {
    if (rcob) {
        rcob->refcount--;
        if (rcob->refcount == 0) {
            delete rcob;
        }
    }
}

template <class T>
inline T * Ptr::as() const {
    return rcob->ob.as<T>();
}

template <class T>
inline bool Ptr::is() const {
    return rcob->ob.is<T>();
}

template <class T>
inline T &Ptr::cast() const {
    return rcob->ob.cast<T>();
}

inline Ptr Ptr::car() const {
    return rcob->ob.car();
}

inline Ptr Ptr::cdr() const {
    return rcob->ob.cdr();
}

inline Ptr Ptr::eval(const Ptr & a) const {
    return rcob->ob.visit(overloaded {
        [&](types::Pair &p) { return p.eval(a); },
        [&, *this](types::Symbol &s) { return types::Context::assoc(a, *this); },
        [&](types::Lazy &p) { return p.eval(a); },
        [&, *this](types::Const &p) { return *this; },
        [](types::Any&) -> Ptr { throw SemanticError("eval"); }
    });
}

inline Ptr Ptr::apply(const Ptr & p, const Ptr & a) const {
    if (p == Ptr::anil()) return *this;
    return rcob->ob.visit(overloaded {
        [&](types::Lazy &t) { return t.apply(p, a); },
        [&](auto& t) -> Ptr {
            using T = std::decay_t<decltype(t)>;
            if constexpr (std::is_base_of_v<types::Macro, T>) {
                return t.apply(p, a);
            } else {
                throw SemanticError("apply of not applyable");
            }
        }
    });
}

inline Ptr Ptr::unlazy() const {
    return rcob->ob.visit(overloaded {
        [&](types::Lazy &t) { return t.unlazy(); },
        [*this](types::Any&) -> Ptr { return *this; }
    });
}

} // namespace
