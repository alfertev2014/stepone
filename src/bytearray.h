#pragma once

#include "core.h"
#include "typetemplates.h"
#include <sstream>


class ByteArray : public Value {
public:
    Ptr getTypeId() const {return TypeInfo<ByteArray>::type_id;}
    static string getTypeString() {return "ByteArray";}
    string typeToString() const {return getTypeString();}
private:
    int n;
    char * arr;
public:
    explicit ByteArray(int _n): n(_n) {arr = new char[n];}
    ~ByteArray() {delete [] arr;}

    int getSize() const {return n;}

    char getElement(int i) const {return arr[i];}

    const char * getData() const {return arr;}

    ByteArray * concat(ByteArray * ba) const {
        int nres = n + ba->n;
        ByteArray * res = new ByteArray(nres);
        for(int i = 0; i < n; ++i)
            res->arr[i] = arr[i];
        for(int i = 0; i < ba->n; ++i)
            res->arr[n + i] = ba->arr[i];
        return res;
    }

    string toString() const {
        if(n <= 0) return "bytes[]";
        stringstream ss;
        ss << "bytes[" << n << "]";
        return ss.str();
    }

    template <class T>
    static ByteArray * from(T f) {
        ByteArray * res = new ByteArray(sizeof(T));
        *((T*)res->arr) = f;
        return res;
    }

    static ByteArray * fromChars(int n, const char * s) {
        ByteArray * res = new ByteArray(n);
        for(int i = 0; i < n; ++i)
            res->arr[i] = s[i];
        return res;
    }

    ByteArray * mid(int i1, int i2) {
        int n = i2 - i1;
        ByteArray * res = new ByteArray(n);
        for(int i = 0; i < n; ++i)
            res->arr[i] = arr[i1 + i];
        return res;
    }

    template <class T>
    T get(int i) {
        if(i < 0 || i + sizeof(T) > n) { DBG("Error get from bytearray");  throw SemanticError();}
        return *((T*)(arr + i));
    }
};

class FByteArrayLength : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FByteArrayLength>::type_id;}
    static string getTypeString() {return "FByteArrayLength";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {
        return new ValueType<int>(x->cast<ByteArray>()->getSize());
    }
public:
    string toString() const {return "FByteArrayLength{}";}
};

class ConcatByteArrayBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return x1->cast<ByteArray>()->concat(x2->cast<ByteArray>());
    }
    static string toString() {return "ConcatByteArrayBinOp";}
};

class MidByteArrayTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return x1->cast<ByteArray>()->mid(x2->cast<ValueType<int> >()->getValue(), x3->cast<ValueType<int> >()->getValue());
    }
    static string toString() {return "MidByteArrayTerOp";}
};

template <class T>
class FSerialize : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FSerialize<T> >::type_id;}
    static string getTypeString() {return "FSerialize{" + cppTypeToString<T>() + "}";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {
        return ByteArray::from<T>(x->cast<ValueType<T> >()->getValue());
    }
public:
    string toString() const {return "FSerialize{" + cppTypeToString<T>() + "}";}
};

template <class T>
class FSerializeBytes : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FSerializeBytes<T> >::type_id;}
    static string getTypeString() {return "FSerializeBytes{" + cppTypeToString<T>() + "}";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {
        return ByteArray::from<T>(T(x->cast<ValueType<long long> >()->getValue()));
    }
public:
    string toString() const {return "FSerializeBytes{" + cppTypeToString<T>() + "}";}
};

template <class T>
class ByteArrayGetBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<T>(x1->cast<ByteArray>()->get<T>(x2->cast<ValueType<int> >()->getValue()));
    }
    static string toString() {return "ByteArrayGetBinOp{" + cppTypeToString<T>() + "}";}
};

template <class T>
class ByteArrayGetBytesBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<long long>(x1->cast<ByteArray>()->get<T>(x2->cast<ValueType<int> >()->getValue()));
    }
    static string toString() {return "ByteArrayGetBytesBinOp{" + cppTypeToString<T>() + "}";}
};

class ByteArrayFunctions {
    ByteArrayFunctions(){}
public:
    static const Ob::Ptr fbytesp;
    static const Ob::Ptr fbyteslen;
    static const Ob::Ptr fbytescat;
    static const Ob::Ptr fbytesmid;
    static const Ob::Ptr fserint;
    static const Ob::Ptr fserfloat;
    static const Ob::Ptr fserchar;
    static const Ob::Ptr fserbyte;
    static const Ob::Ptr fser2bytes;
    static const Ob::Ptr fser4bytes;
    static const Ob::Ptr fser8bytes;
    static const Ob::Ptr fgetint;
    static const Ob::Ptr fgetfloat;
    static const Ob::Ptr fgetchar;
    static const Ob::Ptr fgetbyte;
    static const Ob::Ptr fget2bytes;
    static const Ob::Ptr fget4bytes;
    static const Ob::Ptr fget8bytes;
};
