#ifndef TUPLE_H
#define TUPLE_H

#include "core.h"
#include "numbers.h"

class Vector : public SpecType {
    int n;
    Ob::Ptr * arr;
public:
    Vector(int _n): n(_n) {arr = new Ob::Ptr[n];}
    ~Vector() {delete [] arr;}

    int getSize() const {return n;}

    Ob::Ptr getElement(int i) {return arr[i];}

    Vector * concat(Vector * v) const {
        int nres = n + v->n;
        Vector * res = new Vector(nres);
        for(int i = 0; i < n; ++i)
            res->arr[i] = arr[i];
        for(int i = 0; i < v->n; ++i)
            res->arr[n + i] = v->arr[i];
        return res;
    }

    string toString() const {
        if(n <= 0) return "[]";
        string res("[" + arr[0]->toString());
        for(int i = 1; i < n; ++i)
            res += ", " + arr[i]->toString();
        return res + "]";
    }

    bool isVector() const {return true;}
    Vector * asVector() {return this;}

    friend class FMakeVector;
    friend class FVectorEl;
    friend class FConcatVector;
};

class FVectorP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) return Ob::anil;
        Vector * v = stx->asVector();
        return v == 0 ? Ob::anil : Ob::at;
    }
public:
    string toString() const {return "{FVectorP}";}
};

class FVectorLength : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) return Ob::anil;
        Vector * v = stx->asVector();
        return new Integer(v->getSize());
    }
public:
    string toString() const {return "{FVectorP}";}
};

class FMakeVector : public BaseFunction {
    class FMakeVectorN : public BaseFunction {
        Ptr v;
        Ptr * parr;
        Ptr * narr;
    public:
        FMakeVectorN(const Ptr & _v, Ptr * _parr, Ptr * _narr)
            :v(_v), parr(_parr), narr(_narr) {}

        string toString() const {return "FMakeVectorN";}
    protected:
        Ptr applyX(const Ptr &x) {
            *parr = x;
            ++parr;
            return parr != narr ? new FMakeVectorN(v, parr, narr) : v;
        }
    };
protected:
    Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        Integer * i = stx->asInteger();
        int n = i->getInteger();
        Vector * v = new Vector(n);
        return new FMakeVectorN(v, v->arr, v->arr + n);
    }
public:
    string toString() const {return "FMakeVector";}
};

class FVectorEl : public BaseFunction {
    class FVectorElF : public BaseFunction {
        Ptr v;
    public:
        FVectorElF(const Ptr & _v) :v(_v) {}

        string toString() const {return "FVectorElF";}
    protected:
        Ptr applyX(const Ptr &x) {
            SpecType * spv = v->asSpecType();
            if(spv == 0) throw 0;
            Vector * vec = spv->asVector();
            if(vec == 0) throw 0;
            SpecType * sp = x->asSpecType();
            if(sp == 0) throw 0;
            Integer * i = sp->asInteger();
            if(i == 0) throw 0;
            return vec->arr[i->getInteger()];
        }
    };
protected:
    Ptr applyX(const Ptr &x) {return new FVectorElF(x);}
public:
    string toString() const {return "FVectorEl";}
};

class FConcatVector : public BaseFunction {
    class FConcatVector2 : public BaseFunction {
        Ptr v;
    public:
        FConcatVector2(const Ptr & _v) : v(_v) {}

        string toString() const {return "FConcatVector2";}
    protected:
        Ptr applyX(const Ptr &x) {
            SpecType * spv = v->asSpecType();
            if(spv == 0) throw 0;
            Vector * vec1 = spv->asVector();
            if(vec1 == 0) throw 0;
            SpecType * sp = x->asSpecType();
            if(sp == 0) throw 0;
            Vector * vec = sp->asVector();
            if(vec == 0) throw 0;
            return vec1->concat(vec);
        }
    };
protected:
    Ptr applyX(const Ptr &x) {return new FConcatVector2(x);}
public:
    string toString() const {return "FConcatVector";}
};

class VectorFunctions
{
public:
    static const Ob::Ptr fvecp;
    static const Ob::Ptr fmkvec;
    static const Ob::Ptr fveclen;
    static const Ob::Ptr fvecel;
    static const Ob::Ptr fveccat;
};

#endif // TUPLE_H
