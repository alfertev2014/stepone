#pragma once

#include "core.h"
#include <sstream>

template <class T>
string valueToString(T x) {
    stringstream ss;
    ss << x;
    return ss.str();
}

template <typename T>
string cppTypeToString() {return "cppType";}

template <> inline string cppTypeToString<int>() {return "int";}
template <> inline string cppTypeToString<float>() {return "float";}
template <> inline string cppTypeToString<char>() {return "char";}

template <class T>
class ValueType : public Value {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<ValueType<T> >::instance;}
private:
    T t;
public:
    ValueType(const T & _t) : t(_t) {}
    T getValue() const {return t;}
    char *getValuePointer() {return reinterpret_cast<char *>(&t);}
};

template <class T1, class T2>
class ValueTypeCastUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {
        return new ValueType<T2>(x->cast<ValueType<T1> >()->getValue());
    }
};

template <typename T, typename CppUnOp>
class ValueTypeUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr & x) {
        return new ValueType<T>(CppUnOp::op(x->cast<ValueType<T> >()->getValue()));
    }
};

template <typename T, typename CppBinOp>
class ValueTypeBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr & x1, const Ob::Ptr & x2) {
        return new ValueType<T>(CppBinOp::op(x1->cast<ValueType<T> >()->getValue(), x2->cast<ValueType<T> >()->getValue()));
    }
};

template <typename T, typename CppCmpOp>
class ValueTypeCmpOp {
public:
    static Ob::Ptr op(const Ob::Ptr & x1, const Ob::Ptr & x2) {
        return CppCmpOp::op(x1->cast<ValueType<T> >()->getValue(), x2->cast<ValueType<T> >()->getValue());
    }
};
