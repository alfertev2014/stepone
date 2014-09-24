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
    char * buffer;
    int length;

    explicit ByteArray(int _n): length(_n) {
        if(length < 0)
            length = 0;
        buffer = new char[length];
    }

public:
    ~ByteArray() {delete [] buffer;}

    int getSize() const {return length;}

    char getElement(int i) const {return buffer[i];}

    const char * getData() const {return buffer;}

    string toString() const {
        if(length <= 0) return "bytes[]";
        stringstream ss;
        ss << "bytes[" << length << "]";
        return ss.str();
    }

    ByteArray * copy() {
        ByteArray * res = new ByteArray(length);
        for(int i = 0; i < length; ++i)
            res->buffer[i] = buffer[i];
        return res;
    }

    ByteArray * concat(ByteArray * ba) const {
        int nres = length + ba->length;
        ByteArray * res = new ByteArray(nres);
        for(int i = 0; i < length; ++i)
            res->buffer[i] = buffer[i];
        for(int i = 0; i < ba->length; ++i)
            res->buffer[length + i] = ba->buffer[i];
        return res;
    }

    template <class T>
    static ByteArray * from(T f) {
        ByteArray * res = new ByteArray(sizeof(T));
        *(reinterpret_cast<T*>(res->buffer)) = f;
        return res;
    }

    static ByteArray * fromChars(int n, const char * s) {
        ByteArray * res = new ByteArray(n);
        for(int i = 0; i < n; ++i)
            res->buffer[i] = s[i];
        return res;
    }

    ByteArray * mid(int begin, int end) {
        int n = end - begin;
        ByteArray * res = new ByteArray(n);
        for(int i = 0; i < n; ++i)
            res->buffer[i] = buffer[begin + i];
        return res;
    }

    template <class T>
    T get(int i) {
        if(i < 0 || i + sizeof(T) > length) { DBG("Error get from bytearray");  throw SemanticError();}
        return *(reinterpret_cast<T*>(buffer + i));
    }

    friend class ByteArraySlice;
};

class ByteArraySlice : public Value {
public:
    Ptr getTypeId() const {return TypeInfo<ByteArraySlice>::type_id;}
    static string getTypeString() {return "ByteArraySlice";}
    string typeToString() const {return getTypeString();}
private:
    Ptr array;
    char * beginPtr;
    int length;
public:
    explicit ByteArraySlice(ByteArray * _array)
        : array(_array), beginPtr(_array->buffer), length(_array->length) {}

    ByteArraySlice(ByteArray * _array, int _begin, int _length)
        : array(_array), beginPtr(_array->buffer + _begin), length(_length) {}

    ByteArraySlice(const Ptr &_array, char * _begin, int _length)
        : array(_array), beginPtr(_begin), length(_length) {}

    ByteArraySlice(char * _begin, int _length)
        : array(Ptr()), beginPtr(_begin), length(_length) {}

    int getSize() const {return length;}

    char getElement(int i) const {return beginPtr[i];}

    const char * getData() const {return beginPtr;}

    string toString() const {
        if(length <= 0) return "byteslice[]";
        stringstream ss;
        ss << "byteslice[" << length << "]";
        return ss.str();
    }

    ByteArray * copy() {
        ByteArray * res = new ByteArray(length);
        for(int i = 0; i < length; ++i)
            res->buffer[i] = beginPtr[i];
        return res;
    }

    ByteArraySlice * concat(ByteArraySlice * bas) const {
        int nres = length + bas->length;
        if(bas->beginPtr == beginPtr + length)
            return new ByteArraySlice(array, beginPtr, nres);
        ByteArray * res = new ByteArray(nres);
        for(int i = 0; i < length; ++i)
            res->buffer[i] = beginPtr[i];
        for(int i = 0; i < bas->length; ++i)
            res->buffer[length + i] = bas->beginPtr[i];
        return new ByteArraySlice(res);
    }

    ByteArray * mid(int begin, int end) {
        int n = end - begin;
        ByteArray * res = new ByteArray(n);
        for(int i = 0; i < n; ++i)
            res->buffer[i] = beginPtr[begin + i];
        return res;
    }

    ByteArraySlice * midSlice(int begin, int end) {
        int n = end - begin;
        return new ByteArraySlice(array, beginPtr + begin, n);
    }

    template <class T>
    static ByteArraySlice * fromValue(ValueType<T> *f) {
        return new ByteArraySlice(f, f->getValuePointer(), sizeof(T));
    }

    template <class T>
    T get(int i) {
        if(i < 0 || i + sizeof(T) > length) { DBG("Error get from bytearrayslice");  throw SemanticError();}
        return *((T*)(beginPtr + i));
    }
};

class FByteArrayLength : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FByteArrayLength>::type_id;}
    static string getTypeString() {return "FByteArrayLength";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {
        return new ValueType<int>(p->eval(a)->cast<ByteArray>()->getSize());
    }

    string toString() const {return "FByteArrayLength{}";}
};

class FByteArraySliceLength : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FByteArraySliceLength>::type_id;}
    static string getTypeString() {return "FByteArraySliceLength";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {
        return new ValueType<int>(p->eval(a)->cast<ByteArraySlice>()->getSize());
    }

    string toString() const {return "FByteArraySliceLength{}";}
};

class FByteArrayCopy : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FByteArrayCopy>::type_id;}
    static string getTypeString() {return "FByteArrayCopy";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {
        return p->eval(a)->cast<ByteArray>()->copy();
    }

    string toString() const {return "FByteArrayCopy{}";}
};

class FByteArraySliceCopy : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FByteArraySliceCopy>::type_id;}
    static string getTypeString() {return "FByteArraySliceCopy";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {
        return p->eval(a)->cast<ByteArraySlice>()->copy();
    }

    string toString() const {return "FByteArraySliceCopy{}";}
};



class ConcatByteArrayBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return x1->cast<ByteArray>()->concat(x2->cast<ByteArray>());
    }
    static string toString() {return "ConcatByteArrayBinOp";}
};

class ConcatByteArraySliceBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return x1->cast<ByteArraySlice>()->concat(x2->cast<ByteArraySlice>());
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

class MidByteArraySliceTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return x1->cast<ByteArraySlice>()->midSlice(x2->cast<ValueType<int> >()->getValue(), x3->cast<ValueType<int> >()->getValue());
    }
    static string toString() {return "MidByteArraySliceTerOp";}
};

template <class T>
class FSerialize : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FSerialize<T> >::type_id;}
    static string getTypeString() {return "FSerialize{" + cppTypeToString<T>() + "}";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {
        return ByteArraySlice::fromValue<T>(p->eval(a)->cast<ValueType<T> >());
    }

    string toString() const {return "FSerialize{" + cppTypeToString<T>() + "}";}
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
class ByteArraySliceGetBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<T>(x1->cast<ByteArraySlice>()->get<T>(x2->cast<ValueType<int> >()->getValue()));
    }
    static string toString() {return "ByteArraySliceGetBinOp{" + cppTypeToString<T>() + "}";}
};



class ByteArrayFunctions {
    ByteArrayFunctions(){}
public:
    static const Ob::Ptr fbarrayp;
    static const Ob::Ptr fbslicep;
    static const Ob::Ptr fbarraylen;
    static const Ob::Ptr fbslicelen;
    static const Ob::Ptr fbarraycat;
    static const Ob::Ptr fbslicecat;
    static const Ob::Ptr fbarraymid;
    static const Ob::Ptr fbslicemid;
    static const Ob::Ptr fbarraycopy;
    static const Ob::Ptr fbslicecopy;

    static const Ob::Ptr fserint;
    static const Ob::Ptr fserfloat;
    static const Ob::Ptr fserchar;

    static const Ob::Ptr fgetint;
    static const Ob::Ptr fgetfloat;
    static const Ob::Ptr fgetchar;
};
