#pragma once

#include <impl/core/ob.h>
#include <impl/ptr_impl.h>

namespace stepone::operations {

using namespace stepone::core;

template <class T1, class T2>
class ValueCastUnOp {
public:
    Ptr operator()(const Ptr &x) const {
        return Ob::of<Value<T2>>(x.cast<Value<T1>>().getValue());
    }
};

template <typename T, template<typename> typename CppUnOp>
class ValueUnOp {
public:
    Ptr operator()(const Ptr & x) const {
        return Ob::of<Value<T>>(CppUnOp<T>::op(x.cast<Value<T>>().getValue()));
    }
};

template <typename T, template<typename> typename CppBinOp>
class ValueBinOp {
public:
    Ptr operator()(const Ptr & x1, const Ptr & x2) const {
        return Ob::of<Value<T>>(CppBinOp<T>::op(x1.cast<Value<T>>().getValue(), x2.cast<Value<T> >().getValue()));
    }
};

template <typename T, template<typename> typename CppCmpOp>
class ValueCmpOp {
public:
    Ptr operator()(const Ptr & x1, const Ptr & x2) const {
        return CppCmpOp<T>::op(x1.cast<Value<T>>().getValue(), x2.cast<Value<T> >().getValue()) ? Ptr::at() : Ptr::anil();
    }
};

} // namespaces
