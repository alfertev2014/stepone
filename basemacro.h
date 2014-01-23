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
        Ob::Ptr val = pcdr->cdr();
        return val->cdr()->eval(new Context(pcdr->car(), val->car()->eval(a), a));
    }
};

class MLazy : public Macro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return new Lazy(pcdr, a);
    }
};

class MUnlazy : public Macro {
public:
    Ob::Ptr apply(const Ptr &p, const Ptr &a) {
        return pcdr->eval(a)->unlazy();
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



#endif // BASEMACRO_H
