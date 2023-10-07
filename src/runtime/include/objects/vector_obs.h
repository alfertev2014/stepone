#pragma once

#include <ptr.h>

namespace stepone::objects {

class VectorFunctions {
    VectorFunctions();
public:
    static const VectorFunctions &inst();

    const Ptr avecp;
    const Ptr amkvec;
    const Ptr avecclone;
    const Ptr aveclen;
    const Ptr avecmid;
    const Ptr avecslice;
    const Ptr avecel;
    const Ptr aveccat;

    Ptr populateContext(const Ptr &a) const;
};

} // namespaces
