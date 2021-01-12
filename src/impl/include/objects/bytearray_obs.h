#pragma once

#include <ptr.h>

namespace stepone::objects {

class ByteArrayFunctions {
    ByteArrayFunctions();
public:
    static const ByteArrayFunctions &inst();

    const Ptr abarrayp;
    const Ptr abarraylen;
    const Ptr abarrayclone;
    const Ptr abarraycmp;
    const Ptr abarrayncmp;
    const Ptr abarrayfindch;
    const Ptr abarrayfind;
    const Ptr abarraycat;
    const Ptr abarraymid;
    const Ptr abarrayslice;

    const Ptr aserint;
    const Ptr aserfloat;
    const Ptr aserchar;

    const Ptr agetint;
    const Ptr agetfloat;
    const Ptr agetchar;

    Ptr populateContext(const Ptr &a) const;
};

} //namespaces
