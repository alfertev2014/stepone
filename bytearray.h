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

    ByteArray * sub(int i1, int i2) {
        int n = i2 - i1;
        ByteArray * res = new ByteArray(n);
        for(int i = 0; i < n; ++i)
            res->arr[i] = s[i1 + i];
        return res;
    }

    template <class T>
    T get(int i) {
        if(i < 0 || i >= n) throw 0;
        return *((T*)arr[i]);
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
        Ptr x1;
    public:
        FConcatByteArray2(const Ptr & _v) : x1(_v) {}
    protected:
        Ptr applyX(const Ptr &x) {
            SpecType * spv = x1->asSpecType();
            if(spv == 0) throw 0;
            ByteArray * ba1 = spv->asByteArray();
            if(ba1 == 0) throw 0;
            spv = x->asSpecType();
            if(spv == 0) throw 0;
            ByteArray * ba = spv->asByteArray();
            if(ba == 0) throw 0;
            return ba1->concat(ba);
        }
    public:
        string toString() const {return "FConcatByteArray2";}
    };
protected:
    Ptr applyX(const Ptr &x) {return new FConcatByteArray2(x);}
public:
    string toString() const {return "FConcatByteArray";}
};

class FByteArrayMid : public BaseFunction {
    class FByteArrayMid2 : public BaseFunction {
        Ptr x1;
        class FByteArrayMid3 : public BaseFunction {
            Ptr x1;
            Ptr x2;
        protected:
            Ptr applyX(const Ptr &x) {
                SpecType * spv = x1->asSpecType();
                if(spv == 0) throw 0;
                ByteArray * ba = spv->asByteArray();
                if(ba == 0) throw 0;
                spv = x2->asSpecType();
                if(spv == 0) throw 0;
                Integer * i1 = spv->asInteger();
                if(i1 == 0) throw 0;
                spv = x->asSpecType();
                if(spv == 0) throw 0;
                Integer * i2 = spv->asInteger();
                if(i2 == 0) throw 0;
                return ByteArray::sub(i1, i2);
            }
        public:
            FSubByteArray2(const Ptr & _x1, const Ptr & _x2) :x1(_x1), x2(_x2) {}
            string toString() const {return "FByteArrayMid3";}
        };
    protected:
        Ptr applyX(const Ptr &x) {return new FByteArrayMid3(x1, x);}
    public:
        FByteArrayMid2(const Ptr & _x1) :x1(_x1){}
        string toString() const {return "FByteArrayMid2";}
    };
protected:
    Ptr applyX(const Ptr &x) {return new FByteArrayMid2();}
public:
    string toString() const {return "FByteArrayMid";}
};

class FSerializeInteger : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        Integer * i = stx->asInteger();
        if(i == 0) throw 0;
        return ByteArray::from<int>(i->getInteger());
    }
public:
    string toString() const {return "{FSerializeInteger}";}
};

class FSerializeFloat : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        Float * f = stx->asFloat();
        if(f == 0) throw 0;
        return ByteArray::from<float>(f->getFloat());
    }
public:
    string toString() const {return "{FSerializeInteger}";}
};

class FBytesGetInt : public BaseFunction {
    class FBytesGetInt2 : public BaseFunction {
        Ptr x1;
    public:
        FBytesGetInt2(const Ptr & _x1) : x1(_x1) {}
    protected:
        Ob::Ptr applyX(const Ptr &x) {
            SpecType * spv = x1->asSpecType();
            if(spv == 0) throw 0;
            ByteArray * ba = spv->asByteArray();
            if(ba == 0) throw 0;
            spv = x->asSpecType();
            if(spv == 0) return Ob::anil;
            Integer * i = spv->asInteger();
            if(i == 0) throw 0;
            return new Integer(ba->get<int>(i));
        }
    public:
        string toString() const {return "{FBytesGetFloat2}";}
    };
protected:
    Ob::Ptr applyX(const Ptr &x) {return new FBytesGetInt2(x);}
public:
    string toString() const {return "{FBytesGetInt}";}
};

class FBytesGetFloat : public BaseFunction {
    class FBytesGetFloat2 : public BaseFunction {
        Ptr x1;
    public:
        FBytesGetFloat2(const Ptr & _x1) : x1(_x1) {}
    protected:
        Ob::Ptr applyX(const Ptr &x) {
            SpecType * spv = x1->asSpecType();
            if(spv == 0) throw 0;
            ByteArray * ba = spv->asByteArray();
            if(ba == 0) throw 0;
            spv = x->asSpecType();
            if(spv == 0) return Ob::anil;
            Integer * i = spv->asInteger();
            if(i == 0) throw 0;
            return new Float(ba->get<float>(i));
        }
    public:
        string toString() const {return "{FBytesGetFloat2}";}
    };
protected:
    Ob::Ptr applyX(const Ptr &x) {return new FBytesGetFloat2(x);}
public:
    string toString() const {return "{FBytesGetFloat}";}
};

class ByteArrayFunctions
{
    ByteArrayFunctions(){}
public:
    static const Ob::Ptr fbytesp;
    static const Ob::Ptr fbytescat;
    static const Ob::Ptr fbytesmid;
    static const Ob::Ptr fserint;
    static const Ob::Ptr fserfloat;
    static const Ob::Ptr fdeserint;
    static const Ob::Ptr fdeserfloat;
};

#endif // BYTEARRAY_H
