#pragma once

#include "core.h"

class BaseMacroses {
    BaseMacroses();
public:
    static const BaseMacroses &inst();

    const Ob::Ptr mquote;
    const Ob::Ptr mapply;
    const Ob::Ptr mif;
    const Ob::Ptr mlet;
    const Ob::Ptr mlazy;
    const Ob::Ptr munlazy;
    const Ob::Ptr mlabel;
    const Ob::Ptr mlambda;
    const Ob::Ptr mmacro;
    const Ob::Ptr mcurctx;
    const Ob::Ptr mtry;
    const Ob::Ptr mbot;
    const Ob::Ptr mgensym;
};
