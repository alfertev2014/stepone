#pragma once

#include "macro.h"

template <class T>
class FTypeP : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a) {return p.is<T>() ? Ob::anil : Ob::at;}
};

template <class UnOp>
class FUnaryOp : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a) {return UnOp::op(p.eval(a));}
};

template <class BinOp>
class FBinaryOp : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a) {
        return BinOp::op(p.car().eval(a), p.cdr().eval(a));
    }
};

template <class TerOp>
class FTernaryOp : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a) {
        Ptr pcdr = p.cdr();
        return TerOp::op(p.car().eval(a), pcdr.car().eval(a), pcdr.cdr().eval(a));
    }
};
