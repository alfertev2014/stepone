#pragma once

#include "core.h"

class PairPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asPair());}
    static string toString() {return "pair?";}
};

class LazyPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asLazy());}
    static string toString() {return "lazy?";}
};

class LabelPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asLabel());}
    static string toString() {return "label?";}
};

class AtomPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asAtom());}
    static string toString() {return "atom?";}
};

class SymbolPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asSymbol());}
    static string toString() {return "symbol?";}
};

class ConstPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asConst());}
    static string toString() {return "const?";}
};

class MacroPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asMacro());}
    static string toString() {return "macro?";}
};

class EvaluatorPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asEvaluator());}
    static string toString() {return "evaluator?";}
};

class BaseMacroPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asBaseMacro());}
    static string toString() {return "base-macro?";}
};

class UserMacroPUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asMacroClosure());}
    static string toString() {return "user-macro?";}
};

class ValuePUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return bool(x->asValue());}
    static string toString() {return "value?";}
};
