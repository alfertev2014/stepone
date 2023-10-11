#pragma once

#include <ob.h>

namespace stepone::operations {

using namespace types;

class ByteArrayLengthUnOp {
public:
    Ptr operator()(const Ptr &x) const {
        return Ptr::of<Value<long>>(x.cast<ByteArray>().getSize());
    }
};

class ByteArrayCloneUnOp {
public:
    Ptr operator()(const Ptr &x) const {
        return Ptr::of<ByteArray>(x.cast<ByteArray>());
    }
};

class CompareByteArrayBinOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2) const {
        return Ptr::of<Value<long>>(x1.cast<ByteArray>().cmp(x2.cast<ByteArray>()));
    }
};

class NCompareByteArrayTerOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2, const Ptr &x3) const {
        return Ptr::of<Value<long>>(x1.cast<ByteArray>().ncmp(x2.cast<ByteArray>(), x3.cast<Value<long> >().value));
    }
};

class FindCharByteArrayBinOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2) const {
        return Ptr::of<Value<long>>(x1.cast<ByteArray>().findChar(x2.cast<Value<char> >().value));
    }
};

class FindCharsByteArrayBinOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2) const {
        return Ptr::of<Value<long>>(x1.cast<ByteArray>().findSubarray(x2.cast<ByteArray>()));
    }
};

class ConcatByteArrayBinOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2) const {
        return Ptr::of<ByteArray>(x1.cast<ByteArray>(), x2.cast<ByteArray>());
    }
};

class MidByteArrayTerOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2, const Ptr &x3) const {
        return Ptr::of<ByteArray>(x1.cast<ByteArray>(), x2.cast<Value<long> >().value, x3.cast<Value<long> >().value);
    }
};


template <class T>
class SerializeUnOp {
public:
    Ptr operator()(const Ptr &x) const {
        return Ptr::of<ByteArray>(x.cast<Value<T> >().value);
    }
};

template <class T>
class ByteArrayGetBinOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2) const {
        return Ptr::of<Value<T>>(x1.cast<ByteArray>().get<T>(x2.cast<Value<long> >().value));
    }
};

} // namespaces
