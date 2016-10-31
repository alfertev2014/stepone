#pragma once

#include "base.h"

class Macro : public Const {
public:
    Macro() : Const() {
        typeFlags.constType = TypeFlags::Macro;
    }
    virtual ~Macro();
};

class Evaluator : public Macro {
public:
    const TypeInfoBase * getTypeInfo() const;
private:
    Ptr a;
public:
    static const Ptr eempty;

    Evaluator(Ptr _a) : Macro(), a(_a) {
        typeFlags.macroValueType = TypeFlags::Evaluator;
    }
    Ptr getContext() const;
    Ptr apply(const Ptr &p, const Ptr &a);
};

class BaseMacro : public Macro {
public:
    const TypeInfoBase * getTypeInfo() const;
public:
    BaseMacro(): Macro() {
        typeFlags.macroValueType = TypeFlags::BaseMacro;
    }
    virtual ~BaseMacro();
};

/// TODO: remove it
class Closure : public Macro {
public:
    const TypeInfoBase * getTypeInfo() const;
private:
    Ptr sp;
    Ptr e;
    Ptr a;
public:
    Closure(const Ptr & _sp, const Ptr & _e, const Ptr & _a)
        : Macro(), sp(_sp), e(_e), a(_a) {}

    Ptr apply(const Ptr &p, const Ptr &a);
};

class MacroClosure : public Macro {
public:
    const TypeInfoBase * getTypeInfo() const;
private:
    Ptr sp;
    Ptr e;
    Ptr a;
public:
    MacroClosure(const Ptr & _sp, const Ptr & _e, const Ptr & _a)
        : Macro(), sp(_sp), e(_e), a(_a) {
        typeFlags.macroValueType = TypeFlags::MacroClosure;
    }

    Ptr apply(const Ptr &p, const Ptr &a);
};

class CurrentContext : public Macro {
public:
    const TypeInfoBase * getTypeInfo() const;
private:
    Ptr sa;
    Ptr e;
    Ptr a;
public:
    CurrentContext(const Ptr & _sa, const Ptr & _e, const Ptr & _a)
        : Macro(), sa(_sa), e(_e), a(_a) {
        typeFlags.macroValueType = TypeFlags::CurrentContext;
    }

    Ptr apply(const Ptr &p, const Ptr &a);
};

template<>
Macro *Ob::as<Macro>();

template<>
Evaluator *Ob::as<Evaluator>();

template<>
BaseMacro *Ob::as<BaseMacro>();

template<>
MacroClosure *Ob::as<MacroClosure>();

template<>
CurrentContext *Ob::as<CurrentContext>();

