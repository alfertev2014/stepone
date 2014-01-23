#ifndef INTEGERS_H
#define INTEGERS_H

#include "stepone.h"

class Integer : public SpecType {
    int i;
public:
    Integer(int _i) : i(_i) {}
    int getInteger() const {return i;}

    virtual bool isInteger() const {return true;}
    virtual Integer * asInteger() {return this;}

    string toString() const {return string("{i: ") << i << "}"; }
};

class FIntP : public Operation
{
protected:
    Ob::Ptr applyX(const Ptr &x)
    {
        SpecType * stx = x->asSpecType();
        Integer * i = stx->asInteger();
        return i == 0 ? Ob::anil : Ob::at;
    }

public:
    string toString() const {return "{FIntP}";}
};

class FIntToFloat : public Operation
{
protected:
    Ptr applyX(const Ptr &x)
    {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        Integer * i = stx->asInteger();
        if(i == 0) throw 0;
        return new Float(i->getInteger());
    }

public:
    string toString() const
    {return "{FIntToFloat}";}
};

template <typename BinOp>
class FIntBinOp : public Operation
{
    class FIntBinOp2 : public Operation
    {
        int i1;
    public:
        FIntBinOp2(int _i1) : i1(_i1) {}
    protected:
        Ptr applyX(const Ptr &x)
        {
            SpecType * stx = x->asSpecType();
            if(stx == 0) throw 0;
            Integer * i = stx->asInteger();
            if(i == 0) throw 0;
            return new Integer(BinOp::op(i1, i->getInteger()));
        }
    public:
        string toString() const
        {return "FIntBinOp2{" + i1 + BinOp::toString() + "}";}
    };
protected:
    Ptr applyX(const Ptr &x)
    {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        Integer * i = stx->asInteger();
        if(i == 0) throw 0;
        return new FIntBinOp2(i->getValue());
    }

public:
    string toString() const {return "FIntBinOp{" + BinOp::toString() + "}";}
};

#endif // INTEGERS_H
