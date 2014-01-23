#ifndef BASEMACRO_H
#define BASEMACRO_H

#include "stepone.h"

class MQuote : public Macro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p;
    }
};

class MIf : public Macro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        if(p->car()->eval(a) == Ob::anil)
            return p->cdr()->cdr()->eval(a);
        else
            return p->cdr()->car()->eval(a);
    }
};

class MLambda : public Macro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Closure(p->car(), p->cdr(), a);
    }
};

class MLet : public Macro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        Ob::Ptr val = p->cdr();
        return val->cdr()->eval(new Context(p->car(), val->car()->eval(a), a));
    }
};

class MLazy : public Macro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Lazy(p, a);
    }
};

class MUnlazy : public Macro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p->eval(a)->unlazy();
    }
};

class MLabel : public Macro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Label(p->car(), p->cdr(), a);
    }
};

class MEval : public Macro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return p->eval(a)->eval(a);
    }
};

class BaseMacro {
private:
    BaseMacro(){}
public:
    static const Ob::Ptr mif;
    static const Ob::Ptr mquote;
    static const Ob::Ptr mlambda;
    static const Ob::Ptr mlet;
    static const Ob::Ptr mlazy;
    static const Ob::Ptr munlazy;
    static const Ob::Ptr mlabel;
    static const Ob::Ptr meval;
};


#endif // BASEMACRO_H
