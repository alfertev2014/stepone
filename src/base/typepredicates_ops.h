#pragma once

#include <core.h>

template <class T>
class TypePUnOp {
public:
    static Ptr op(const Ptr &x) {return bool(x.as<T>());}
};
