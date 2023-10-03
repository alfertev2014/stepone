#pragma once

#include <ptr_impl.h>

namespace stepone::operations {

using namespace stepone::core;

class VectorLengthUnOp {
public:
    Ptr operator()(const Ptr &x) const {return Ptr::of<Value<int>>(static_cast<int>(x.cast<Vector>().getSize()));}
};

class FMakeVector {
public:
    Ptr operator()(const Ptr &p, const Ptr &a) const {
        int n = p.car().eval(a).cast<Value<int> >().getValue();
        return Ptr::of<Vector>(n, p.cdr(), a);
    }
};

class VectorElBinOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2) const {
        return x1.cast<Vector>().getElement(x2.cast<Value<int> >().getValue());
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
        return Ptr::of<Vector>(x1.cast<Vector>(), x2.cast<Value<int> >().getValue(), x3.cast<Value<int> >().getValue());
    }
};


} // namespaces
