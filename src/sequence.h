#pragma once

#include "core.h"
#include "valuetype.h"

template <class T>
class Sequence : public Value {
private:
    T * buffer;
    int length;

    explicit Sequence(int _n): length(_n < 0 ? 0 : _n) {
        buffer = new T[length];
    }

public:
    ~Sequence() {delete [] buffer;}

    int getSize() const {return length;}

    const T * getData() const {return buffer;}

    Sequence * copy() {
        Sequence * res = new Sequence(length);
        for(int i = 0; i < length; ++i)
            res->buffer[i] = buffer[i];
        return res;
    }

    int cmp(Sequence *ba) {
        return length > ba->length ? 1 :
               length < ba->length ? -1 :
               memcmp(buffer, ba->buffer, length);
    }

    int ncmp(Sequence *ba, int n) {
        return memcmp(buffer, ba->buffer, n);
    }

    int findChar(const T &ch) {
        T * end = buffer + length;
        for(T * p = buffer; p != end; ++p) {
            if(*p == T)
                return p - buffer;
        }
        return -1;
    }

    int findSubarray(Sequence *ba) {
        T * pend = buffer + length;
        T * needleEnd = ba->buffer + ba->length;
        for(T *p = buffer, *needle = ba->buffer; p != pend; ++p, ++needle) {
            if(*p != *needle) {
                needle = ba->buffer;
            }
            if(needle == needleEnd)
                return p - buffer - ba->length;
        }
        return -1;
    }

    Sequence * concat(Sequence * ba) const {
        int nres = length + ba->length;
        Sequence * res = new Sequence(nres);
        for(int i = 0; i < length; ++i)
            res->buffer[i] = buffer[i];
        for(int i = 0; i < ba->length; ++i)
            res->buffer[length + i] = ba->buffer[i];
        return res;
    }

    template <class F>
    static Sequence * from(F f) {
        Sequence * res = new Sequence(sizeof(F));
        *(reinterpret_cast<F*>(res->buffer)) = f;
        return res;
    }

    static Sequence * fromChars(int size, const T * chars) {
        Sequence * res = new Sequence(size);
        memcpy(res->buffer, chars, size);
        return res;
    }

    Sequence * mid(int begin, int end) {
        if(begin > length)
            begin = length;
        if(end > length)
            end = length;
        int n = end - begin;
        if(n < 0)
            n = 0;
        Sequence * res = new Sequence(n);
        for(int i = 0; i < n; ++i)
            res->buffer[i] = buffer[begin + i];
        return res;
    }

    T &get(int i) {
        if(i < 0 || i >= length) { DBG("Error get from bytearray");  throw SemanticError();}
        return buffer + i;
    }

    friend class SequenceSlice;
};

template <class T>
class SequenceSlice : public Value {
private:
    Ptr array;
    T * beginPtr;
    int length;
public:
    explicit SequenceSlice(Sequence * _array)
        : array(_array), beginPtr(_array->buffer), length(_array->length) {}

    SequenceSlice(Sequence * _array, int _begin, int _length)
        : array(_array), beginPtr(_array->buffer + _begin), length(_length < 0 ? 0 : _length) {}

    SequenceSlice(const Ptr &_array, T * _begin, int _length)
        : array(_array), beginPtr(_begin), length(_length < 0 ? 0 : _length) {}

    SequenceSlice(T * _begin, int _length)
        : array(Ptr()), beginPtr(_begin), length(_length < 0 ? 0 : _length) {}

    int getSize() const {return length;}

    const T * getData() const {return beginPtr;}

    Sequence * copy() {
        Sequence * res = new Sequence(length);
        for(int i = 0; i < length; ++i)
            res->buffer[i] = beginPtr[i];
        return res;
    }

    int cmp(Sequence *ba) {
        return length > ba->length ? 1 :
               length < ba->length ? -1 :
               memcmp(beginPtr, ba->buffer, length);
    }

    int ncmp(Sequence *ba, int n) {
        return memcmp(beginPtr, ba->buffer, n);
    }

    int cmp(SequenceSlice *bas) {
        return length > bas->length ? 1 :
               length < bas->length ? -1 :
               memcmp(beginPtr, bas->beginPtr, length);
    }

    int ncmp(SequenceSlice *bas, int n) {
        return memcmp(beginPtr, bas->beginPtr, n);
    }

    int findChar(int ch) {
        char * res = (char *)memchr(beginPtr, ch, length);
        return res ? res - beginPtr : -1;
    }

    int findSubarray(SequenceSlice *bas) {
        char * pend = beginPtr + length;
        char * needleEnd = bas->beginPtr + bas->length;
        for(char *p = beginPtr, *needle = bas->beginPtr; p != pend; ++p, ++needle) {
            if(*p != *needle) {
                needle = bas->beginPtr;
            }
            if(needle == needleEnd)
                return p - beginPtr - bas->length;
        }
        return -1;
    }

    SequenceSlice * concat(SequenceSlice * bas) const {
        int nres = length + bas->length;
        if(bas->beginPtr == beginPtr + length)
            return new SequenceSlice(array, beginPtr, nres);
        Sequence * res = new Sequence(nres);
        memcpy(res->buffer, beginPtr, length);
        memcpy(res->buffer + length, bas->beginPtr, bas->length);
        return new SequenceSlice(res);
    }

    Sequence * mid(int begin, int end) {
        if(begin > length)
            begin = length;
        if(end > length)
            end = length;
        int n = end - begin;
        if(n < 0)
            n = 0;
        Sequence * res = new Sequence(n);
        for(int i = 0; i < n; ++i)
            res->buffer[i] = beginPtr[begin + i];
        return res;
    }

    SequenceSlice * midSlice(int begin, int end) {
        if(begin > length)
            begin = length;
        if(end > length)
            end = length;
        int n = end - begin;
        if(n < 0)
            n = 0;
        return new SequenceSlice(array, beginPtr + begin, n);
    }

    T &get(int i) {
        if(i < 0 || i >= length) { DBG("Error get from bytearrayslice");  throw SemanticError();}
        return beginPtr + i;
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

class CompareByteArrayBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<int>(x1->cast<ByteArray>()->cmp(x2->cast<ByteArray>()));
    }
    static string toString() {return "CompareByteArrayBinOp";}
};

class CompareByteArraySliceBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<int>(x1->cast<ByteArraySlice>()->cmp(x2->cast<ByteArraySlice>()));
    }
    static string toString() {return "CompareByteArraySliceBinOp";}
};

class NCompareByteArrayTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return new ValueType<int>(x1->cast<ByteArray>()->ncmp(x2->cast<ByteArray>(), x3->cast<ValueType<int> >()->getValue()));
    }
    static string toString() {return "NCompareByteArrayTerOp";}
};

class NCompareByteArraySliceTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return new ValueType<int>(x1->cast<ByteArraySlice>()->ncmp(x2->cast<ByteArraySlice>(), x3->cast<ValueType<int> >()->getValue()));
    }
    static string toString() {return "NCompareByteArraySliceTerOp";}
};

class FindCharByteArrayBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<int>(x1->cast<ByteArray>()->findChar(x2->cast<ValueType<char> >()->getValue()));
    }
    static string toString() {return "FindCharByteArrayBinOp";}
};

class FindCharByteArraySliceBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<int>(x1->cast<ByteArraySlice>()->findChar(x2->cast<ValueType<char> >()->getValue()));
    }
    static string toString() {return "FindCharByteArraySliceBinOp";}
};

class FindCharsByteArrayBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<int>(x1->cast<ByteArray>()->findSubarray(x2->cast<ByteArray>()));
    }
    static string toString() {return "FindCharsByteArrayBinOp";}
};

class FindCharsByteArraySliceBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return new ValueType<int>(x1->cast<ByteArraySlice>()->findSubarray(x2->cast<ByteArraySlice>()));
    }
    static string toString() {return "FindCharsByteArraySliceBinOp";}
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
        return SequenceSlice::fromValue<T>(p->eval(a)->cast<ValueType<T> >());
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
    static const Ob::Ptr fbarraycopy;
    static const Ob::Ptr fbslicecopy;
    static const Ob::Ptr fbarraycmp;
    static const Ob::Ptr fbslicecmp;
    static const Ob::Ptr fbarrayncmp;
    static const Ob::Ptr fbslicencmp;
    static const Ob::Ptr fbarrayfindch;
    static const Ob::Ptr fbslicefindch;
    static const Ob::Ptr fbarrayfind;
    static const Ob::Ptr fbslicefind;
    static const Ob::Ptr fbarraycat;
    static const Ob::Ptr fbslicecat;
    static const Ob::Ptr fbarraymid;
    static const Ob::Ptr fbslicemid;

    static const Ob::Ptr fserint;
    static const Ob::Ptr fserfloat;
    static const Ob::Ptr fserchar;

    static const Ob::Ptr fgetint;
    static const Ob::Ptr fgetfloat;
    static const Ob::Ptr fgetchar;
};
