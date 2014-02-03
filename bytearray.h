#ifndef BYTEARRAY_H
#define BYTEARRAY_H

#include "core.h"
#include "typestemp.h"
#include <sstream>

class ByteArray : public SpecType {
public:
    Ptr getTypeId() const {return TypeInfo<ByteArray>::type_id;}
    static string getTypeString() {return "ByteArray";}
    string typeToString() const {return getTypeString();}
private:
    int n;
    char * arr;
public:
    ByteArray(int _n): n(_n) {arr = new char[n];}
    ~ByteArray() {delete [] arr;}

    int getSize() const {return n;}

    char getElement(int i) {return arr[i];}

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
        if(i < 0 || i >= n) throw 0;
        return *((T*)(arr + i));
    }
};

class ConcatByteArrayBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return x1->cast<ByteArray>()->concat(x2->cast<ByteArray>());
    }
    static string toString() {return "FConcatByteArray";}
};

class MidByteArrayTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return x1->cast<ByteArray>()->mid(x2->cast<SpecTypeTemp<int> >()->getValue(), x3->cast<SpecTypeTemp<int> >()->getValue());
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
        return ByteArray::from<T>(x->cast<SpecTypeTemp<T> >()->getValue());
    }
public:
    string toString() const {return "FSerialize{" + cppTypeToString<T>() + "}";}
};

template <class T>
class ByteArrayGetBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new SpecTypeTemp<int>(x1->cast<ByteArray>()->get<T>(x2->cast<SpecTypeTemp<int> >()->getValue()));
    }
    static string toString() {return "ByteArrayGetBinOp{" + cppTypeToString<T>() + "}";}
};

class ByteArrayFunctions {
    ByteArrayFunctions(){}
public:
    static const Ob::Ptr fbytesp;
    static const Ob::Ptr fbytescat;
    static const Ob::Ptr fbytesmid;
    static const Ob::Ptr fserint;
    static const Ob::Ptr fserfloat;
    static const Ob::Ptr fgetint;
    static const Ob::Ptr fgetfloat;
};

#endif // BYTEARRAY_H
