#pragma once

#include "core.h"

class FCar : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FCar>::type_id;}
    static string getTypeString() {return "FCar";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->car();}
public:
    string toString() const {return "FCar{}";}
};

class FCdr : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FCdr>::type_id;}
    static string getTypeString() {return "FCdr";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->cdr();}
public:
    string toString() const {return "FCdr{}";}
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

class FGetType : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FGetType>::type_id;}
    static string getTypeString() {return "FGetType";}
    string typeToString() const {return getTypeString();}
protected:
    Ptr applyX(const Ptr &x) {return x->getTypeId();}
public:
    string toString() const {return "FGetType{}";}
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
