#pragma once

#include <ptr.h>

namespace stepone::objects {

class BaseFunctions {
    BaseFunctions();
public:
    static const BaseFunctions &inst();

    const Ptr acar;
    const Ptr acdr;
    const Ptr acons;
    const Ptr aeq;
    const Ptr agettype;
    const Ptr actxget;
    const Ptr actxpush;

    const Ptr aeempty;

    Ptr populateContext(const Ptr &a) const;
};

} // namespaces
