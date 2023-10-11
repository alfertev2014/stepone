#pragma once

#include "value.h"

#include <vector>

namespace stepone::types {

class Vector : public ValueBase {
private:
    const std::vector<Ptr> array {};

    Vector(int _length) : array(_length) {}
public:
    Vector(int length, const Ptr & list, const Ptr & a);
    Vector(const Vector &v1, const Vector &v2);
    Vector(const Vector &origin, int begin, int length);

    size_t getSize() const {return array.size();}
    Ptr getElement(int i) const {return array[i];}
};

} // namespaces
