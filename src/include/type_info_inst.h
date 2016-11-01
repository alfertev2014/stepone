#pragma once

#include "type_info.h"

#include "dbg.h"

template <class T>
class TypeInfo : public TypeInfoBase {
public:
    static const TypeInfo<T> instance;
};

template <class T>
const TypeInfo<T> TypeInfo<T>::instance;

template <class T>
T * Ob::as() {return &TypeInfo<T>::instance == getTypeInfo() ? dynamic_cast<T*>(this) : 0;}

template <class T>
bool Ob::is() const {return &TypeInfo<T>::instance == getTypeInfo();}

template <class T>
T * Ob::cast() {
    if(&TypeInfo<T>::instance == getTypeInfo())
        return dynamic_cast<T*>(this);
    DBG("error cast"); throw SemanticError();
}

template <class T>
inline T * Ptr::as() const {
    return ob->as<T>();
}

template <class T>
inline bool Ptr::is() const {
    return ob->is<T>();
}

template <class T>
inline T * Ptr::cast() const {
    return ob->cast<T>();
}
