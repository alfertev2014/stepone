#pragma once

#include "value.h"
#include <error_exception.h>
#include <vector>

namespace stepone::types {

class ByteArray final : public ValueBase {
private:
    const std::vector<char> buffer {};
public:
    explicit ByteArray(int _n)
        : buffer(_n) {}

    ByteArray(const ByteArray &origin, size_t begin, size_t length);
    ByteArray(const ByteArray &v1, const ByteArray &v2);
    ByteArray(const char *begin, size_t length);

    template <class T>
    explicit ByteArray(const T &f) : ByteArray(reinterpret_cast<const char*>(&f), sizeof(T)) {}

    size_t getSize() const {return buffer.size();}
    char getElement(int i) const {return buffer[i];}
    const char * getData() const {return buffer.data();}

    int cmp(const ByteArray &ba) const;
    int ncmp(const ByteArray &ba, size_t n) const;

    int findChar(int ch) const;
    int findSubarray(const ByteArray &ba) const;

    template <class T>
    T get(int i) const {
        if(i < 0 || i + sizeof(T) > getSize()) { throw TypeError("Error get from bytearray");}
        return *(reinterpret_cast<const T*>(getData() + i));
    }
};

} // namespaces
