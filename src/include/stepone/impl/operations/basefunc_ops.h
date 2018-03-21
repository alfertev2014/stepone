#pragma once

#include <impl/core/macro.h>
#include <impl/ptr_impl.h>
#include <impl/core/type_info_inst.h>

namespace stepone { namespace operations {

using namespace core;

class CarUnOp {
public:
    static Ptr op(const Ptr &x) {return x.car();}
};

class CdrUnOp {
public:
    static Ptr op(const Ptr &x) {return x.cdr();}
};

class ConsBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {return new Pair(x1, x2);}
};

class EqBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {return x1 == x2;}
};

class GetTypeUnOp {
public:
    static Ptr op(const Ptr &x) {return x.typeId();}
};

class ContextGetBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {return x1.cast<Evaluator>()->getContext().assoc(x2);}
};

class ContextPushTerOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2, const Ptr &x3) {return new Evaluator(Context::make(x2, x3, x1.cast<Evaluator>()->getContext()));}
};

}} // namespaces
