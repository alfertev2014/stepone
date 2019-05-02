#pragma once

#include "ob.h"
#include "value.h"

namespace stepone::core {

class ByteArray final : public ValueBase {
private:
    Ptr origin;
    int length;
    char * buffer;
public:
    explicit ByteArray(int _n)
        : ValueBase(BaseTypeTag::ByteArray),
        origin(Ptr::anil), length(_n < 0 ? 0 : _n), buffer(new char[length]) {}

    explicit ByteArray(ByteArray * _origin)
        : origin(_origin), length(_origin->length), buffer(_origin->buffer) {}

    ByteArray(ByteArray * _origin, int _begin, int _length)
        : origin(_origin), length(_length < 0 ? 0 : _length), buffer(_origin->buffer + _begin) {}

    ByteArray(const Ptr &_origin, char * _begin, int _length)
        : origin(_origin), length(_length < 0 ? 0 : _length), buffer(_begin) {}

    ByteArray(char * _begin, int _length)
        : origin(Ptr::at), length(_length < 0 ? 0 : _length), buffer(_begin) {}

    ~ByteArray();

    int getSize() const {return length;}
    char getElement(int i) const {return buffer[i];}
    char * getData() const {return buffer;}

    ByteArray * clone();

    int cmp(ByteArray *ba);
    int ncmp(ByteArray *ba, int n);

    int findChar(int ch);
    int findSubarray(ByteArray *ba);

    ByteArray * concat(ByteArray * ba) const;
    ByteArray * mid(int begin, int end);
    ByteArray * slice(int begin, int end);

    static ByteArray * fromChars(int size, const char * chars);

    template <class T>
    static ByteArray * from(T f) {
        ByteArray * res = new ByteArray(sizeof(T));
        *(reinterpret_cast<T*>(res->buffer)) = f;
        return res;
    }

    template <class T>
    T get(int i) {
        if(i < 0 || i + sizeof(T) > length) { throw SemanticError("Error get from bytearray");}
        return *(reinterpret_cast<T*>(buffer + i));
    }
};

} // namespaces
