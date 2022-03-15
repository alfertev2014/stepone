#pragma once

#include <core/ob.h>
#include <ptr_impl.h>

namespace stepone::operations {

using namespace stepone::core;

template <class T1, class T2>
class ValueCastUnOp {
public:
    Ptr operator()(const Ptr &x) const {
        return Ptr::of<Value<T2>>(x.cast<Value<T1>>().getValue());
    }
};

} // namespaces
