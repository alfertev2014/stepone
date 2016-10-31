#pragma once

#include <core.h>

class ByteArrayFunctions {
    ByteArrayFunctions();
public:
    static const ByteArrayFunctions &inst();

    const Ptr fbarrayp;
    const Ptr fbarraylen;
    const Ptr fbarrayclone;
    const Ptr fbarraycmp;
    const Ptr fbarrayncmp;
    const Ptr fbarrayfindch;
    const Ptr fbarrayfind;
    const Ptr fbarraycat;
    const Ptr fbarraymid;
    const Ptr fbarrayslice;

    const Ptr fserint;
    const Ptr fserfloat;
    const Ptr fserchar;

    const Ptr fgetint;
    const Ptr fgetfloat;
    const Ptr fgetchar;
};
