#pragma once

#include <ptr.h>

namespace stepone { namespace objects {

class VectorFunctions {
    VectorFunctions();
public:
    static const VectorFunctions &inst();

    const Ptr fvecp;
    const Ptr fmkvec;
    const Ptr fvecclone;
    const Ptr fveclen;
    const Ptr fvecmid;
    const Ptr fvecslice;
    const Ptr fvecel;
    const Ptr fveccat;
};

}} // namespaces