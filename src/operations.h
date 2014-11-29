#pragma once

#include "core.h"

template <class T>
class FTypeP : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<FTypeP<T> >::instance;}
    static string getTypeString() {return "FTypeP{" + T::getTypeString() + "}";}

    Ob::Ptr apply(const Ptr &p, const Ptr &a) {return p->is<T>() ? Ob::anil : Ob::at;}
};

template <class UnOp>
class FUnaryOp : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<FUnaryOp<UnOp> >::instance;}
    static string getTypeString() {return "FUnaryOp{" + UnOp::toString() + "}";}

    Ptr apply(const Ptr &p, const Ptr &a) {return UnOp::op(p->eval(a));}
};

template <class BinOp>
class FBinaryOp : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<FBinaryOp<BinOp> >::instance;}
    static string getTypeString() {return "FBinaryOp{" + BinOp::toString() + "}";}

    Ptr apply(const Ptr &p, const Ptr &a) {
        return BinOp::op(p->car()->eval(a), p->cdr()->eval(a));
    }
};

template <class TerOp>
class FTernaryOp : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<FTernaryOp<TerOp> >::instance;}
    static string getTypeString() {return "FTernaryOp{" + TerOp::toString() + "}";}

    Ptr apply(const Ptr &p, const Ptr &a) {
        Ptr pcdr = p->cdr();
        return TerOp::op(p->car()->eval(a), pcdr->car()->eval(a), pcdr->cdr()->eval(a));
    }
};
