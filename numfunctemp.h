#ifndef NUMFUNCTEMP_H
#define NUMFUNCTEMP_H

#include <string>

using namespace std;

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

#endif // NUMFUNCTEMP_H
