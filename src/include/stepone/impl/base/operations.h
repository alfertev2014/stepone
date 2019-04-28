#pragma once

#include <impl/core/macro.h>
#include <impl/ptr_impl.h>

namespace stepone::base {

using namespace core;

template <class T>
class FTypeP : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a) {return p.is<T>() ? Ptr::anil : Ptr::at;}
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

} // namespaces
