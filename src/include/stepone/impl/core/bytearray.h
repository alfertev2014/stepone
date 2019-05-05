#pragma once

#include <impl/core/value.h>
#include <error_exception.h>

namespace stepone::core {

class ByteArray final : public ValueBase {
private:
    Ptr origin;
    int length;
    char * buffer;
public:
    explicit ByteArray(int _n)
        : origin(Ptr::anil), length(_n < 0 ? 0 : _n), buffer(new char[length]) {}

    explicit ByteArray(const Ptr &_origin)
        : origin(_origin), length(_origin.as<ByteArray>()->length), buffer(_origin.as<ByteArray>()->buffer) {}

    ByteArray(const Ptr &_origin, int _begin, int _length)
        : origin(_origin), length(_length < 0 ? 0 : _length), buffer(_origin.as<ByteArray>()->buffer + _begin) {}

    ByteArray(const Ptr &_origin, char * _begin, int _length)
        : origin(_origin), length(_length < 0 ? 0 : _length), buffer(_begin) {}

    ByteArray(char * _begin, int _length)
        : origin(Ptr::at), length(_length < 0 ? 0 : _length), buffer(_begin) {}

    ~ByteArray();

    int getSize() const {return length;}
    char getElement(int i) const {return buffer[i];}
    char * getData() const {return buffer;}

    Ptr clone();

    int cmp(ByteArray *ba);
    int ncmp(ByteArray *ba, int n);

    int findChar(int ch);
    int findSubarray(ByteArray *ba);

    Ptr concat(ByteArray * ba) const;
    Ptr mid(int begin, int end);

    static Ptr fromChars(int size, const char * chars);

    template <class T>
    static Ptr from(T f) {
        return fromChars(sizeof(T), reinterpret_cast<char*>(&f));
    }

    template <class T>
    T get(int i) {
        if(i < 0 || i + sizeof(T) > length) { throw SemanticError("Error get from bytearray");}
        return *(reinterpret_cast<T*>(buffer + i));
    }
};

} // namespaces
