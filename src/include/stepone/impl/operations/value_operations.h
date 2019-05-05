#pragma once

#include <impl/core/ob.h>
#include <impl/ptr_impl.h>

namespace stepone::operations {

using namespace stepone::core;

template <class T1, class T2>
class ValueCastUnOp {
public:
    static Ptr op(const Ptr &x) {
        return new Ob(Value<T2>(x.cast<Value<T1> >()->getValue()));
    }
};

template <typename T, typename CppUnOp>
class ValueUnOp {
public:
    static Ptr op(const Ptr & x) {
        return new Ob(Value<T>(CppUnOp::op(x.cast<Value<T> >()->getValue())));
    }
};

template <typename T, typename CppBinOp>
class ValueBinOp {
public:
    static Ptr op(const Ptr & x1, const Ptr & x2) {
        return new Ob(Value<T>(CppBinOp::op(x1.cast<Value<T> >()->getValue(), x2.cast<Value<T> >()->getValue())));
    }
};

template <typename T, typename CppCmpOp>
class ValueCmpOp {
public:
    static Ptr op(const Ptr & x1, const Ptr & x2) {
        return CppCmpOp::op(x1.cast<Value<T> >()->getValue(), x2.cast<Value<T> >()->getValue()) ? Ptr::at : Ptr::anil;
    }
};

} // namespaces
