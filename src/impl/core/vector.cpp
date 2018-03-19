#include <impl/core/vector.h>
#include <impl/core/type_info_inst.h>

const Ptr Vector::getTypeInfo() const {return TypeInfo<Vector>::instance;}

Vector::~Vector() {
    if(origin == Ptr::anil) {
        // manual call destructor ~Ptr()
        for(int i = 0; i < length; ++i)
            array[i].~Ptr();
        delete [] reinterpret_cast<char*>(array);
    }
}

Vector *Vector::fromList(int n, const Ptr &list, const Ptr &a) {
    Vector * res = new Vector(n);
    Ptr p = list;
    for(int i = 0; i < n; ++i) {
        new (res->array + i) Ptr(p.car().eval(a));
        p = p.cdr();
    }
    return res;
}

Vector *Vector::clone() {
    Vector * res = new Vector(length);
    for(int i = 0; i < length; ++i)
        new (res->array + i) Ptr(array[i]);
    return res;
}

Vector *Vector::concat(Vector *v) const {
    int nres = length + v->length;
    Vector * res = new Vector(nres);
    for(int i = 0; i < length; ++i)
        new (res->array + i) Ptr(array[i]);
    for(int i = 0; i < v->length; ++i)
        new (res->array + length + i) Ptr(v->array[i]);
    return res;
}

Vector *Vector::mid(int begin, int end) {
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

Vector *Vector::slice(int begin, int end) {
    if(begin < 0 || end >= length) {
        DBG("vector index out of range");
        throw SemanticError();
    }
    return new Vector(this, begin, end - begin);
}
