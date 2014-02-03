#ifndef TUPLE_H
#define TUPLE_H

#include "core.h"
#include "funcstemp.h"
#include "typestemp.h"

class Vector : public SpecType {
public:
    Ptr getTypeId() const {return TypeInfo<Vector>::type_id;}
    static string getTypeString() {return "Vector";}
    string typeToString() const {return getTypeString();}
private:
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

    friend class MakeVectorNaryOp;
    friend class VectorElBinOp;
};

class FVectorLength : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FVectorLength>::type_id;}
    static string getTypeString() {return "FVectorLength";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return new SpecTypeTemp<int>(x->cast<Vector>()->getSize());}
public:
    string toString() const {return "FVectorLength{}";}
};


template <class NaryOp>
class FMakeNaryOp : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FMakeNaryOp<NaryOp> >::type_id;}
    static string getTypeString() {return "FMakeNaryOp{" + NaryOp::toString() + "}";}
    string typeToString() const {return getTypeString();}
public:
    string toString() const {return "FMakeNaryOp{" + NaryOp::toString() + "}";}
protected:
    Ptr applyX(const Ptr &x) {
        int n = x->cast<SpecTypeTemp<int> >()->getValue();
        return new FNaryOp<NaryOp>(n, n, new Pair(x, Ob::anil));
    }
};

class MakeVectorNaryOp {
public:
    static Ob::Ptr op(int n, const Ob::Ptr &args) {
        Vector * v = new Vector(n);
        Ob::Ptr p = args;
        for(int i = n - 1; i >= 0; --i) {
            v->arr[i] = p->car();
            p = p->cdr();
        }
        return v;
    }

    static string toString() {return "MakeVectorNaryOp";}
};

class VectorElBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return x1->cast<Vector>()->arr[x2->cast<SpecTypeTemp<int> >()->getValue()];
    }

    static string toString() {return "VectorElBinOp";}
};

class VectorConcatBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return x1->cast<Vector>()->concat(x2->cast<Vector>());
    }

    static string toString() {return "VectorConcatBinOp";}
};

class VectorFunctions {
    VectorFunctions(){}
public:
    static const Ob::Ptr fvecp;
    static const Ob::Ptr fmkvec;
    static const Ob::Ptr fveclen;
    static const Ob::Ptr fvecel;
    static const Ob::Ptr fveccat;
};

#endif // TUPLE_H
