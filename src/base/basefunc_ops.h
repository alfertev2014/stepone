#pragma once

#include <macro.h>

class CarUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return x->car();}
};

class CdrUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return x->cdr();}
};

class ConsBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {return new Pair(x1, x2);}
};

class EqBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {return x1 == x2;}
};

class GetTypeUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return x->getTypeInfo()->type_id;}
};

class ContextGetBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {return x1->cast<Evaluator>()->getContext()->assoc(x2);}
};

class ContextPushTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {return new Evaluator(Context::make(x2, x3, x1->cast<Evaluator>()->getContext()));}
};
