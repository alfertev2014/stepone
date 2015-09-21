#pragma once

#include "valuetype.h"

class Vector : public Value {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Vector>::instance;}
private:
    Ptr origin;
    Ptr * array;
    int length;

    Vector(int _length): origin(Ob::anil), length(_length) {
        // array is not initialized
        // allocate memory, don't call constructor Ptr()
        array = reinterpret_cast<Ptr*>(new char[length * sizeof(Ptr)]);
    }
public:
    explicit Vector(Vector * _origin)
        : origin(_origin), array(_origin->array), length(_origin->length) {}

    Vector(Vector * _origin, int _begin, int _length)
        : origin(_origin), array(_origin->array + _begin), length(_length < 0 ? 0 : _length) {}

    Vector(const Ptr &_origin, Ptr * _begin, int _length)
        : origin(_origin), array(_begin), length(_length < 0 ? 0 : _length) {}


    ~Vector() {
        if(origin == Ob::anil) {
            // manual call destructor ~Ptr()
            for(int i = 0; i < length; ++i)
                array[i].~Ptr();
            delete [] reinterpret_cast<char*>(array);
        }
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

    Vector * clone() {
        Vector * res = new Vector(length);
        for(int i = 0; i < length; ++i)
            new (res->array + i) Ptr(array[i]);
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

    Vector * slice(int begin, int end) {
        if(begin < 0 || end >= length) {
            DBG("vector index out of range");
            throw SemanticError();
        }
        return new Vector(this, begin, end - begin);
    }

    friend class FMakeVector;
    friend class VectorElBinOp;
};
