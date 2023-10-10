#include <ob.h>
#include <types/bytearray.h>

#include <cstring>
#include <sstream>
#include <algorithm>

namespace stepone::types {
ByteArray::ByteArray(const ByteArray &_origin, size_t _begin, size_t _length) {
    if(_begin < 0 || _begin + _length >= _origin.getSize()) {
        throw TypeError("buffer index out of range");
    }

    buffer.reserve(_length);
    auto itBegin = _origin.buffer.cbegin() + _begin;
    buffer.insert(buffer.end(), itBegin, itBegin + _length);
}

ByteArray::ByteArray(const ByteArray &v1, const ByteArray &v2) {
    buffer.reserve(v1.getSize() + v2.getSize());
    buffer.insert(buffer.end(), v1.buffer.cbegin(), v1.buffer.cend());
    buffer.insert(buffer.end(), v2.buffer.cbegin(), v2.buffer.cend());
}

ByteArray::ByteArray(const char *_begin, size_t _length) {
    if(_begin == nullptr || _length < 0) {
        throw TypeError("buffer index out of range");
    }

    buffer.reserve(_length);
    buffer.insert(buffer.end(), _begin, _begin + _length);
}

int ByteArray::cmp(const ByteArray &ba) {
    return std::lexicographical_compare(
        buffer.cbegin(), buffer.cend(),
        ba.buffer.cbegin(), ba.buffer.cend());
}

int ByteArray::ncmp(const ByteArray &ba, size_t n) {
    n = std::min(buffer.size(), n);
    n = std::min(ba.buffer.size(), n);
    return std::lexicographical_compare(
        buffer.cbegin(), buffer.cbegin() + n,
        ba.buffer.cbegin(), ba.buffer.cbegin() + n);
}

int ByteArray::findChar(int ch) {
    auto res = std::find(buffer.cbegin(), buffer.cend(), ch);
    return res != buffer.cend() ? res - buffer.cbegin() : -1;
}

int ByteArray::findSubarray(const ByteArray &ba) {
    auto res = std::search(buffer.cbegin(), buffer.cend(), ba.buffer.cbegin(), ba.buffer.cend());
    return res != buffer.cend() ? res - buffer.cbegin() : -1;
}

} // namespaces
