#pragma once

#include "vector.h"


class VectorLengthUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return new ValueType<int>(x->cast<Vector>()->getSize());}
    static string toString() {return "vec-len";}
};

class FMakeVector : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<FMakeVector>::instance;}
    static string getTypeString() {return "FMakeVector";}

    Ptr apply(const Ptr &p, const Ptr &a) {
        int n = p->car()->eval(a)->cast<ValueType<int> >()->getValue();
        return Vector::fromList(n, p->cdr(), a);
    }
};

class VectorElBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return x1->cast<Vector>()->array[x2->cast<ValueType<int> >()->getValue()];
    }
    static string toString() {return "vec-el";}
};

class VectorCloneUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {
        return x->cast<Vector>()->clone();
    }
    static string toString() {return "vec-clone";}
};

class VectorConcatBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return x1->cast<Vector>()->concat(x2->cast<Vector>());
    }
    static string toString() {return "vec-cat";}
};

class VectorMidTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return x1->cast<Vector>()->mid(x2->cast<ValueType<int> >()->getValue(), x3->cast<ValueType<int> >()->getValue());
    }
    static string toString() {return "vec-mid";}
};

class VectorSliceTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return x1->cast<Vector>()->mid(x2->cast<ValueType<int> >()->getValue(), x3->cast<ValueType<int> >()->getValue());
    }
    static string toString() {return "vec-slice";}
};

