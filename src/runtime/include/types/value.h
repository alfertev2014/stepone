#pragma once

#include "core.h"

#include <sstream>

namespace stepone::types {

template <class T>
class Value final : public ValueBase {
private:
    T t;
public:
    Value(const T & _t) : t(_t) {}
    T getValue() const {return t;}
};

// TODO: Add it to Ob payload
class OtherValue final : public ValueBase {
private:
    char payload[sizeof(Ptr) * 3];
protected:
    OtherValue() = default;
};

} // namespaces
