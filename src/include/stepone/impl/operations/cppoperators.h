#pragma once

#include <string>

namespace stepone::operations {

template <class T>
class MinusUnOp {
public:
    inline static T op(T x) {return -x;}
};

template <class T>
class BitNotUnOp {
public:
    inline static T op(T x) {return ~x;}
};

template <class T>
class PlusBinOp {
public:
    inline static T op(T x1, T x2) {return x1 + x2;}
};

template <class T>
class MinusBinOp {
public:
    inline static T op(T x1, T x2) {return x1 - x2;}
};

template <class T>
class ProductBinOp {
public:
    inline static T op(T x1, T x2) {return x1 * x2;}
};

template <class T>
class DivisionBinOp {
public:
    inline static T op(T x1, T x2) {return x1 / x2;}
};

template <class T>
class ModBinOp {
public:
    inline static T op(T x1, T x2) {return x1 % x2;}
};

template <class T>
class BitAndBinOp {
public:
    inline static T op(T x1, T x2) {return x1 & x2;}
};

template <class T>
class BitOrBinOp {
public:
    inline static T op(T x1, T x2) {return x1 | x2;}
};

template <class T>
class BitXorBinOp {
public:
    inline static T op(T x1, T x2) {return x1 ^ x2;}
};

template <class T>
class BitSHLBinOp {
public:
    inline static T op(T x1, T x2) {return x1 << x2;}
};

template <class T>
class BitSHRBinOp {
public:
    inline static T op(T x1, T x2) {return x1 >> x2;}
};

template <class T>
class EqlCmpOp {
public:
    inline static bool op(T x1, T x2) {return x1 == x2;}
};

template <class T>
class NECmpOp {
public:
    inline static bool op(T x1, T x2) {return x1 != x2;}
};

template <class T>
class LTCmpOp {
public:
    inline static bool op(T x1, T x2) {return x1 < x2;}
};

template <class T>
class GTCmpOp {
public:
    inline static bool op(T x1, T x2) {return x1 > x2;}
};

template <class T>
class LECmpOp {
public:
    inline static bool op(T x1, T x2) {return x1 <= x2;}
};

template <class T>
class GECmpOp {
public:
    inline static bool op(T x1, T x2) {return x1 >= x2;}
};

} // namespaces
