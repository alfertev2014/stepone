#ifndef FLOATS_H
#define FLOATS_H

#include "stepone.h"

class Float : public SpecType {
    Float f;
public:
    Float(Float _f) : f(_f) {}
    Float getFloat() const {return f;}

    virtual bool isFloat() const {return true;}
    virtual Float * asFloat() {return this;}

    string toString() const {return string("{f: ") << f << "}"; }
};

class FFloatP : public Operation
{
protected:
    Ob::Ptr applyX(const Ptr &x)
    {
        SpecType * stx = x->asSpecType();
        Float * f = stx != 0 ? stx->asFloat() : 0;
        return f == 0 ? Ob::anil : Ob::at;
    }

public:
    string toString() const {return "{FFloatP}";}
};

class FFloatToInt : public Operation
{
protected:
    Ptr applyX(const Ptr &x)
    {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        Float * f = stx->asFloat();
        if(f == 0) throw 0;
        return new Integer(f->getFloat());
    }

public:
    string toString() const
    {return "{FFloatToInt}";}
};

template <typename BinOp>
class FFloatBinOp : public Operation
{
    class FFloatBinOp2 : public Operation
    {
        Float i1;
    public:
        FFloatBinOp2(Float _i1) : i1(_i1) {}
    protected:
        Ptr applyX(const Ptr &x)
        {
            SpecType * stx = x->asSpecType();
            if(stx == 0) throw 0;
            Float * f = stx->asFloat();
            if(f == 0) throw 0;
            return new Float(BinOp::op(i1, f->getFloat()));
        }
    public:
        string toString() const
        {return "FFloatBinOp2{" + i1 + BinOp::toString() + "}";}
    };
protected:
    Ptr applyX(const Ptr &x)
    {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        Float * f = stx->asFloat();
        if(f == 0) throw 0;
        return new FFloatBinOp2(f->getValue());
    }

public:
    string toString() const {return "FFloatBinOp{" + BinOp::toString() + "}";}
};

template <class CmpOp>
class FFloatCmpOp : public Operation
{
    class FFloatCmpOp2 : public Operation
    {
        Float i1;
    public:
        FFloatCmpOp2(Float _i1) : i1(_i1) {}
    protected:
        Ptr applyX(const Ptr &x)
        {
            SpecType * stx = x->asSpecType();
            if(stx == 0) throw 0;
            Float * f = stx->asFloat();
            if(f == 0) throw 0;
            return CmpOp::op(i1, f->getFloat()) ? Ob::at : Ob::anil;
        }
    public:
        string toString() const
        {return "FFloatCmpOp2{" + i1 + CmpOp::toString() + "}";}
    };
protected:
    Ptr applyX(const Ptr &x)
    {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        Float * f = stx->asFloat();
        if(f == 0) throw 0;
        return new FFloatCmpOp2(f->getFloat());
    }

public:
    string toString() const {return "FFloatCmpOp{" + CmpOp::toString() + "}";}
};

#endif // FLOATS_H
