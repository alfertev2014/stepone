#pragma once

#include "value.h"

#include <vector>

namespace stepone::core {

class Vector : public ValueBase {
    friend class Ob;
private:
    std::vector<Ptr> array {};

    Vector(int _length) : array(_length) {}
public:
    explicit Vector(const Vector &_origin)
        : array(_origin.array) {}

    Vector(int _length, const Ptr & list, const Ptr & a);
    Vector(const Vector &v1, const Vector &v2);
    Vector(const Vector &_origin, int _begin, int _length);

    size_t getSize() const {return array.size();}
    Ptr getElement(int i) {return array[i];}
};

} // namespaces
