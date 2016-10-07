#pragma once

#include "core.h"
#include <sstream>

template <class T>
std::string valueToString(T x) {
    std::stringstream ss;
    ss << x;
    return ss.str();
}

template <typename T>
std::string cppTypeToString() {return "cppType";}

template <> inline std::string cppTypeToString<int>() {return "int";}
template <> inline std::string cppTypeToString<float>() {return "float";}
template <> inline std::string cppTypeToString<char>() {return "char";}

class ValueBase : public Const {
public:
    ValueBase() : Const() {
        typeFlags.constType = TypeFlags::ValueBase;
    }
    virtual ~ValueBase() {}
};

class OtherValue : public ValueBase {
public:
    OtherValue() : ValueBase() {
        typeFlags.macroValueType = TypeFlags::Other;
    }
    virtual ~OtherValue() {}
};

template <class T>
class Value : public OtherValue {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Value<T> >::instance;}
private:
    T t;
public:
    Value(const T & _t) : OtherValue(), t(_t) {}
    T getValue() const {return t;}
    char *getValuePointer() {return reinterpret_cast<char *>(&t);}
};

template <class T1, class T2>
class ValueCastUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {
        return new Value<T2>(x->cast<Value<T1> >()->getValue());
    }
};

template <typename T, typename CppUnOp>
class ValueUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr & x) {
        return new Value<T>(CppUnOp::op(x->cast<Value<T> >()->getValue()));
    }
};

template <typename T, typename CppBinOp>
class ValueBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr & x1, const Ob::Ptr & x2) {
        return new Value<T>(CppBinOp::op(x1->cast<Value<T> >()->getValue(), x2->cast<Value<T> >()->getValue()));
    }
};

template <typename T, typename CppCmpOp>
class ValueCmpOp {
public:
    static Ob::Ptr op(const Ob::Ptr & x1, const Ob::Ptr & x2) {
        return CppCmpOp::op(x1->cast<Value<T> >()->getValue(), x2->cast<Value<T> >()->getValue());
    }
};
