#ifndef FUNCSTEMP_H
#define FUNCSTEMP_H

#include "core.h"

template <class T>
class FTypeP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FTypeP<T> >::type_id;}
    static string getTypeString() {return "FTypeP{" + T::getTypeString() + "}";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->is<T>() ? Ob::anil : Ob::at;}
public:
    string toString() const {return "FTypeP{" + T::getTypeString() + "}";}
};

template <class BinOp>
class FBinaryOp : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FBinaryOp<BinOp> >::type_id;}
    static string getTypeString() {return "FBinaryOp{" + BinOp::toString() + "}";}
    string typeToString() const {return getTypeString();}
private:
    class FBinaryOp2 : public BaseFunction {
    public:
        Ptr getTypeId() const {return TypeInfo<FBinaryOp2>::type_id;}
        static string getTypeString() {return "FBinaryOp2{" + BinOp::toString() + "}";}
        string typeToString() const {return getTypeString();}
    private:
        Ptr x1;
    public:
        FBinaryOp2(const Ptr & _x1) : x1(_x1) {}
    protected:
        Ptr applyX(const Ptr &x) {return BinOp::op(x1, x);}
    public:
        string toString() const {return "FBinaryOp2{" + BinOp::toString() + " " + x1->toString() + "}";}
    };
protected:
    Ptr applyX(const Ptr &x) {return new FBinaryOp2(x);}
public:
    string toString() const {return "FBinaryOp{" + BinOp::toString() + "}";}
};

template <class TerOp>
class FTernaryOp : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FTernaryOp<TerOp> >::type_id;}
    static string getTypeString() {return "FTernaryOp{" + TerOp::toString() + "}";}
    string typeToString() const {return getTypeString();}
private:
    class FTernaryOp2 : public BaseFunction {
    public:
        Ptr getTypeId() const {return TypeInfo<FTernaryOp2>::type_id;}
        static string getTypeString() {return "FTernaryOp2{" + TerOp::toString() + "}";}
        string typeToString() const {return getTypeString();}
    private:
        class FTernaryOp3 : public BaseFunction {
        public:
            Ptr getTypeId() const {return TypeInfo<FTernaryOp3>::type_id;}
            static string getTypeString() {return "FTernaryOp3{" + TerOp::toString() + "}";}
            string typeToString() const {return getTypeString();}
        private:
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
        Ptr applyX(const Ptr &x) {return new FTernaryOp3(x1, x);}
    public:
        string toString() const {return "FTernaryOp2{" + TerOp::toString() + " " + x1->toString() + "}";}
    };
protected:
    Ptr applyX(const Ptr &x) {return new FTernaryOp2(x);}
public:
    string toString() const {return "FTernaryOp{" + TerOp::toString() + "}";}
};

template <class NaryOp>
class FNaryOp : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FNaryOp<NaryOp> >::type_id;}
    static string getTypeString() {return "FNaryOp{" + NaryOp::toString() + "}";}
    string typeToString() const {return getTypeString();}
private:
    int i;
    int n;
    Ptr args;
public:
    FNaryOp(int _i, int _n, const Ptr & _args) :i(_i), n(_n), args(_args) {}
    string toString() const {return "FNaryOp{" + NaryOp::toString() + "}";}
protected:
    Ptr applyX(const Ptr &x) {
        if(i <= 1) return NaryOp::op(n, new Pair(x, args));
        return new FNaryOp<NaryOp>(i - 1, n, new Pair(x, args));
    }
};

#endif // FUNCSTEMP_H
