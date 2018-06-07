#pragma once

#include "type_info.h"
#include "core.h"

#include <error_exception.h>
#include <dbg.h>

namespace stepone {

namespace core {

template <class T>
const Ptr TypeInfo<T>::instance(new Symbol);

template <class T>
T * Ob::as() {
    return TypeInfo<T>::instance == getTypeInfo() ? dynamic_cast<T*>(this) : 0;
}

template <class T>
bool Ob::is() const {
    return TypeInfo<T>::instance == getTypeInfo();
}

template <class T>
T * Ob::cast() {
    if(TypeInfo<T>::instance == getTypeInfo())
        return dynamic_cast<T*>(this);
    DBG("error cast"); throw SemanticError();
}

} // core

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

} // stepone
