#ifndef BYTEARRAY_H
#define BYTEARRAY_H

#include "core.h"
#include "numbers.h"
#include <sstream>

class ByteArray : public SpecType {
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

    bool isByteArray() const {return true;}
    ByteArray * asByteArray() {return this;}

    static ByteArray * fromInteger(int i) {
        ByteArray * res = new ByteArray(sizeof(int));
        (int*)res->arr = i;
        return res;
    }

    static ByteArray * fromFloat(float f) {
        ByteArray * res = new ByteArray(sizeof(float));
        (int*)res->arr = f;
        return res;
    }

    static ByteArray * fromChars(int n, const char * s) {
        ByteArray * res = new ByteArray(n);
        for(int i = 0; i < n; ++i)
            res->arr[i] = s[i];
        return res;
    }
};

class FByteArrayP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) return Ob::anil;
        ByteArray * ba = stx->asByteArray();
        return ba == 0 ? Ob::anil : Ob::at;
    }
public:
    string toString() const {return "{FByteArrayP}";}
};

class FConcatByteArray : public BaseFunction {
    class FConcatByteArray2 : public BaseFunction {
        Ptr v;
    public:
        FConcatByteArray2(const Ptr & _v) : v(_v) {}
    protected:
        Ptr applyX(const Ptr &x) {
            SpecType * spv = v->asSpecType();
            if(spv == 0) throw 0;
            ByteArray * vec1 = spv->asVector();
            SpecType * sp = x->asSpecType();
            if(sp == 0) throw 0;
            ByteArray * vec = sp->asVector();
            if(vec == 0) throw 0;
            return vec1->concat(vec);
        }
    public:
        string toString() const {return "FConcatByteArray2";}
    };
protected:
    Ptr applyX(const Ptr &x) {return new FConcatByteArray2(x);}
public:
    string toString() const {return "FConcatByteArray";}
};

class FSerializeInteger : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) return Ob::anil;
        Integer * i = stx->asInteger();

        return ba == 0 ? Ob::anil : Ob::at;
    }
public:
    string toString() const {return "{FSerializeInteger}";}
};

class FSerializeFloat : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) return Ob::anil;
        ByteArray * ba = stx->asByteArray();
        return ba == 0 ? Ob::anil : Ob::at;
    }
public:
    string toString() const {return "{FSerializeInteger}";}
};

class ByteArrayFunctions
{
public:
    static const Ob::Ptr fbytesp;
    static const Ob::Ptr fbytescat;
};

#endif // BYTEARRAY_H
