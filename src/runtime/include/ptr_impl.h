#pragma once

#include <ptr.h>
#include <ob.h>

namespace stepone {

struct Ptr::RefCounter final {
    mutable int refcount {0};
    const Ob ob;

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
inline const T * Ptr::as() const {
    return rcob->ob.as<T>();
}

template <class T>
inline bool Ptr::is() const {
    return rcob->ob.is<T>();
}

template <class T>
inline const T &Ptr::cast() const {
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
        [&](const types::Pair &p) { return p.eval(a); },
        [&, *this](const types::Symbol &s) { return types::Context::assoc(a, *this); },
        [&, *this](const types::Const &p) { return *this; },
        [](const types::Any&) -> Ptr { throw TypeError("eval"); }
    });
}

inline Ptr Ptr::apply(const Ptr & p, const Ptr & a) const {
    if (p == Ptr::anil()) return *this;
    return rcob->ob.visit(
        [&](const auto& t) -> Ptr {
            using T = std::decay_t<decltype(t)>;
            if constexpr (std::is_base_of_v<types::Macro, T>) {
                return t.apply(p, a);
            } else {
                throw TypeError("apply of not applyable");
            }
        }
    );
}

} // namespace
