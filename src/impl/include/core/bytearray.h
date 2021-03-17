#pragma once

#include "value.h"
#include <error_exception.h>
#include <vector>

namespace stepone::core {

class ByteArray final : public ValueBase {
private:
    std::vector<char> buffer {};
public:
    explicit ByteArray(int _n)
        : buffer(_n) {}

    ByteArray(const ByteArray &_origin, size_t _begin, size_t _length);
    ByteArray(const ByteArray &v1, const ByteArray &v2);
    ByteArray(const char *_begin, size_t _length);

    template <class T>
    explicit ByteArray(const T &f) : ByteArray(reinterpret_cast<const char*>(&f), sizeof(T)) {}

    size_t getSize() const {return buffer.size();}
    char getElement(int i) const {return buffer[i];}
    char * getData() const {return const_cast<char*>(buffer.data());}

    int cmp(const ByteArray &ba);
    int ncmp(const ByteArray &ba, size_t n);

    int findChar(int ch);
    int findSubarray(const ByteArray &ba);

    template <class T>
    T get(int i) {
        if(i < 0 || i + sizeof(T) > getSize()) { throw SemanticError("Error get from bytearray");}
        return *(reinterpret_cast<T*>(getData() + i));
    }
};

} // namespaces
