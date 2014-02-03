#ifndef TYPESTEMP_H
#define TYPESTEMP_H

#include "core.h"

template <class T>
string valueToString(T x) {return "value";}

template <typename T>
string cppTypeToString() {return "cppType";}

template <> inline string cppTypeToString<int>() {return "int";}
template <> inline string cppTypeToString<float>() {return "float";}
template <> inline string cppTypeToString<char>() {return "char";}

template <class T>
class SpecTypeTemp : public SpecType {
public:
    Ptr getTypeId() const {return TypeInfo<SpecTypeTemp<T> >::type_id;}
    static string getTypeString() {return "SpecType{" + cppTypeToString<T>() + "}";}
    string typeToString() const {return getTypeString();}
private:
    T t;
public:
    SpecTypeTemp(const T & _t) : t(_t) {}
    T getValue() const {return t;}
    string toString() const {return "[" + cppTypeToString<T>() + ": " + valueToString(t) + "]";}
};

template <class T1, class T2>
class FSpecTypeCast : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FSpecTypeCast>::type_id;}
    static string getTypeString() {return "FSpecTypeCast";}
    string typeToString() const {return getTypeString();}
protected:
    Ptr applyX(const Ptr &x) {
        return new SpecTypeTemp<T2>(x->cast<SpecTypeTemp<T1> >()->getValue());
    }
public:
    string toString() const {return "FSpecTypeCast{" + cppTypeToString<T1>() + " -> " + cppTypeToString<T2>() + "}";}
};

template <class T>
class FBitNot : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FBitNot>::type_id;}
    static string getTypeString() {return "FBitNot";}
    string typeToString() const {return getTypeString();}
protected:
    Ptr applyX(const Ptr &x) {
        return new SpecTypeTemp<T>(~ x->cast<SpecTypeTemp<T> >()->getValue());
    }
public:
    string toString() const {return "FBitNot{" + cppTypeToString<T>() + "}";}
};

template <class T>
class FNeg : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FNeg>::type_id;}
    static string getTypeString() {return "FNeg";}
    string typeToString() const {return getTypeString();}
protected:
    Ptr applyX(const Ptr &x) {
        return new SpecTypeTemp<T>(- x->cast<SpecTypeTemp<T> >()->getValue());
    }
public:
    string toString() const {return "FMinus{" + cppTypeToString<T>() + "}";}
};


template <typename T, typename CppBinOp>
class SpecTypeBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr & x1, const Ob::Ptr & x2) {
        return new SpecTypeTemp<T>(CppBinOp::op(x1->cast<SpecTypeTemp<T> >()->getValue(), x2->cast<SpecTypeTemp<T> >()->getValue()));
    }

    static string toString() {return "SpecTypeBinOp{" + CppBinOp::toString() + "}";}
};

template <typename T, typename CppCmpOp>
class SpecTypeCmpOp {
public:
    static Ob::Ptr op(const Ob::Ptr & x1, const Ob::Ptr & x2) {
        return CppCmpOp::op(x1->cast<SpecTypeTemp<T> >()->getValue(), x2->cast<SpecTypeTemp<T> >()->getValue()) ? Ob::at : Ob::anil;
    }

    static string toString() {return "SpecTypeCmpOp{" + CppCmpOp::toString() + "}";}
};


#endif // TYPESTEMP_H
