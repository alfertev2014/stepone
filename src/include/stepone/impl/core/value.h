#pragma once

#include "core.h"

#include <sstream>

namespace stepone::core {

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
        typeFlags.typeTag = BaseTypeTag::BaseValue;
    }
    virtual ~ValueBase();
};

template<>
inline bool Ob::is<ValueBase>() const {return typeFlags.isValue();}


class BaseValue : public ValueBase {
protected:
    BaseValue() : ValueBase() {
        typeFlags.typeTag = BaseTypeTag::Other;
    }
};

template<>
inline bool Ob::is<BaseValue>() const {return typeFlags.typeTag == BaseTypeTag::BaseValue;}


class OtherValue : public ValueBase {
protected:
    OtherValue() : ValueBase() {
        typeFlags.typeTag = BaseTypeTag::Other;
    }
};

template<>
inline bool Ob::is<OtherValue>() const {return typeFlags.typeTag == BaseTypeTag::Other;}


template <class T>
class Value : public BaseValue {
private:
    T t;
public:
    Value(const T & _t) : BaseValue(), t(_t) {}
    T getValue() const {return t;}
    char *getValuePointer() {return reinterpret_cast<char *>(&t);}
};

} // namespaces
