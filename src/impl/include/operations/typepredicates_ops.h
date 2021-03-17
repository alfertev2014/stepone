#pragma once

#include <ptr.h>

namespace stepone::operations {

template <class T>
class TypePUnOp {
public:
    Ptr operator()(const Ptr &x) const {return x.is<T>() ? Ptr::at() : Ptr::anil();}
};

} // namespaces
