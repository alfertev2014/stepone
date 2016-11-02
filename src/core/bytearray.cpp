#include <bytearray.h>
#include <type_info_inst.h>

#include <cstring>
#include <sstream>

const TypeInfoBase *ByteArray::getTypeInfo() const {return &TypeInfo<ByteArray>::instance;}

ByteArray::~ByteArray() {
    if(origin == Ptr::anil)
        delete [] buffer;
}

ByteArray *ByteArray::clone() {
    ByteArray * res = new ByteArray(length);
    for(int i = 0; i < length; ++i)
        res->buffer[i] = buffer[i];
    return res;
}

int ByteArray::cmp(ByteArray *ba) {
    int len = std::min(length, ba->length);
    int res = memcmp(buffer, ba->buffer, len);
    if(res == 0)
        return len < ba->length ? -1 : len < length ? 1 : 0;
    return res;
}

int ByteArray::ncmp(ByteArray *ba, int n) {
    return memcmp(buffer, ba->buffer, n);
}

int ByteArray::findChar(int ch) {
    char * res = (char *)memchr(buffer, ch, length);
    return res ? res - buffer : -1;
}

int ByteArray::findSubarray(ByteArray *ba) {
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

ByteArray *ByteArray::concat(ByteArray *ba) const {
    int nres = length + ba->length;
    ByteArray * res = new ByteArray(nres);
    memcpy(res->buffer, buffer, length);
    memcpy(res->buffer + length, ba->buffer, ba->length);
    return res;
}

ByteArray *ByteArray::fromChars(int size, const char *chars) {
    ByteArray * res = new ByteArray(size);
    memcpy(res->buffer, chars, size);
    return res;
}

ByteArray *ByteArray::mid(int begin, int end) {
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

ByteArray *ByteArray::slice(int begin, int end) {
    if(begin > length)
        begin = length;
    if(end > length)
        end = length;
    int n = end - begin;
    if(n < 0)
        n = 0;
    return new ByteArray(origin == Ptr::anil ? this : origin, buffer + begin, n);
}
