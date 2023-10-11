#pragma once

#include <ptr_impl.h>

namespace stepone::operations {

using namespace stepone::types;

class VectorLengthUnOp {
public:
    Ptr operator()(const Ptr &x) const {return Ptr::of<Value<long>>(static_cast<int>(x.cast<Vector>().getSize()));}
};

class FMakeVector {
public:
    Ptr operator()(const Ptr &p, const Ptr &a) const {
        long n = p.car().eval(a).cast<Value<long> >().value;
        return Ptr::of<Vector>(n, p.cdr(), a);
    }
};

class VectorElBinOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2) const {
        return x1.cast<Vector>().getElement(x2.cast<Value<long> >().value);
    }
};

class VectorCloneUnOp {
public:
    Ptr operator()(const Ptr &x) const {
        return Ptr::of<Vector>(x.cast<Vector>());
    }
};

class VectorConcatBinOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2) const {
        return Ptr::of<Vector>(x1.cast<Vector>(), x2.cast<Vector>());
    }
};

class VectorMidTerOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2, const Ptr &x3) const {
        return Ptr::of<Vector>(x1.cast<Vector>(), x2.cast<Value<long> >().value, x3.cast<Value<long> >().value);
    }
};


} // namespaces
