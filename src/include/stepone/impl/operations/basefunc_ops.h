#pragma once

#include <impl/core/ob.h>
#include <impl/ptr_impl.h>

namespace stepone::operations {

using namespace core;

class CarUnOp {
public:
    Ptr operator()(const Ptr &x) const {return x.car();}
};

class CdrUnOp {
public:
    Ptr operator()(const Ptr &x) const {return x.cdr();}
};

class ConsBinOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2) const {return Ob::of<Pair>(x1, x2);}
};

class EqBinOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2) const {return x1 == x2 ? Ptr::at() : Ptr::anil();}
};

class ContextGetBinOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2) const {return x1.cast<Evaluator>().getContext().assoc(x2);}
};

class ContextPushTerOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2, const Ptr &x3) const {return Ob::of<Evaluator>(Context::make(x2, x3, x1.cast<Evaluator>().getContext()));}
};

} // namespaces
