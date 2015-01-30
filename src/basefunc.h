#pragma once

#include "core.h"

class CarUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return x->car();}
    static string toString() {return "car";}
};

class CdrUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return x->cdr();}
    static string toString() {return "cdr";}
};

class ConsBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {return new Pair(x1, x2);}
    static string toString() {return "cons";}
};

class EqBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {return x1 == x2;}
    static string toString() {return "eq";}
};

class GetTypeUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return x->getTypeInfo()->type_id;}
    static string toString() {return "get-type";}
};

class ContextGetBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {return x1->cast<Evaluator>()->getContext()->assoc(x2);}
    static string toString() {return "ctx-get";}
};

class ContextPushTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {return new Evaluator(Context::make(x2, x3, x1->cast<Evaluator>()->getContext()));}
    static string toString() {return "ctx-push";}
};

class BaseFunctions {
    BaseFunctions();
public:
    static const BaseFunctions &inst();

    const Ob::Ptr fcar;
    const Ob::Ptr fcdr;
    const Ob::Ptr fcons;
    const Ob::Ptr feq;
    const Ob::Ptr fgettype;
    const Ob::Ptr fctxget;
    const Ob::Ptr fctxpush;
};
