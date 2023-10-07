#pragma once

#include "value.h"

#include <vector>

namespace stepone::types {

class Vector : public ValueBase {
private:
    std::vector<Ptr> array {};

    Vector(int _length) : array(_length) {}
public:
    Vector(int _length, const Ptr & list, const Ptr & a);
    Vector(const Vector &v1, const Vector &v2);
    Vector(const Vector &_origin, int _begin, int _length);

    size_t getSize() const {return array.size();}
    Ptr getElement(int i) {return array[i];}
};

} // namespaces
