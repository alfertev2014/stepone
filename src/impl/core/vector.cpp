#include <impl/core/ob.h>
#include <error_exception.h>

namespace stepone::core {

Vector::~Vector() {
    if(origin == Ptr::anil) {
        // manual call destructor ~Ptr()
        for(int i = 0; i < length; ++i)
            array[i].~Ptr();
        delete [] reinterpret_cast<char*>(array);
    }
}

Ptr Vector::fromList(int n, const Ptr &list, const Ptr &a) {
    Ptr res = Ob::of<Vector>(n);
    Vector * v = res.as<Vector>();
    Ptr p = list;
    for(int i = 0; i < n; ++i) {
        new (v->array + i) Ptr(p.car().eval(a));
        p = p.cdr();
    }
    return res;
}

Ptr Vector::clone() {
    Ptr res = Ob::of<Vector>(length);
    Vector * v = res.as<Vector>();
    for(int i = 0; i < length; ++i)
        new (v->array + i) Ptr(array[i]);
    return res;
}

Ptr Vector::concat(Vector *v) const {
    int nres = length + v->length;
    Ptr res = Ob::of<Vector>(nres);
    Vector * vv = res.as<Vector>();
    for(int i = 0; i < length; ++i)
        new (vv->array + i) Ptr(array[i]);
    for(int i = 0; i < v->length; ++i)
        new (vv->array + length + i) Ptr(v->array[i]);
    return res;
}

Ptr Vector::mid(int begin, int end) {
    if(begin < 0 || end >= length) {
        throw SemanticError("vector index out of range");
    }
    int nres = end - begin;
    Ptr res = Ob::of<Vector>(nres);
    Vector * v = res.as<Vector>();
    for(int i = 0; i < nres; ++i)
        new (v->array + i) Ptr(array[begin + i]);
    return res;
}

} // namespaces
