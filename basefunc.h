#ifndef BASEFUNC_H
#define BASEFUNC_H

#include "stepone.h"

class FCar : public Operation
{
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->car();}
public:
    string toString() const {return "FCar";}
};

class FCdr : public Operation
{
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->cdr();}
public:
    string toString() const {return "FCdr";}
};

class FCons : public Operation
{
    class FCons2 : public Operation
    {
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

class FAtom : public Operation
{
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isAtom() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FAtom";}
};

class FEq : public Operation
{
    class FEq2 : public Operation
    {
        Ob::Ptr x1;
    public:
        FEq2(const Ob::Ptr & _x1) : x1(_x1) {}
    protected:
        Ob::Ptr applyX(const Ob::Ptr &x) {return x1 == x ? Ob::at : Ob::anil;}
    public:
        string toString() const {return "{FEq " + x1->toString() + "}";}
    };
protected:
    Ob::Ptr applyX(const Ptr &x) {return new FEq2(x);}
public:
    string toString() const {return "FEq";}
};


class BaseFunc
{
    BaseFunc(){}
public:
    static const Ob::Ptr fcar;
    static const Ob::Ptr fcdr;
    static const Ob::Ptr fcons;
    static const Ob::Ptr fatom;
    static const Ob::Ptr feq;
};

#endif // BASEFUNC_H
