#pragma once

#include "core.h"

template <class T>
class FTypeP : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<FTypeP<T> >::instance;}

    Ob::Ptr apply(const Ptr &p, const Ptr &a) {return p->is<T>() ? Ob::anil : Ob::at;}
};

template <class UnOp>
class FUnaryOp : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<FUnaryOp<UnOp> >::instance;}

    Ptr apply(const Ptr &p, const Ptr &a) {return UnOp::op(p->eval(a));}
};

template <class BinOp>
class FBinaryOp : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<FBinaryOp<BinOp> >::instance;}

    Ptr apply(const Ptr &p, const Ptr &a) {
        return BinOp::op(p->car()->eval(a), p->cdr()->eval(a));
    }
};

template <class TerOp>
class FTernaryOp : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<FTernaryOp<TerOp> >::instance;}

    Ptr apply(const Ptr &p, const Ptr &a) {
        Ptr pcdr = p->cdr();
        return TerOp::op(p->car()->eval(a), pcdr->car()->eval(a), pcdr->cdr()->eval(a));
    }
};
