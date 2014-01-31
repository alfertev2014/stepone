#ifndef FLOATS_H
#define FLOATS_H

#include "core.h"

class Float : public SpecType {
    float f;
public:
    Float(float _f) : f(_f) {}
    float getFloat() const {return f;}

    virtual bool isFloat() const {return true;}
    virtual Float * asFloat() {return this;}

    string toString() const {
        stringstream ss;
        ss << "{f: " << f << "}";
        return ss.str();
    }
};

class FFloatP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) return Ob::anil;
        Float * f = stx->asFloat();
        return f == 0 ? Ob::anil : Ob::at;
    }

public:
    string toString() const {return "{FFloatP}";}
};

template <typename BinOp>
class FFloatBinOp : public BaseFunction {
    class FFloatBinOp2 : public BaseFunction {
        float f1;
    public:
        FFloatBinOp2(float _f1) : f1(_f1) {}
    protected:
        Ptr applyX(const Ptr &x) {
            SpecType * stx = x->asSpecType();
            if(stx == 0) throw 0;
            Float * f = stx->asFloat();
            if(f == 0) throw 0;
            return new Float(BinOp::op(f1, f->getFloat()));
        }
    public:
        string toString() const {
            stringstream ss;
            ss << "FFloatBinOp2{" << f1 << BinOp::toString() << "}";
            return ss.str();
        }
    };
protected:
    Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        Float * f = stx->asFloat();
        if(f == 0) throw 0;
        return new FFloatBinOp2(f->getFloat());
    }

public:
    string toString() const {
        stringstream ss;
        ss << "FFloatBinOp{" << BinOp::toString() << "}";
        return ss.str();
    }
};

template <class CmpOp>
class FFloatCmpOp : public BaseFunction {
    class FFloatCmpOp2 : public BaseFunction {
        float f1;
    public:
        FFloatCmpOp2(float _f1) : f1(_f1) {}
    protected:
        Ptr applyX(const Ptr &x) {
            SpecType * stx = x->asSpecType();
            if(stx == 0) throw 0;
            Float * f = stx->asFloat();
            if(f == 0) throw 0;
            return CmpOp::op(f1, f->getFloat()) ? Ob::at : Ob::anil;
        }
    public:
        string toString() const {
            stringstream ss;
            ss << "FFloatCmpOp2{" << f1 << CmpOp::toString() << "}";
            return ss.str();
        }
    };
protected:
    Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        Float * f = stx->asFloat();
        if(f == 0) throw 0;
        return new FFloatCmpOp2(f->getFloat());
    }

public:
    string toString() const {
        stringstream ss;
        ss << "FFloatCmpOp{" << CmpOp::toString() << "}";
        return ss.str();
    }
};

#endif // FLOATS_H
