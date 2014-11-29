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
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {return x1 == x2 ? Ob::at : Ob::anil;}
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
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {return new Evaluator(new Context(x2, x3, x1->cast<Evaluator>()->getContext()));}
    static string toString() {return "ctx-push";}
};

class BaseFunctions {
    BaseFunctions(){}
public:
    static const Ob::Ptr fcar;
    static const Ob::Ptr fcdr;
    static const Ob::Ptr fcons;
    static const Ob::Ptr feq;
    static const Ob::Ptr fgettype;
    static const Ob::Ptr fctxget;
    static const Ob::Ptr fctxpush;
};
