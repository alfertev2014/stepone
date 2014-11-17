#pragma once

#include "core.h"
#include "valuetype.h"

#include <cstring>
#include <sstream>


class ByteArray : public Value {
public:
    Ptr getTypeId() const {return TypeInfo<ByteArray>::type_id;}
    static string getTypeString() {return "ByteArray";}
    string typeToString() const {return getTypeString();}
private:
    Ptr array;
    char * buffer;
    int length;

    explicit ByteArray(int _n): length(_n < 0 ? 0 : _n) {
        buffer = new char[length];
    }

public:
    explicit ByteArray(ByteArray * _array)
        : array(_array), buffer(_array->buffer), length(_array->length) {}

    ByteArray(ByteArray * _array, int _begin, int _length)
        : array(_array), buffer(_array->buffer + _begin), length(_length < 0 ? 0 : _length) {}

    ByteArray(const Ptr &_array, char * _begin, int _length)
        : array(_array), buffer(_begin), length(_length < 0 ? 0 : _length) {}

    ByteArray(char * _begin, int _length)
        : array(Ptr()), buffer(_begin), length(_length < 0 ? 0 : _length) {}

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

    ByteArray * clone() {
        ByteArray * res = new ByteArray(length);
        for(int i = 0; i < length; ++i)
            res->buffer[i] = buffer[i];
        return res;
    }

    int cmp(ByteArray *ba) {
        return length > ba->length ? 1 :
               length < ba->length ? -1 :
               memcmp(buffer, ba->buffer, length);
    }

    int ncmp(ByteArray *ba, int n) {
        return memcmp(buffer, ba->buffer, n);
    }

    int findChar(int ch) {
        char * res = (char *)memchr(buffer, ch, length);
        return res ? res - buffer : -1;
    }

    int findSubarray(ByteArray *ba) {
        char * pend = buffer + length;
        char * needleEnd = ba->buffer + ba->length;
        for(char *p = buffer, *needle = ba->buffer; p != pend; ++p, ++needle) {
            if(*p != *needle) {
                needle = ba->buffer;
            }
            if(needle == needleEnd)
                return p - buffer - ba->length;
        }
        return -1;
    }

    ByteArray * concat(ByteArray * ba) const {
        int nres = length + ba->length;
        ByteArray * res = new ByteArray(nres);
        memcpy(res->buffer, buffer, length);
        memcpy(res->buffer + length, ba->buffer, ba->length);
        return res;
    }

    template <class T>
    static ByteArray * from(T f) {
        ByteArray * res = new ByteArray(sizeof(T));
        *(reinterpret_cast<T*>(res->buffer)) = f;
        return res;
    }

    static ByteArray * fromChars(int size, const char * chars) {
        ByteArray * res = new ByteArray(size);
        memcpy(res->buffer, chars, size);
        return res;
    }

    ByteArray * mid(int begin, int end) {
        if(begin > length)
            begin = length;
        if(end > length)
            end = length;
        int n = end - begin;
        if(n < 0)
            n = 0;
        ByteArray * res = new ByteArray(n);
        memcpy(res->buffer, buffer + begin, n);
        return res;
    }

    ByteArray * slice(int begin, int end) {
        if(begin > length)
            begin = length;
        if(end > length)
            end = length;
        int n = end - begin;
        if(n < 0)
            n = 0;
        return new ByteArray(array == Ob::anil ? this : array, buffer + begin, n);
    }

    template <class T>
    T get(int i) {
        if(i < 0 || i + sizeof(T) > length) { DBG("Error get from bytearray");  throw SemanticError();}
        return *(reinterpret_cast<T*>(buffer + i));
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

class FByteArrayClone : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FByteArrayClone>::type_id;}
    static string getTypeString() {return "FByteArrayClone";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {
        return p->eval(a)->cast<ByteArray>()->clone();
    }

    string toString() const {return "FByteArrayCopy{}";}
};

class CompareByteArrayBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<int>(x1->cast<ByteArray>()->cmp(x2->cast<ByteArray>()));
    }
    static string toString() {return "CompareByteArrayBinOp";}
};

class NCompareByteArrayTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return new ValueType<int>(x1->cast<ByteArray>()->ncmp(x2->cast<ByteArray>(), x3->cast<ValueType<int> >()->getValue()));
    }
    static string toString() {return "NCompareByteArrayTerOp";}
};

class FindCharByteArrayBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<int>(x1->cast<ByteArray>()->findChar(x2->cast<ValueType<char> >()->getValue()));
    }
    static string toString() {return "FindCharByteArrayBinOp";}
};

class FindCharsByteArrayBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<int>(x1->cast<ByteArray>()->findSubarray(x2->cast<ByteArray>()));
    }
    static string toString() {return "FindCharsByteArrayBinOp";}
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

class SliceByteArrayTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return x1->cast<ByteArray>()->slice(x2->cast<ValueType<int> >()->getValue(), x3->cast<ValueType<int> >()->getValue());
    }
    static string toString() {return "SliceByteArrayTerOp";}
};

template <class T>
class FSerialize : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FSerialize<T> >::type_id;}
    static string getTypeString() {return "FSerialize{" + cppTypeToString<T>() + "}";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {
        return ByteArray::from<T>(p->eval(a)->cast<ValueType<T> >()->getValue());
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


class ByteArrayFunctions {
    ByteArrayFunctions(){}
public:
    static const Ob::Ptr fbarrayp;
    static const Ob::Ptr fbarraylen;
    static const Ob::Ptr fbarrayclone;
    static const Ob::Ptr fbarraycmp;
    static const Ob::Ptr fbarrayncmp;
    static const Ob::Ptr fbarrayfindch;
    static const Ob::Ptr fbarrayfind;
    static const Ob::Ptr fbarraycat;
    static const Ob::Ptr fbarraymid;
    static const Ob::Ptr fbarrayslice;

    static const Ob::Ptr fserint;
    static const Ob::Ptr fserfloat;
    static const Ob::Ptr fserchar;

    static const Ob::Ptr fgetint;
    static const Ob::Ptr fgetfloat;
    static const Ob::Ptr fgetchar;
};
