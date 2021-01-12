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


class ValueBase : public Const {};


class BaseValue : public ValueBase {
// TODO: Place here a payload for built in cpp types and value type tag
protected:
    BaseValue() = default;
};


template <class T>
class Value : public BaseValue {
private:
    T t; // TODO: Use place in BaseValue and reinterpret_cast
public:
    Value(const T & _t) : t(_t) {}
    T getValue() const {return t;}
    char *getValuePointer() {return reinterpret_cast<char *>(&t);}
};

} // namespaces
