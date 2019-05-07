#pragma once

#include <impl/core/ob.h>
#include <impl/ptr_impl.h>

namespace stepone::operations {

using namespace stepone::core;

class VectorLengthUnOp {
public:
    static Ptr op(const Ptr &x) {return Ob::of<Value<int>>(x.cast<Vector>()->getSize());}
};

class FMakeVector {
public:
    static Ptr apply(const Ptr &p, const Ptr &a) {
        int n = p.car().eval(a).cast<Value<int> >()->getValue();
        return Vector::fromList(n, p.cdr(), a);
    }
};

class VectorElBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {
        return x1.cast<Vector>()->array[x2.cast<Value<int> >()->getValue()];
    }
};

class VectorCloneUnOp {
public:
    static Ptr op(const Ptr &x) {
        return x.cast<Vector>()->clone();
    }
};

class VectorConcatBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {
        return x1.cast<Vector>()->concat(x2.cast<Vector>());
    }
};

class VectorMidTerOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2, const Ptr &x3) {
        return x1.cast<Vector>()->mid(x2.cast<Value<int> >()->getValue(), x3.cast<Value<int> >()->getValue());
    }
};

class VectorSliceTerOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2, const Ptr &x3) {
        return x1.cast<Vector>()->mid(x2.cast<Value<int> >()->getValue(), x3.cast<Value<int> >()->getValue());
    }
};

} // namespaces
