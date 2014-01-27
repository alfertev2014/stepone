//#ifndef TUPLE_H
//#define TUPLE_H

//#include "core.h"
//#include "typestemp.h"

//class Vector
//{
//    int n;
//    Ob::Ptr * arr;
//public:

//    Vector(int _n): n(_n)
//    {
//        arr = new Ob::Ptr[n];
//    }

//    ~Vector()
//    {
//        delete [] arr;
//    }

//    int getSize() const {return n;}

//    Vector concat(const Vector & v) const
//    {
//        int nres = n + v.n;
//        Vector res(nres);
//        for(int i = 0; i < n; ++i)
//            res.arr[i] = arr[i];
//        for(int i = 0; i < v.n; ++i)
//            res.arr[n + i] = v.arr[i];
//        return res;
//    }

//    string toString() const
//    {
//        if(n <= 0) return "[]";
//        string res("[" + arr[0]->toString());
//        for(int i = 1; i < n; ++i)
//        {
//            res += ", " + arr[i]->toString();
//        }
//        return res + "]";
//    }

//    friend class FMakeVector;
//    friend class FVectorEl;
//    friend class FConcatVector;
//};


//class FMakeVector : public Operation
//{
//    class FMakeVectorN : public Operation
//    {
//        Ptr v;
//        Ptr * parr;
//        Ptr * narr;
//    public:
//        FMakeVectorN(const Ptr & _v, Ptr * _parr, Ptr * _narr)
//            :v(_v), parr(_parr), narr(_narr) {}

//        string toString() const {return "FMakeVectorN";}
//    protected:
//        Ptr applyX(const Ptr &x)
//        {
//            *parr = x;
//            ++parr;
//            return parr != narr ? new FMakeVectorN(v, parr, narr) : v;
//        }
//    };

//protected:
//    Ptr applyX(const Ptr &x)
//    {
//        SpecType * sp = x->asSpecType();
//        if(sp == 0) throw 0;
//        int n = sp->cast<SpecTypeTemp<int> >()->getValue();
//        Vector * v = new Vector(n);
//        return new FMakeVectorN(v, v->arr, v->arr + n);
//    }
//public:
//    string toString() const {return "FMakeVector";}
//};

//class FVectorEl : public Operation
//{
//    class FVectorElF : public Operation
//    {
//        Ptr v;
//        Ptr * arr;
//    public:
//        FVectorElF(const Ptr & _v, Ptr * _arr) :v(_v), arr(_arr){}

//        string toString() const {return "FVectorElF";}
//    protected:
//        Ptr applyX(const Ptr &x)
//        {
//            SpecType * sp = x->asSpecType();
//            if(sp == 0) throw 0;
//            int i = sp->cast<SpecTypeTemp<int> >()->getValue();
//            return arr[i];
//        }
//    };

//protected:
//    Ptr applyX(const Ptr &x)
//    {
//        SpecType * spv = x->asSpecType();
//        if(spv == 0) throw 0;
//        Vector * vec = spv->cast<Vector>();
//        return new FVectorElF(x, vec->arr);
//    }
//public:
//    string toString() const {return "FVectorEl";}
//};

//class FConcatVector : public Operation
//{
//    class FConcatVector2 : public Operation
//    {
//        Ptr v;
//    public:
//        FConcatVector2(const Ptr & _v) : v(_v) {}
//    protected:
//        Ptr applyX(const Ptr &x)
//        {
//            SpecType * sp = x->asSpecType();
//            if(sp == 0) throw 0;
//            Vector * vec = sp->cast<Vector>();
//            if(vec == 0) throw 0;
//            return v->asSpecType()->cast<Vector>()->concat(*vec);
//        }
//    };

//protected:
//    Ptr applyX(const Ptr &x)
//    {
//        SpecType * sp = x->asSpecType();
//        if(spv == 0) throw 0;
//        Vector * v = sp->cast<Vector>();
//        if(v == 0) throw 0;
//        return new FConcatVector2(x);
//    }
//public:
//    string toString() const {return "FConcatVector";}
//};

//class VectorFunc
//{
//public:
//    static const Ob::Ptr fvecp;
//    static const Ob::Ptr fmkvec;
//    static const Ob::Ptr fvecel;
//    static const Ob::Ptr fveccat;
//};

//#endif // TUPLE_H
