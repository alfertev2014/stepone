#pragma once

#include <core.h>
#include <macro.h>
#include <value.h>

class PairPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->as<Pair>());}
};

class LazyPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->as<Lazy>());}
};

class LabelPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->as<Label>());}
};

class AtomPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->as<Atom>());}
};

class SymbolPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->as<Symbol>());}
};

class ConstPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->as<Const>());}
};

class MacroPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->as<Macro>());}
};

class EvaluatorPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->as<Evaluator>());}
};

class BaseMacroPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->as<BaseMacro>());}
};

class UserMacroPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->as<MacroClosure>());}
};

class ValuePUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->as<ValueBase>());}
};
