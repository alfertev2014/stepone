#pragma once

#include <ptr.h>
#include <impl/core/ob.h>

namespace stepone {

inline void Ptr::acquire() const {
    ob->refcount++;
    // printf("Ptr::acquire, ob=%lx, refcount=%d\n", (unsigned long)ob, ob->refcount);
}

inline void Ptr::release() const {
    // printf("Ptr::release, ob=%lx, ", (unsigned long)ob);
    ob->refcount--;
    // printf("refcount=%d\n", ob->refcount);
    if (ob->refcount == 0) {
        // printf("delete\n");
        delete ob;
    }
}

inline Ptr WPtr::car() const
{
    return ob->car();
}

inline Ptr WPtr::cdr() const
{
    return ob->cdr();
}

inline Ptr WPtr::eval(const Ptr &a) const
{
    return ob->eval(a);
}

inline Ptr WPtr::apply(const Ptr &p, const Ptr &a) const
{
    return ob->apply(p, a);
}

inline Ptr WPtr::unlazy() const
{
    return ob->unlazy();
}

inline Ptr WPtr::assoc(const Ptr &s) const
{
    return ob->assoc(s);
}

template <class T>
inline T * WPtr::as() const {
    return ob->as<T>();
}

template <class T>
inline bool WPtr::is() const {
    return ob->is<T>();
}

template <class T>
inline T &WPtr::cast() const {
    return ob->cast<T>();
}

} // namespace
