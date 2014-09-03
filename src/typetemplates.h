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
    Ptr getTypeId() const {return TypeInfo<ValueType<T> >::type_id;}
    static string getTypeString() {return "ValueType{" + cppTypeToString<T>() + "}";}
    string typeToString() const {return getTypeString();}
private:
    T t;
public:
    ValueType(const T & _t) : t(_t) {}
    T getValue() const {return t;}
    string toString() const {return "[" + cppTypeToString<T>() + ": " + valueToString(t) + "]";}
};

template <class T1, class T2>
class FValueTypeCast : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FValueTypeCast>::type_id;}
    static string getTypeString() {return "FValueTypeCast";}
    string typeToString() const {return getTypeString();}
protected:
    Ptr applyX(const Ptr &x) {
        return new ValueType<T2>(x->cast<ValueType<T1> >()->getValue());
    }
public:
    string toString() const {return "FValueTypeCast{" + cppTypeToString<T1>() + " -> " + cppTypeToString<T2>() + "}";}
};

template <typename T, typename CppUnOp>
class ValueTypeUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr & x1) {
        return new ValueType<T>(CppUnOp::op(x1->cast<ValueType<T> >()->getValue()));
    }

    static string toString() {return "ValueTypeUnOp{" + CppUnOp::toString() + "}";}
};

template <typename T, typename CppBinOp>
class ValueTypeBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr & x1, const Ob::Ptr & x2) {
        return new ValueType<T>(CppBinOp::op(x1->cast<ValueType<T> >()->getValue(), x2->cast<ValueType<T> >()->getValue()));
    }

    static string toString() {return "ValueTypeBinOp{" + CppBinOp::toString() + "}";}
};

template <typename T, typename CppCmpOp>
class ValueTypeCmpOp {
public:
    static Ob::Ptr op(const Ob::Ptr & x1, const Ob::Ptr & x2) {
        return CppCmpOp::op(x1->cast<ValueType<T> >()->getValue(), x2->cast<ValueType<T> >()->getValue()) ? Ob::at : Ob::anil;
    }

    static string toString() {return "ValueTypeCmpOp{" + CppCmpOp::toString() + "}";}
};
