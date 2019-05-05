#pragma once

#include <ptr.h>

namespace stepone::objects {

class BaseMacroses {
    BaseMacroses();
public:
    static const BaseMacroses &inst();

    const Ptr mquote;
    const Ptr mapply;
    const Ptr mif;
    const Ptr mlet;
    const Ptr mlazy;
    const Ptr munlazy;
    const Ptr mlabel;
    const Ptr mmacro;
    const Ptr mcurctx;
    const Ptr mtry;
    const Ptr mbot;
    const Ptr mgensym;
};

} // namespaces
