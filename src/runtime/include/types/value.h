#pragma once

#include "core.h"

#include <sstream>

namespace stepone::types {

template <class T>
class Value final : public ValueBase {
public:
    const T value;
    Value(const T &value) : value(value) {}
};

// TODO: Add it to Ob payload
class OtherValue final : public ValueBase {
private:
    char payload[sizeof(Ptr) * 3];
protected:
    OtherValue() = default;
};

} // namespaces
