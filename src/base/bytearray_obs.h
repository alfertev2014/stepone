#pragma once

#include <core.h>

class ByteArrayFunctions {
    ByteArrayFunctions();
public:
    static const ByteArrayFunctions &inst();

    const Ob::Ptr fbarrayp;
    const Ob::Ptr fbarraylen;
    const Ob::Ptr fbarrayclone;
    const Ob::Ptr fbarraycmp;
    const Ob::Ptr fbarrayncmp;
    const Ob::Ptr fbarrayfindch;
    const Ob::Ptr fbarrayfind;
    const Ob::Ptr fbarraycat;
    const Ob::Ptr fbarraymid;
    const Ob::Ptr fbarrayslice;

    const Ob::Ptr fserint;
    const Ob::Ptr fserfloat;
    const Ob::Ptr fserchar;

    const Ob::Ptr fgetint;
    const Ob::Ptr fgetfloat;
    const Ob::Ptr fgetchar;
};
