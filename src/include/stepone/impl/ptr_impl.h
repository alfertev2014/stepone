#pragma once

#include <ptr.h>
#include <impl/core/ob.h>

namespace stepone {

inline void Ptr::acqure() { ob->incRefCount(); }

inline void Ptr::release() { ob->decRefCount(); }

inline void Ptr::assing(core::Ob *_ob)
{
    if(_ob != ob) {
        // don't change the order
        _ob->incRefCount();
        ob->decRefCount();
        ob = _ob;
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
inline T * WPtr::cast() const {
    return ob->cast<T>();
}

} // namespace
