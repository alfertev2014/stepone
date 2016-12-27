#pragma once

#include <ob.h>

class BaseFunctions {
    BaseFunctions();
public:
    static const BaseFunctions &inst();

    const Ptr fcar;
    const Ptr fcdr;
    const Ptr fcons;
    const Ptr feq;
    const Ptr fgettype;
    const Ptr fctxget;
    const Ptr fctxpush;
};
