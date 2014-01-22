#ifndef NUMFUNCTEMP_H
#define NUMFUNCTEMP_H

#include "typestemp.h"

template <class T>
class PlusBinOp
{
public:
    inline static T op(T x1, T x2) {return x1 + x2;}

    static string toString() {return "+";}
};

template <class T>
class MinusBinOp
{
public:
    inline static T op(T x1, T x2) {return x1 - x2;}

    static string toString() {return "-";}
};

template <class T>
class ProductBinOp
{
public:
    inline static T op(T x1, T x2) {return x1 * x2;}

    static string toString() {return "*";}
};



template <class T>
class DivisionBinOp
{
public:
    inline static T op(T x1, T x2) {return x1 / x2;}

    static string toString() {return "/";}
};

template <class T>
class ModBinOp
{
public:
    inline static T op(T x1, T x2) {return x1 % x2;}

    static string toString() {return "%";}
};

template <class T, class CmpOp>
class FCompareOp : public Operation
{
    class FCompareOp2 : public Operation
    {
        T t1;
    public:
        FCompareOp2(int _t1) : t1(_t1) {}
    protected:
        Ptr applyX(const Ptr &x)
        {
            SpecType * stx = x->asSpecType();
            if(stx == 0) throw 0;
            return CmpOp::op(t1, stx->cast<SpecTypeTemp<T> >()->getValue()) ? Ob::at : Ob::anil;
        }
    public:
        string toString() const
        {return "FCompareOp2{" + typeToString<T>() + ": " + valueToString(t1) + CmpOp::toString() + "}";}
    };
protected:
    Ptr applyX(const Ptr &x)
    {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        return new FCompareOp2(stx->cast<SpecTypeTemp<T> >()->getValue());
    }

public:
    string toString() const {return "FCompareOp{" + typeToString<T>() + CmpOp::toString() + "}";}
};

template <class T>
class EqlCmpOp
{
public:
    inline static bool op(T x1, T x2) {return x1 == x2;}

    static string toString() {return "=";}
};

template <class T>
class NECmpOp
{
public:
    inline static bool op(T x1, T x2) {return x1 != x2;}

    static string toString() {return "!=";}
};

template <class T>
class LTCmpOp
{
public:
    inline static bool op(T x1, T x2) {return x1 < x2;}

    static string toString() {return "<";}
};

template <class T>
class GTCmpOp
{
public:
    inline static bool op(T x1, T x2) {return x1 > x2;}

    static string toString() {return ">";}
};

template <class T>
class LECmpOp
{
public:
    inline static bool op(T x1, T x2) {return x1 <= x2;}

    static string toString() {return "<=";}
};

template <class T>
class GECmpOp
{
public:
    inline static bool op(T x1, T x2) {return x1 >= x2;}

    static string toString() {return ">=";}
};

typedef SpecTypeTemp<int> SpecTypeInteger;
typedef SpecTypeTemp<float> SpecTypeFloat;
typedef SpecTypeTemp<double> SpecTypeDouble;


#endif // NUMFUNCTEMP_H
