#pragma once

#include "core.h"

class BaseFunctions {
    BaseFunctions();
public:
    static const BaseFunctions &inst();

    const Ob::Ptr fcar;
    const Ob::Ptr fcdr;
    const Ob::Ptr fcons;
    const Ob::Ptr feq;
    const Ob::Ptr fgettype;
    const Ob::Ptr fctxget;
    const Ob::Ptr fctxpush;
};
