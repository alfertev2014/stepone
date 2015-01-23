#pragma once

#include "core.h"

class MQuote : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MQuote>::instance;}
    static string getTypeString() {return "MQuote";}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p;
    }
};

class MApply : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MApply>::instance;}
    static string getTypeString() {return "MApply";}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p->car()->eval(a)->apply(p->cdr(), a);
    }
};

class MIf : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MIf>::instance;}
    static string getTypeString() {return "MIf";}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        if(p->car()->eval(a) == Ob::anil)
            return p->cdr()->cdr()->eval(a);
        else
            return p->cdr()->car()->eval(a);
    }

    string toString() const {return "{MIf}";}
};

class MLet : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MLet>::instance;}
    static string getTypeString() {return "MLet";}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        Ob::Ptr val = p->cdr();
        return val->cdr()->eval(new Context(p->car(), val->car()->eval(a), a));
    }
};

class MLazy : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MLazy>::instance;}
    static string getTypeString() {return "MLazy";}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Lazy(p, a);
    }
};

class MUnlazy : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MUnlazy>::instance;}
    static string getTypeString() {return "MUnlazy";}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p->eval(a)->unlazy();
    }
};

class MLabel : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MLabel>::instance;}
    static string getTypeString() {return "MLabel";}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return Label::loop(p->car(), p->cdr(), a);
    }
};

class MLambda : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MLambda>::instance;}
    static string getTypeString() {return "MLambda";}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Closure(p->car(), p->cdr(), a);
    }
};

class MMacro : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MMacro>::instance;}
    static string getTypeString() {return "MMacro";}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new MacroClosure(p->car(), p->cdr(), a);
    }
};

class MCurrentContext : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MCurrentContext>::instance;}
    static string getTypeString() {return "MCurrentContext";}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new CurrentContext(p->car(), p->cdr(), a);
    }
};

class MTry : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MTry>::instance;}
    static string getTypeString() {return "MTry";}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        try {
            return p->car()->eval(a);
        } catch(SemanticError e) {
            return p->cdr()->eval(a);
        }
    }
};

class MBot : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MBot>::instance;}
    static string getTypeString() {return "MBot";}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        throw SemanticError();
    }
};

class MGenSymbol : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MGenSymbol>::instance;}
    static string getTypeString() {return "MGenSymbol";}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Symbol;
    }
};

class BaseMacroses {
    BaseMacroses();
public:
    static const BaseMacroses &inst();

    const Ob::Ptr mquote;
    const Ob::Ptr mapply;
    const Ob::Ptr mif;
    const Ob::Ptr mlet;
    const Ob::Ptr mlazy;
    const Ob::Ptr munlazy;
    const Ob::Ptr mlabel;
    const Ob::Ptr mlambda;
    const Ob::Ptr mmacro;
    const Ob::Ptr mcurctx;
    const Ob::Ptr mtry;
    const Ob::Ptr mbot;
    const Ob::Ptr mgensym;
};
