#ifndef BASEMACRO_H
#define BASEMACRO_H

#include "stepone.h"

class MQuote : public BaseMacro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p;
    }

    string toString() const {return "{MQuote}";}
};

class MIf : public BaseMacro {
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
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Closure(p->car(), p->cdr(), a);
    }

    string toString() const {return "{MLambda}";}
};

class MLet : public BaseMacro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        Ob::Ptr val = p->cdr();
        return val->cdr()->eval(new Context(p->car(), val->car()->eval(a), a));
    }

    string toString() const {return "{MLet}";}
};

class MLazy : public BaseMacro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Lazy(p, a);
    }

    string toString() const {return "{MLazy}";}
};

class MUnlazy : public BaseMacro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p->eval(a)->unlazy();
    }

    string toString() const {return "{MUnlazy}";}
};

class MLabel : public BaseMacro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Label(p->car(), p->cdr(), a);
    }

    string toString() const {return "{MLabel}";}
};

class MMacro : public BaseMacro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        Ob::Ptr p1 = p->cdr();
        return new UserMacro(p->car(), p1->car(), p1->cdr(), a);
    }

    string toString() const {return "{MMacro}";}
};

class MEval : public BaseMacro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p->eval(a)->eval(a);
    }

    string toString() const {return "{MEval}";}
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
};


#endif // BASEMACRO_H
