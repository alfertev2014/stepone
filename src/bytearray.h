#pragma once

#include "core.h"
#include "valuetype.h"

#include <cstring>
#include <sstream>


class ByteArray : public Value {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<ByteArray>::instance;}
    static string getTypeString() {return "ByteArray";}
private:
    Ptr origin;
    char * buffer;
    int length;
public:
    explicit ByteArray(int _n): length(_n < 0 ? 0 : _n) {
        buffer = new char[length];
    }

    explicit ByteArray(ByteArray * _origin)
        : origin(_origin), buffer(_origin->buffer), length(_origin->length) {}

    ByteArray(ByteArray * _origin, int _begin, int _length)
        : origin(_origin), buffer(_origin->buffer + _begin), length(_length < 0 ? 0 : _length) {}

    ByteArray(const Ptr &_origin, char * _begin, int _length)
        : origin(_origin), buffer(_begin), length(_length < 0 ? 0 : _length) {}

    ByteArray(char * _begin, int _length)
        : origin(Ob::at), buffer(_begin), length(_length < 0 ? 0 : _length) {}

    ~ByteArray() {
        if(origin == Ob::anil)
            delete [] buffer;
    }

    int getSize() const {return length;}

    char getElement(int i) const {return buffer[i];}

    char * getData() const {return buffer;}

    string toString() const {
        if(length <= 0) return "bytes[]";
        stringstream ss;
        ss << "bytes[" << length << "]";
        return ss.str();
    }

    ByteArray * clone() {
        ByteArray * res = new ByteArray(length);
        for(int i = 0; i < length; ++i)
            res->buffer[i] = buffer[i];
        return res;
    }

    int cmp(ByteArray *ba) {
        int len = min(length, ba->length);
        int res = memcmp(buffer, ba->buffer, len);
        if(res == 0)
            return len < ba->length ? -1 : len < length ? 1 : 0;
        return res;
    }

    int ncmp(ByteArray *ba, int n) {
        return memcmp(buffer, ba->buffer, n);
    }

    int findChar(int ch) {
        char * res = (char *)memchr(buffer, ch, length);
        return res ? res - buffer : -1;
    }

    int findSubarray(ByteArray *ba) {
        char * pend = buffer + length;
        char * needleEnd = ba->buffer + ba->length;
        char *p = buffer, *needle = ba->buffer;
        while(true) {
            if(needle == needleEnd)
                return p - buffer - ba->length;
            if(p == pend)
                return -1;
            if(*p != *needle) {
                needle = ba->buffer;
                while(*p != *needle) {
                    if(p == pend)
                        return -1;
                    ++p;
                }
            }
            ++needle;
            ++p;
        }
        return -1;
    }

    ByteArray * concat(ByteArray * ba) const {
        int nres = length + ba->length;
        ByteArray * res = new ByteArray(nres);
        memcpy(res->buffer, buffer, length);
        memcpy(res->buffer + length, ba->buffer, ba->length);
        return res;
    }

    template <class T>
    static ByteArray * from(T f) {
        ByteArray * res = new ByteArray(sizeof(T));
        *(reinterpret_cast<T*>(res->buffer)) = f;
        return res;
    }

    static ByteArray * fromChars(int size, const char * chars) {
        ByteArray * res = new ByteArray(size);
        memcpy(res->buffer, chars, size);
        return res;
    }

    ByteArray * mid(int begin, int end) {
        if(begin > length)
            begin = length;
        if(end > length)
            end = length;
        int n = end - begin;
        if(n < 0)
            n = 0;
        ByteArray * res = new ByteArray(n);
        memcpy(res->buffer, buffer + begin, n);
        return res;
    }

    ByteArray * slice(int begin, int end) {
        if(begin > length)
            begin = length;
        if(end > length)
            end = length;
        int n = end - begin;
        if(n < 0)
            n = 0;
        return new ByteArray(origin == Ob::anil ? this : origin, buffer + begin, n);
    }

    template <class T>
    T get(int i) {
        if(i < 0 || i + sizeof(T) > length) { DBG("Error get from bytearray");  throw SemanticError();}
        return *(reinterpret_cast<T*>(buffer + i));
    }
};

