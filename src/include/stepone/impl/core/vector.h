#pragma once

#include "value.h"

#include <vector>

namespace stepone::core {

class Vector : public ValueBase {
    friend class Ob;
private:
    Ptr origin;
    std::vector<Ptr> array;

    Vector(int _length) : origin(Ptr::anil), array(_length) {}
public:
    explicit Vector(const Ptr &_origin)
        : origin(_origin), array(_origin.as<Vector>()->array) {}

    Vector(const Ptr &_origin, int _begin, int _length)
        : origin(_origin),
        array(_origin.as<Vector>()->array.cbegin() + _begin,
              _origin.as<Vector>()->array.cbegin() + _begin + _length) {}

    size_t getSize() const {return array.size();}
    Ptr getElement(int i) {return array[i];}

    static Ptr fromList(int n, const Ptr & list, const Ptr & a);

    Ptr concat(Vector * v) const;
    Ptr mid(int begin, int end);
};

} // namespaces
