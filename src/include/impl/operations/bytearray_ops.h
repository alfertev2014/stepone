#pragma once

#include <impl/core/bytearray.h>

class ByteArrayLengthUnOp {
public:
    static Ptr op(const Ptr &x) {
        return new Value<int>(x.cast<ByteArray>()->getSize());
    }
};

class ByteArrayCloneUnOp {
public:
    static Ptr op(const Ptr &x) {
        return x.cast<ByteArray>()->clone();
    }
};

class CompareByteArrayBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {
        return new Value<int>(x1.cast<ByteArray>()->cmp(x2.cast<ByteArray>()));
    }
};

class NCompareByteArrayTerOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2, const Ptr &x3) {
        return new Value<int>(x1.cast<ByteArray>()->ncmp(x2.cast<ByteArray>(), x3.cast<Value<int> >()->getValue()));
    }
};

class FindCharByteArrayBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {
        return new Value<int>(x1.cast<ByteArray>()->findChar(x2.cast<Value<char> >()->getValue()));
    }
};

class FindCharsByteArrayBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {
        return new Value<int>(x1.cast<ByteArray>()->findSubarray(x2.cast<ByteArray>()));
    }
};

class ConcatByteArrayBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {
        return x1.cast<ByteArray>()->concat(x2.cast<ByteArray>());
    }
};

class MidByteArrayTerOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2, const Ptr &x3) {
        return x1.cast<ByteArray>()->mid(x2.cast<Value<int> >()->getValue(), x3.cast<Value<int> >()->getValue());
    }
};

class SliceByteArrayTerOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2, const Ptr &x3) {
        return x1.cast<ByteArray>()->slice(x2.cast<Value<int> >()->getValue(), x3.cast<Value<int> >()->getValue());
    }
};

template <class T>
class SerializeUnOp {
public:
    static Ptr op(const Ptr &x) {
        return ByteArray::from<T>(x.cast<Value<T> >()->getValue());
    }
};

template <class T>
class ByteArrayGetBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {
        return new Value<T>(x1.cast<ByteArray>()->get<T>(x2.cast<Value<int> >()->getValue()));
    }
};

