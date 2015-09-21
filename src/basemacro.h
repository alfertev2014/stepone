#pragma once

#include "core.h"

class MQuote : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MQuote>::instance;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p;
    }
};

class MApply : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MApply>::instance;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p->car()->eval(a)->apply(p->cdr(), a);
    }
};

class MIf : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MIf>::instance;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        if(p->car()->eval(a) == Ob::anil)
            return p->cdr()->cdr()->eval(a);
        else
            return p->cdr()->car()->eval(a);
    }
};

class MLet : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MLet>::instance;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        Ob::Ptr val = p->cdr();
        return val->cdr()->eval(Context::make(p->car(), val->car()->eval(a), a));
    }
};

class MLazy : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MLazy>::instance;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Lazy(p, a);
    }
};

class MUnlazy : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MUnlazy>::instance;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p->eval(a)->unlazy();
    }
};

class MLabel : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MLabel>::instance;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return Label::loop(p->car(), p->cdr(), a);
    }
};

class MLambda : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MLambda>::instance;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Closure(p->car(), p->cdr(), a);
    }
};

class MMacro : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MMacro>::instance;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new MacroClosure(p->car(), p->cdr(), a);
    }
};

class MCurrentContext : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MCurrentContext>::instance;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new CurrentContext(p->car(), p->cdr(), a);
    }
};

class MTry : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MTry>::instance;}
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
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        throw SemanticError();
    }
};

class MGenSymbol : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MGenSymbol>::instance;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Symbol;
    }
};

