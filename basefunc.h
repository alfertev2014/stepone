#ifndef BASEFUNC_H
#define BASEFUNC_H

#include "core.h"

class FCar : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->car();}
public:
    string toString() const {return "FCar";}
};

class FCdr : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->cdr();}
public:
    string toString() const {return "FCdr";}
};

class FCons : public BaseFunction {
    class FCons2 : public BaseFunction {
        Ob::Ptr x1;
    public:
        FCons2(const Ob::Ptr & _x1) : x1(_x1){}
    protected:
        Ob::Ptr applyX(const Ptr &x) {return new Pair(x1, x);}
    public:
        string toString() const {return "{Fcons2 " + x1->toString() + "}";}
    };
protected:
    Ob::Ptr applyX(const Ptr &x) {return new FCons2(x);}
public:
    string toString() const {return "FCons";}
};

class FEq : public BaseFunction {
    class FEq2 : public BaseFunction {
        Ob::Ptr x1;
    public:
        FEq2(const Ob::Ptr & _x1) : x1(_x1) {}
    protected:
        Ob::Ptr applyX(const Ob::Ptr &x) {return x1 == x ? Ob::at : Ob::anil;}
    public:
        string toString() const {return "{FEq2 " + x1->toString() + "}";}
    };
protected:
    Ob::Ptr applyX(const Ptr &x) {return new FEq2(x);}
public:
    string toString() const {return "FEq";}
};

class FContextGet : public BaseFunction {
    class FContextGet2 : public BaseFunction {
        Ob::Ptr x1;
    public:
        FContextGet2(const Ob::Ptr & _x1) : x1(_x1) {}
    protected:
        Ob::Ptr applyX(const Ob::Ptr &x) {
            Evaluator * ev = x1->asEvaluator();
            if(ev == 0) throw 0;
            return ev->getContext()->assoc(x);
        }
    public:
        string toString() const {return "{FContextGet2 " + x1->toString() + "}";}
    };
protected:
    Ob::Ptr applyX(const Ptr &x) {return new FContextGet2(x);}
public:
    string toString() const {return "FContextGet";}
};

class FContextPush : public BaseFunction {
    class FContextPush2 : public BaseFunction {
        class FContextPush3 : public BaseFunction {
            Ob::Ptr x1;
            Ob::Ptr x2;
        public:
            FContextPush3(const Ob::Ptr & _x1, const Ob::Ptr & _x2) : x1(_x1), x2(_x2) {}
        protected:
            Ob::Ptr applyX(const Ob::Ptr &x) {
                Evaluator * ev = x1->asEvaluator();
                if(ev == 0) throw 0;
                return new Evaluator(new Context(x2, x, ev->getContext()));
            }
        public:
            string toString() const {return "{FContextPush3 " + x1->toString() + ", " + x2->toString() + "}";}
        };

        Ob::Ptr x1;
    public:
        FContextPush2(const Ob::Ptr & _x1) : x1(_x1) {}
    protected:
        Ob::Ptr applyX(const Ob::Ptr &x) {
            return new FContextPush3(x1, x);
        }
    public:
        string toString() const {return "{FContextPush2 " + x1->toString() + "}";}
    };
protected:
    Ob::Ptr applyX(const Ptr &x) {return new FContextPush2(x);}
public:
    string toString() const {return "FContextPush";}
};

class BaseFunctions {
    BaseFunctions(){}
public:
    static const Ob::Ptr fcar;
    static const Ob::Ptr fcdr;
    static const Ob::Ptr fcons;
    static const Ob::Ptr feq;
    static const Ob::Ptr fctxget;
    static const Ob::Ptr fctxpush;
};

#endif // BASEFUNC_H
