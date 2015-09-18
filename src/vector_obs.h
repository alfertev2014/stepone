#pragma once

#include "core.h"

class VectorFunctions {
    VectorFunctions();
public:
    static const VectorFunctions &inst();

    const Ob::Ptr fvecp;
    const Ob::Ptr fmkvec;
    const Ob::Ptr fvecclone;
    const Ob::Ptr fveclen;
    const Ob::Ptr fvecmid;
    const Ob::Ptr fvecslice;
    const Ob::Ptr fvecel;
    const Ob::Ptr fveccat;
};
