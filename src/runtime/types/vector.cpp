#include <types/vector.h>
#include <error_exception.h>

#include <utility>

namespace stepone::types {

Vector::Vector(int length, const Ptr &list, const Ptr &a)
    : array(
        [&](){
            Ptr p = list;
            std::vector<Ptr> arr;
            arr.reserve(length);
            for(int i = 0; i < length; ++i) {
                arr.emplace_back(p.car().eval(a));
                p = p.cdr();
            }
            return arr;
        }()
    )
{
}

Vector::Vector(const Vector &v1, const Vector &v2)
    : array(
         [&](){
            std::vector<Ptr> arr;
            arr.reserve(v1.getSize() + v2.getSize());
            arr.insert(arr.end(), v1.array.cbegin(), v1.array.cend());
            arr.insert(arr.end(), v2.array.cbegin(), v2.array.cend());
            return arr;
        }()
    )
{
}

Vector::Vector(const Vector &origin, int begin, int length)
    : array(
         [&](){
            if(begin < 0 || begin + length >= origin.getSize()) {
                throw TypeError("vector index out of range");
            }
            std::vector<Ptr> arr;

            arr.reserve(length);
            auto itBegin = origin.array.cbegin() + begin;
            arr.insert(arr.end(), itBegin, itBegin + length);
            return arr;
        }()
    )
{
}

} // namespaces
