#pragma once

#include <ptr.h>
#include <core/ob.h>

namespace stepone {

inline core::Ob* as_ob(void *ob) {
    return reinterpret_cast<core::Ob*>(ob);
}

inline void Ptr::acquire() const {
    as_ob(ob)->refcount++;
}

inline void Ptr::release() const {
    as_ob(ob)->refcount--;
    if (as_ob(ob)->refcount == 0) {
        delete as_ob(ob);
    }
}

inline Ptr WPtr::car() const
{
    return as_ob(ob)->car();
}

inline Ptr WPtr::cdr() const
{
    return as_ob(ob)->cdr();
}

inline Ptr WPtr::eval(const Ptr &a) const
{
    return as_ob(ob)->eval(a);
}

inline Ptr WPtr::apply(const Ptr &p, const Ptr &a) const
{
    return as_ob(ob)->apply(p, a);
}

inline Ptr WPtr::unlazy() const
{
    return as_ob(ob)->unlazy();
}

template <class T>
inline T * WPtr::as() const {
    return as_ob(ob)->as<T>();
}

template <class T>
inline bool WPtr::is() const {
    return as_ob(ob)->is<T>();
}

template <class T>
inline T &WPtr::cast() const {
    return as_ob(ob)->cast<T>();
}

} // namespace
