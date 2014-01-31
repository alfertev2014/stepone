#ifndef INTEGERS_H
#define INTEGERS_H

#include <sstream>
#include "core.h"

class Integer : public SpecType {
    int i;
public:
    Integer(int _i) : i(_i) {}
    int getInteger() const {return i;}

    virtual bool isInteger() const {return true;}
    virtual Integer * asInteger() {return this;}

    string toString() const {
        stringstream ss;
        ss << "{i: " << i << "}";
        return ss.str();
    }
};

class FIntP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) return Ob::anil;
        Integer * i = stx->asInteger();
        return i == 0 ? Ob::anil : Ob::at;
    }

public:
    string toString() const {return "{FIntP}";}
};

template <typename BinOp>
class FIntBinOp : public BaseFunction {
    class FIntBinOp2 : public BaseFunction {
        int i1;
    public:
        FIntBinOp2(int _i1) : i1(_i1) {}
    protected:
        Ptr applyX(const Ptr &x) {
            SpecType * stx = x->asSpecType();
            if(stx == 0) throw 0;
            Integer * i = stx->asInteger();
            if(i == 0) throw 0;
            return new Integer(BinOp::op(i1, i->getInteger()));
        }
    public:
        string toString() const {
            stringstream ss;
            ss << "FIntBinOp2{" << i1 << BinOp::toString() << "}";
            return ss.str();
        }
    };
protected:
    Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        Integer * i = stx->asInteger();
        if(i == 0) throw 0;
        return new FIntBinOp2(i->getInteger());
    }

public:
    string toString() const {
        stringstream ss;
        ss << "FIntBinOp{" << BinOp::toString() << "}";
        return ss.str();
    }
};

template <class CmpOp>
class FIntCmpOp : public BaseFunction {
    class FIntCmpOp2 : public BaseFunction {
        int i1;
    public:
        FIntCmpOp2(int _i1) : i1(_i1) {}
    protected:
        Ptr applyX(const Ptr &x) {
            SpecType * stx = x->asSpecType();
            if(stx == 0) throw 0;
            Integer * i = stx->asInteger();
            if(i == 0) throw 0;
            return CmpOp::op(i1, i->getInteger()) ? Ob::at : Ob::anil;
        }
    public:
        string toString() const {
            stringstream ss;
            ss << "FIntCmpOp2{" << i1 << CmpOp::toString() << "}";
            return ss.str();
        }
    };
protected:
    Ptr applyX(const Ptr &x)
    {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        Integer * i = stx->asInteger();
        if(i == 0) throw 0;
        return new FIntCmpOp2(i->getInteger());
    }

public:
    string toString() const {
        stringstream ss;
        ss << "FIntCmpOp{" << CmpOp::toString() << "}";
        return ss.str();
    }
};

#endif // INTEGERS_H
