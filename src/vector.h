#pragma once

#include "core.h"
#include "valuetype.h"

class Vector : public Value {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Vector>::instance;}
    static string getTypeString() {return "Vector";}
private:
    Ob::Ptr * array;
    int length;
public:
    Vector(int _length): length(_length) {array = new Ob::Ptr[length];}
    ~Vector() {delete [] array;}

    int getSize() const {return length;}

    Ob::Ptr getElement(int i) {return array[i];}

    Vector * concat(Vector * v) const {
        int nres = length + v->length;
        Vector * res = new Vector(nres);
        for(int i = 0; i < length; ++i)
            res->array[i] = array[i];
        for(int i = 0; i < v->length; ++i)
            res->array[length + i] = v->array[i];
        return res;
    }

    Vector * mid(int i1, int i2) {
        if(i1 < 0 || i2 >= length) {
            DBG("vector index out of range");
            throw SemanticError();
        }
        int nres = i2 - i1;
        Vector * res = new Vector(nres);
        for(int i = 0; i < nres; ++i)
            res->array[i] = array[i1 + i];
        return res;
    }

    string toString() const {
        if(length <= 0) return "[]";
        string res("[" + array[0]->toString());
        for(int i = 1; i < length; ++i)
            res += ", " + array[i]->toString();
        return res + "]";
    }

    friend class FMakeVector;
    friend class VectorElBinOp;
};

class VectorLengthUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return new ValueType<int>(x->cast<Vector>()->getSize());}
    static string toString() {return "vec-len";}
};

class FMakeVector : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<FMakeVector>::instance;}
    static string getTypeString() {return "FMakeVector";}

    Ptr apply(const Ptr &p, const Ptr &a) {
        int n = p->car()->eval(a)->cast<ValueType<int> >()->getValue();
        Vector * v = new Vector(n);
        Ob::Ptr args = p->cdr();
        for(int i = 0; i < n; ++i) {
            v->array[i] = args->car()->eval(a);
            args = args->cdr();
        }
        return v;
    }
};

class VectorElBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return x1->cast<Vector>()->array[x2->cast<ValueType<int> >()->getValue()];
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
