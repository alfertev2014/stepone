#pragma once

#include "core.h"
#include "type_info_inst.h"

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
        typeFlags.constType = TypeFlags::ValueBase;
    }
    virtual ~ValueBase();
};

template<>
ValueBase *Ob::as<ValueBase>();

class OtherValue : public ValueBase {
protected:
    OtherValue() : ValueBase() {
        typeFlags.macroValueType = TypeFlags::Other;
    }
};

template <class T>
class Value : public OtherValue {
public:
    const Ptr getTypeInfo() const {return TypeInfo<Value<T> >::instance;}
private:
    T t;
public:
    Value(const T & _t) : OtherValue(), t(_t) {}
    T getValue() const {return t;}
    char *getValuePointer() {return reinterpret_cast<char *>(&t);}
};

} // namespaces
