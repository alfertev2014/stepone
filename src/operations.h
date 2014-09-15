#pragma once

#include "core.h"

template <class T>
class FTypeP : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FTypeP<T> >::type_id;}
    static string getTypeString() {return "FTypeP{" + T::getTypeString() + "}";}
    string typeToString() const {return getTypeString();}

    Ob::Ptr apply(const Ptr &p, const Ptr &a) {return p->is<T>() ? Ob::anil : Ob::at;}

    string toString() const {return "FTypeP{" + T::getTypeString() + "}";}
};

template <class UnOp>
class FUnaryOp : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FUnaryOp<UnOp> >::type_id;}
    static string getTypeString() {return "FUnaryOp{" + UnOp::toString() + "}";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {return UnOp::op(p->eval(a));}

    string toString() const {return "FUnaryOp{" + UnOp::toString() + "}";}
};

template <class BinOp>
class FBinaryOp : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FBinaryOp<BinOp> >::type_id;}
    static string getTypeString() {return "FBinaryOp{" + BinOp::toString() + "}";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {
        return BinOp::op(p->car()->eval(a), p->cdr()->eval(a));
    }

    string toString() const {return "FBinaryOp{" + BinOp::toString() + "}";}
};

template <class TerOp>
class FTernaryOp : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FTernaryOp<TerOp> >::type_id;}
    static string getTypeString() {return "FTernaryOp{" + TerOp::toString() + "}";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {
        Ptr pcdr = p->cdr();
        return TerOp::op(p->car()->eval(a), pcdr->car()->eval(a), pcdr->cdr()->eval(a));
    }

    string toString() const {return "FTernaryOp{" + TerOp::toString() + "}";}
};
