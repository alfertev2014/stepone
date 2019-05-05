#include <impl/core/bytearray.h>
#include <impl/core/ob.h>

#include <cstring>
#include <sstream>

namespace stepone::core {

ByteArray::~ByteArray() {
    if(origin == Ptr::anil)
        delete [] buffer;
}

Ptr ByteArray::clone() {
    Ptr res = new Ob(ByteArray(length));
    ByteArray * ba = res.as<ByteArray>();
    for(int i = 0; i < length; ++i)
        ba->buffer[i] = buffer[i];
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

Ptr ByteArray::concat(ByteArray *ba) const {
    int nres = length + ba->length;
    Ptr res = new Ob(ByteArray(nres));
    ByteArray * b = res.as<ByteArray>();
    memcpy(b->buffer, buffer, length);
    memcpy(b->buffer + length, ba->buffer, ba->length);
    return res;
}

Ptr ByteArray::fromChars(int size, const char *chars) {
    Ptr res = new Ob(ByteArray(size));
    ByteArray * ba = res.as<ByteArray>();
    memcpy(ba->buffer, chars, size);
    return res;
}

Ptr ByteArray::mid(int begin, int end) {
    if(begin > length)
        begin = length;
    if(end > length)
        end = length;
    int n = end - begin;
    if(n < 0)
        n = 0;
    Ptr res = new Ob(ByteArray(n));
    ByteArray * ba = res.as<ByteArray>();
    memcpy(ba->buffer, buffer + begin, n);
    return res;
}

} // namespaces
