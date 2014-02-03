#ifndef BASEMACRO_H
#define BASEMACRO_H

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

class MLambda : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MLambda>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Closure(p->car(), p->cdr(), a);
    }

    string toString() const {return "{MLambda}";}
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
        return new Label(p->car(), p->cdr(), a);
    }

    string toString() const {return "{MLabel}";}
};

class MMacro : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MMacro>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        Ob::Ptr p1 = p->cdr();
        return new UserMacro(p->car(), p1->car(), p1->cdr(), a);
    }

    string toString() const {return "{MMacro}";}
};

class MEval : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<MEval>::type_id;}
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p->eval(a)->eval(a);
    }

    string toString() const {return "{MEval}";}
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

class BaseMacroses {
    BaseMacroses(){}
public:
    static const Ob::Ptr mif;
    static const Ob::Ptr mquote;
    static const Ob::Ptr mlambda;
    static const Ob::Ptr mlet;
    static const Ob::Ptr mlazy;
    static const Ob::Ptr munlazy;
    static const Ob::Ptr mlabel;
    static const Ob::Ptr mmacro;
    static const Ob::Ptr meval;
    static const Ob::Ptr mgensym;
};


#endif // BASEMACRO_H
