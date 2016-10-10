#pragma once

#include <vector.h>

class VectorLengthUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {return new Value<int>(x->cast<Vector>()->getSize());}
};

class FMakeVector : public BaseMacro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<FMakeVector>::instance;}

    Ptr apply(const Ptr &p, const Ptr &a) {
        int n = p->car()->eval(a)->cast<Value<int> >()->getValue();
        return Vector::fromList(n, p->cdr(), a);
    }
};

class VectorElBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return x1->cast<Vector>()->array[x2->cast<Value<int> >()->getValue()];
    }
};

class VectorCloneUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {
        return x->cast<Vector>()->clone();
    }
};

class VectorConcatBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        return x1->cast<Vector>()->concat(x2->cast<Vector>());
    }
};

class VectorMidTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return x1->cast<Vector>()->mid(x2->cast<Value<int> >()->getValue(), x3->cast<Value<int> >()->getValue());
    }
};

class VectorSliceTerOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2, const Ob::Ptr &x3) {
        return x1->cast<Vector>()->mid(x2->cast<Value<int> >()->getValue(), x3->cast<Value<int> >()->getValue());
    }
};

