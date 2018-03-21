#pragma once

#include <ptr.h>

namespace stepone { namespace operations {

template <class T>
class TypePUnOp {
public:
    static Ptr op(const Ptr &x) {return bool(x.as<T>());}
};

}} // namespaces
