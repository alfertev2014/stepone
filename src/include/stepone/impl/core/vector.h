#pragma once

#include "value.h"

namespace stepone::operations {
class FMakeVector;
class VectorElBinOp;
}

namespace stepone::core {

class Vector : public ValueBase {
    friend class Ob;
private:
    Ptr origin;
    Ptr * array;
    int length;

    Vector(int _length) : origin(Ptr::anil), length(_length) {
        // array is not initialized
        // allocate memory, don't call constructor Ptr()
        array = reinterpret_cast<Ptr*>(new char[length * sizeof(Ptr)]);
    }
public:
    explicit Vector(const Ptr &_origin)
        : origin(_origin), array(_origin.as<Vector>()->array), length(_origin.as<Vector>()->length) {}

    Vector(const Ptr &_origin, int _begin, int _length)
        : origin(_origin), array(_origin.as<Vector>()->array + _begin), length(_length < 0 ? 0 : _length) {}

    Vector(const Ptr &_origin, Ptr * _begin, int _length)
        : origin(_origin), array(_begin), length(_length < 0 ? 0 : _length) {}


    ~Vector();

    int getSize() const {return length;}
    Ptr getElement(int i) {return array[i];}

    static Ptr fromList(int n, const Ptr & list, const Ptr & a);

    Ptr clone();
    Ptr concat(Vector * v) const;
    Ptr mid(int begin, int end);

    friend class operations::FMakeVector;
    friend class operations::VectorElBinOp;
};

} // namespaces
