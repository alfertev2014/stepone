#pragma once

#include "bytearray.h"

class ByteArrayLengthUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {
        return new ValueType<int>(x->cast<ByteArray>()->getSize());
    }
    static string toString() {return "b-length";}
};

class ByteArrayCloneUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {
        return x->cast<ByteArray>()->clone();
    }
    static string toString() {return "b-clone";}
};

class CompareByteArrayBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<int>(x1->cast<ByteArray>()->cmp(x2->cast<ByteArray>()));
    }
    static string toString() {return "b-cmp";}
};

class NCompareByteArrayTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return new ValueType<int>(x1->cast<ByteArray>()->ncmp(x2->cast<ByteArray>(), x3->cast<ValueType<int> >()->getValue()));
    }
    static string toString() {return "b-ncmp";}
};

class FindCharByteArrayBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<int>(x1->cast<ByteArray>()->findChar(x2->cast<ValueType<char> >()->getValue()));
    }
    static string toString() {return "b-findch";}
};

class FindCharsByteArrayBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<int>(x1->cast<ByteArray>()->findSubarray(x2->cast<ByteArray>()));
    }
    static string toString() {return "b-find";}
};

class ConcatByteArrayBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return x1->cast<ByteArray>()->concat(x2->cast<ByteArray>());
    }
    static string toString() {return "b-cat";}
};

class MidByteArrayTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return x1->cast<ByteArray>()->mid(x2->cast<ValueType<int> >()->getValue(), x3->cast<ValueType<int> >()->getValue());
    }
    static string toString() {return "b-mid";}
};

class SliceByteArrayTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return x1->cast<ByteArray>()->slice(x2->cast<ValueType<int> >()->getValue(), x3->cast<ValueType<int> >()->getValue());
    }
    static string toString() {return "b-slice";}
};

template <class T>
class SerializeUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {
        return ByteArray::from<T>(x->cast<ValueType<T> >()->getValue());
    }
    static string toString() {return "ser{" + cppTypeToString<T>() + "}";}
};

template <class T>
class ByteArrayGetBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<T>(x1->cast<ByteArray>()->get<T>(x2->cast<ValueType<int> >()->getValue()));
    }
    static string toString() {return "b-get{" + cppTypeToString<T>() + "}";}
};

