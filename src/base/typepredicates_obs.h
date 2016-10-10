#pragma once

#include <core.h>

class BaseTypePredicates {
    BaseTypePredicates();
public:
    static const BaseTypePredicates &inst();

    const Ob::Ptr fpairp;
    const Ob::Ptr flazyp;
    const Ob::Ptr flabelp;
    const Ob::Ptr fatomp;
    const Ob::Ptr fsymbolp;
    const Ob::Ptr fconstp;
    const Ob::Ptr fmacrop;
    const Ob::Ptr fevalp;
    const Ob::Ptr fbasemacrop;
    const Ob::Ptr fusermacrop;
    const Ob::Ptr fvaluep;
};
