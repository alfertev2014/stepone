#include <ob.h>
#include <types/bytearray.h>

#include <cstring>
#include <sstream>
#include <algorithm>

namespace stepone::types {
ByteArray::ByteArray(const ByteArray &origin, size_t begin, size_t length)
    : buffer(
        [&](){
            if(begin < 0 || begin + length >= origin.getSize()) {
                throw TypeError("buffer index out of range");
            }

            std::vector<char> buff;
            buff.reserve(length);
            auto itBegin = origin.buffer.cbegin() + begin;
            buff.insert(buff.end(), itBegin, itBegin + length);
            return buff;
        }()
    )
{
}

ByteArray::ByteArray(const ByteArray &v1, const ByteArray &v2)
    : buffer(
        [&](){
            std::vector<char> buff;
            buff.reserve(v1.getSize() + v2.getSize());
            buff.insert(buff.end(), v1.buffer.cbegin(), v1.buffer.cend());
            buff.insert(buff.end(), v2.buffer.cbegin(), v2.buffer.cend());
            return buff;
        }()
    )
{
}

ByteArray::ByteArray(const char *begin, size_t length)
    : buffer(
        [&](){
            if(!begin) {
                throw TypeError("begin pointer is null");
            }
            std::vector<char> buff;
            buff.reserve(length);
            buff.insert(buff.end(), begin, begin + length);
            return buff;
        }()
    )
{
}

int ByteArray::cmp(const ByteArray &ba) const {
    return std::lexicographical_compare(
        buffer.cbegin(), buffer.cend(),
        ba.buffer.cbegin(), ba.buffer.cend());
}

int ByteArray::ncmp(const ByteArray &ba, size_t n) const {
    n = std::min(buffer.size(), n);
    n = std::min(ba.buffer.size(), n);
    return std::lexicographical_compare(
        buffer.cbegin(), buffer.cbegin() + n,
        ba.buffer.cbegin(), ba.buffer.cbegin() + n);
}

int ByteArray::findChar(int ch) const {
    auto res = std::find(buffer.cbegin(), buffer.cend(), ch);
    return res != buffer.cend() ? res - buffer.cbegin() : -1;
}

int ByteArray::findSubarray(const ByteArray &ba) const {
    auto res = std::search(buffer.cbegin(), buffer.cend(), ba.buffer.cbegin(), ba.buffer.cend());
    return res != buffer.cend() ? res - buffer.cbegin() : -1;
}

} // namespaces
