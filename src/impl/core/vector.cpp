#include <core/ob.h>
#include <error_exception.h>

#include <utility>

namespace stepone::core {

Vector::Vector(int _length, const Ptr &list, const Ptr &a) {
    Ptr p = list;
    array.reserve(_length);
    for(int i = 0; i < _length; ++i) {
        array.emplace_back(p.car().eval(a));
        p = p.cdr();
    }
}

Vector::Vector(const Vector &v1, const Vector &v2) {
    array.reserve(v1.getSize() + v2.getSize());
    array.insert(array.end(), v1.array.cbegin(), v1.array.cend());
    array.insert(array.end(), v2.array.cbegin(), v2.array.cend());
}

Vector::Vector(const Vector &_origin, int _begin, int _length) {
    if(_begin < 0 || _begin + _length >= _origin.getSize()) {
        throw SemanticError("vector index out of range");
    }

    array.reserve(_length);
    auto itBegin = _origin.array.cbegin() + _begin;
    array.insert(array.end(), itBegin, itBegin + _length);
}

} // namespaces
