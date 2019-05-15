#pragma once

#include <impl/core/ob.h>

namespace stepone::operations {

using namespace core;

class ByteArrayLengthUnOp {
public:
    static Ptr op(const Ptr &x) {
        return Ob::of<Value<int>>(x.cast<ByteArray>().getSize());
    }
};

class ByteArrayCloneUnOp {
public:
    static Ptr op(const Ptr &x) {
        return Ob::of<ByteArray>(x.cast<ByteArray>());
    }
};

class CompareByteArrayBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {
        return Ob::of<Value<int>>(x1.cast<ByteArray>().cmp(x2.cast<ByteArray>()));
    }
};

class NCompareByteArrayTerOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2, const Ptr &x3) {
        return Ob::of<Value<int>>(x1.cast<ByteArray>().ncmp(x2.cast<ByteArray>(), x3.cast<Value<int> >().getValue()));
    }
};

class FindCharByteArrayBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {
        return Ob::of<Value<int>>(x1.cast<ByteArray>().findChar(x2.cast<Value<char> >().getValue()));
    }
};

class FindCharsByteArrayBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {
        return Ob::of<Value<int>>(x1.cast<ByteArray>().findSubarray(x2.cast<ByteArray>()));
    }
};

class ConcatByteArrayBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {
        return Ob::of<ByteArray>(x1.cast<ByteArray>(), x2.cast<ByteArray>());
    }
};

class MidByteArrayTerOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2, const Ptr &x3) {
        return Ob::of<ByteArray>(x1.cast<ByteArray>(), x2.cast<Value<int> >().getValue(), x3.cast<Value<int> >().getValue());
    }
};


template <class T>
class SerializeUnOp {
public:
    static Ptr op(const Ptr &x) {
        return Ob::of<ByteArray>(x.cast<Value<T> >().getValue());
    }
};

template <class T>
class ByteArrayGetBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {
        return Ob::of<Value<T>>(x1.cast<ByteArray>().get<T>(x2.cast<Value<int> >().getValue()));
    }
};

} // namespaces
