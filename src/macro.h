#pragma once

#include "core.h"

class Macro : public Const {
public:
    Macro() : Const() {
        typeFlags.constType = TypeFlags::Macro;
    }
    virtual ~Macro() {}
};

class Evaluator : public Macro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Evaluator>::instance;}
private:
    Ptr a;
public:
    static const Ptr eempty;

    Evaluator(Ptr _a) : Macro(), a(_a) {
        typeFlags.macroValueType = TypeFlags::Evaluator;
    }

    Ptr getContext() const {return a;}

    Ptr apply(const Ptr &p, const Ptr &a) {return p->eval(a)->eval(this->a);}
};

class BaseMacro : public Macro {
public:
    virtual ~BaseMacro(){}
};

/// TODO: remove it
class Closure : public Macro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Closure>::instance;}
private:
    Ptr sp;
    Ptr e;
    Ptr a;
public:
    Closure(const Ptr & _sp, const Ptr & _e, const Ptr & _a)
        : Macro(), sp(_sp), e(_e), a(_a) {}

    Ptr apply(const Ptr &p, const Ptr &a) {
        if(p == Ob::anil)
            return this;
        return e->eval(Context::make(sp, p->car()->eval(a), this->a))->apply(p->cdr(), a);
    }
};

class MacroClosure : public Macro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MacroClosure>::instance;}
private:
    Ptr sp;
    Ptr e;
    Ptr a;
public:
    MacroClosure(const Ptr & _sp, const Ptr & _e, const Ptr & _a)
        : Macro(), sp(_sp), e(_e), a(_a) {
        typeFlags.macroValueType = TypeFlags::MacroClosure;
    }

    Ptr apply(const Ptr &p, const Ptr &a) {
        return e->eval(Context::make(sp, p, this->a));
    }
};

class CurrentContext : public Macro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<CurrentContext>::instance;}
private:
    Ptr sa;
    Ptr e;
    Ptr a;
public:
    CurrentContext(const Ptr & _sa, const Ptr & _e, const Ptr & _a)
        : Macro(), sa(_sa), e(_e), a(_a) {
        typeFlags.macroValueType = TypeFlags::CurrentContext;
    }

    Ptr apply(const Ptr &p, const Ptr &a) {
        return e->eval(Context::make(sa, new Evaluator(a), this->a))->apply(p, this->a);
    }
};
