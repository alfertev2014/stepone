#pragma once

#include "valuetype.h"

class Vector : public Value {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Vector>::instance;}
    static string getTypeString() {return "Vector";}
private:
    Ptr * array;
    int length;

    Vector(int _length): length(_length) {
        // array is not initialized
        // allocate memory, don't call constructor Ptr()
        array = reinterpret_cast<Ptr*>(new char[length * sizeof(Ptr)]);
    }
public:
    ~Vector() {
        // manual call destructor ~Ptr()
        for(int i = 0; i < length; ++i)
            array[i].~Ptr();
        delete [] reinterpret_cast<char*>(array);
    }

    int getSize() const {return length;}

    Ptr getElement(int i) {return array[i];}

    static Vector * fromList(int n, const Ptr & list, const Ptr & a) {
        Vector * res = new Vector(n);
        Ptr p = list;
        for(int i = 0; i < n; ++i) {
            new (res->array + i) Ptr(p->car()->eval(a));
            p = p->cdr();
        }
        return res;
    }

    Vector * concat(Vector * v) const {
        int nres = length + v->length;
        Vector * res = new Vector(nres);
        for(int i = 0; i < length; ++i)
            new (res->array + i) Ptr(array[i]);
        for(int i = 0; i < v->length; ++i)
            new (res->array + length + i) Ptr(v->array[i]);
        return res;
    }

    Vector * mid(int begin, int end) {
        if(begin < 0 || end >= length) {
            DBG("vector index out of range");
            throw SemanticError();
        }
        int nres = end - begin;
        Vector * res = new Vector(nres);
        for(int i = 0; i < nres; ++i)
            new (res->array + i) Ptr(array[begin + i]);
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
        return Vector::fromList(n, p->cdr(), a);
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
