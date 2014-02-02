#ifndef FUNCSTEMP_H
#define FUNCSTEMP_H

#include "core.h"

template <class T>
class FTypeP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FTypeP<T> >::type_id;}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->is<T>() ? Ob::anil : Ob::at;}
public:
    string toString() const {return "FTypeP{" + T::getTypeString() + "}";}
};

template <class BinOp>
class FBinaryOp : public BaseFunction {
    class FBinaryOp2 : public BaseFunction {
        Ptr x1;
    public:
        FBinaryOp2(const Ptr & _x1) : x1(_x1) {}
    protected:
        Ptr applyX(const Ptr &x) {return BinOp::op(x1, x);}
    public:
        string toString() const {return "FBinaryOp2{" + x1->toString() + " " + BinOp::toString() + "}";}
    };
protected:
    Ptr applyX(const Ptr &x) {return new FBinaryOp2(x);}
public:
    string toString() const {return "FBinaryOp{" + BinOp::toString() + "}";}
};

template <class TerOp>
class FTernaryOp : public BaseFunction {
    class FTernaryOp2 : public BaseFunction {
        class FTernaryOp3 : public BaseFunction {
            Ptr x1;
            Ptr x2;
        public:
            FTernaryOp3(const Ptr & _x1, const Ptr & _x2) : x1(_x1), x2(_x2) {}
        protected:
            Ptr applyX(const Ptr &x) {return TerOp::op(x1, x2, x);}
        public:
            string toString() const {return "FTernaryOp3{" + TerOp::toString() + x1->toString() + " " + x2->toString() + "}";}
        };
        Ptr x1;
    public:
        FTernaryOp2(const Ptr & _x1) : x1(_x1) {}
    protected:
        Ptr applyX(const Ptr &x) {return new FTernaryOp2(x1, x);}
    public:
        string toString() const {return "FTernaryOp2{" + TerOp::toString() + " " + x1->toString() + "}";}
    };
protected:
    Ptr applyX(const Ptr &x) {return new FTernaryOp2(x);}
public:
    string toString() const {return "FTernaryOp{" + TerOp::toString() + "}";}
};


#endif // FUNCSTEMP_H
