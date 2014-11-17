#pragma once

#include "core.h"

class MQuote : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MQuote>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p;
    }

    string toString() const {return "{MQuote}";}
};

class MApply : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MApply>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p->car()->eval(a)->apply(p->cdr(), a);
    }

    string toString() const {return "{MApply}";}
};

class MIf : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MIf>::type_id;}
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
    Ptr getTypeId() const {return TypeInfo<MLet>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        Ob::Ptr val = p->cdr();
        return val->cdr()->eval(new Context(p->car(), val->car()->eval(a), a));
    }

    string toString() const {return "{MLet}";}
};

class MLazy : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MLazy>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Lazy(p, a);
    }

    string toString() const {return "{MLazy}";}
};

class MUnlazy : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MUnlazy>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p->eval(a)->unlazy();
    }

    string toString() const {return "{MUnlazy}";}
};

class MLabel : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MLabel>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return Label::loop(p->car(), p->cdr(), a);
    }

    string toString() const {return "{MLabel}";}
};

class MLambda : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MLambda>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Closure(p->car(), p->cdr(), a);
    }

    string toString() const {return "{MLambda}";}
};

class MMacro : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MMacro>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new MacroClosure(p->car(), p->cdr(), a);
    }

    string toString() const {return "{MMacro}";}
};

class MCurrentContext : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MCurrentContext>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new CurrentContext(p->car(), p->cdr(), a);
    }

    string toString() const {return "{MCurrentContext}";}
};

class MTry : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MTry>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        try {
            return p->car()->eval(a);
        } catch(SemanticError e) {
            return p->cdr()->eval(a);
        }
    }

    string toString() const {return "{MTry}";}
};

class MBot : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MBot>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        throw SemanticError();
    }

    string toString() const {return "{MBot}";}
};

class MGenSymbol : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MGenSymbol>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Symbol;
    }

    string toString() const {return "{MGenSymbol}";}
};

class MGetType : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MGetType>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p->eval(a)->getTypeId();
    }

    string toString() const {return "{MGetType}";}
};

class BaseMacroses {
    BaseMacroses(){}
public:
    static const Ob::Ptr mquote;
    static const Ob::Ptr mapply;
    static const Ob::Ptr mif;
    static const Ob::Ptr mlet;
    static const Ob::Ptr mlazy;
    static const Ob::Ptr munlazy;
    static const Ob::Ptr mlabel;
    static const Ob::Ptr mlambda;
    static const Ob::Ptr mmacro;
    static const Ob::Ptr mcurctx;
    static const Ob::Ptr mtry;
    static const Ob::Ptr mbot;
    static const Ob::Ptr mgensym;
    static const Ob::Ptr mgettype;
};
