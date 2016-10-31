#pragma once

#include <core.h>
#include <macro.h>
#include <value.h>

class PairPUnOp {
public:
    static Ptr op(const Ptr &x) {return bool(x->as<Pair>());}
};

class LazyPUnOp {
public:
    static Ptr op(const Ptr &x) {return bool(x->as<Lazy>());}
};

class LabelPUnOp {
public:
    static Ptr op(const Ptr &x) {return bool(x->as<Label>());}
};

class AtomPUnOp {
public:
    static Ptr op(const Ptr &x) {return bool(x->as<Atom>());}
};

class SymbolPUnOp {
public:
    static Ptr op(const Ptr &x) {return bool(x->as<Symbol>());}
};

class ConstPUnOp {
public:
    static Ptr op(const Ptr &x) {return bool(x->as<Const>());}
};

class MacroPUnOp {
public:
    static Ptr op(const Ptr &x) {return bool(x->as<Macro>());}
};

class EvaluatorPUnOp {
public:
    static Ptr op(const Ptr &x) {return bool(x->as<Evaluator>());}
};

class BaseMacroPUnOp {
public:
    static Ptr op(const Ptr &x) {return bool(x->as<BaseMacro>());}
};

class UserMacroPUnOp {
public:
    static Ptr op(const Ptr &x) {return bool(x->as<MacroClosure>());}
};

class ValuePUnOp {
public:
    static Ptr op(const Ptr &x) {return bool(x->as<ValueBase>());}
};
