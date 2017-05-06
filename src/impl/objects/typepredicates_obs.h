#pragma once

#include <ptr.h>

class BaseTypePredicates {
    BaseTypePredicates();
public:
    static const BaseTypePredicates &inst();

    const Ptr fpairp;
    const Ptr flazyp;
    const Ptr flabelp;
    const Ptr fatomp;
    const Ptr fsymbolp;
    const Ptr fconstp;
    const Ptr fmacrop;
    const Ptr fevalp;
    const Ptr fbasemacrop;
    const Ptr fusermacrop;
    const Ptr fvaluep;
};
