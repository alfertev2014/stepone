#pragma once

#include "core.h"

class PairPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asPair());}
};

class LazyPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asLazy());}
};

class LabelPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asLabel());}
};

class AtomPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asAtom());}
};

class SymbolPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asSymbol());}
};

class ConstPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asConst());}
};

class MacroPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asMacro());}
};

class EvaluatorPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asEvaluator());}
};

class BaseMacroPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asBaseMacro());}
};

class UserMacroPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asMacroClosure());}
};

class ValuePUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asValue());}
};
