#pragma once

#include <ptr.h>

namespace stepone::operations {

template <class T>
class TypePUnOp {
public:
    static Ptr op(const Ptr &x) {return x.is<T>();}
};

} // namespaces
