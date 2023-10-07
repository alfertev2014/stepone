#pragma once

#include <ptr_impl.h>

namespace stepone::operations {

using namespace types;

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
    Ptr operator()(const Ptr &x1, const Ptr &x2) const {return Ptr::of<Pair>(x1, x2);}
};

class EqBinOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2) const {return x1 == x2 ? Ptr::at() : Ptr::anil();}
};

class ContextGetBinOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2) const {return x1.cast<Evaluator>().assoc(x2);}
};

class ContextPushTerOp {
public:
    Ptr operator()(const Ptr &x1, const Ptr &x2, const Ptr &x3) const {return x1.cast<Evaluator>().push(x2, x3);}
};

} // namespaces
