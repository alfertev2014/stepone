#pragma once

#include "core.h"
#include "operations.h"
#include "valuetype.h"

class Vector : public Value {
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

    Vector * mid(int i1, int i2) {
        if(i1 < 0 || i2 >= n) {
            DBG("vector index out of range");
            throw SemanticError();
        }
        int nres = i2 - i1;
        Vector * res = new Vector(nres);
        for(int i = 0; i < nres; ++i)
            res->arr[i] = arr[i1 + i];
        return res;
    }

    string toString() const {
        if(n <= 0) return "[]";
        string res("[" + arr[0]->toString());
        for(int i = 1; i < n; ++i)
            res += ", " + arr[i]->toString();
        return res + "]";
    }

    friend class FMakeVector;
    friend class VectorElBinOp;
};

class FVectorLength : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FVectorLength>::type_id;}
    static string getTypeString() {return "FVectorLength";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {return new ValueType<int>(p->eval(a)->cast<Vector>()->getSize());}

    string toString() const {return "FVectorLength{}";}
};


class FMakeVector : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FMakeVector>::type_id;}
    static string getTypeString() {return "FMakeVector";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {
        int n = p->car()->eval(a)->cast<ValueType<int> >()->getValue();
        Vector * v = new Vector(n);
        Ob::Ptr args = p->cdr();
        for(int i = 0; i < n; ++i) {
            v->arr[i] = args->car()->eval(a);
            args = args->cdr();
        }
        return v;
    }

    string toString() const {return "FMakeVector{}";}
};

class VectorElBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return x1->cast<Vector>()->arr[x2->cast<ValueType<int> >()->getValue()];
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

class VectorMidTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return x1->cast<Vector>()->mid(x2->cast<ValueType<int> >()->getValue(), x3->cast<ValueType<int> >()->getValue());
    }

    static string toString() {return "VectorMidTerOp";}
};

class VectorFunctions {
    VectorFunctions(){}
public:
    static const Ob::Ptr fvecp;
    static const Ob::Ptr fmkvec;
    static const Ob::Ptr fveclen;
    static const Ob::Ptr fvecmid;
    static const Ob::Ptr fvecel;
    static const Ob::Ptr fveccat;
};
