#pragma once

#include <ptr.h>

namespace stepone::objects {

class BaseTypePredicates {
    BaseTypePredicates();
public:
    static const BaseTypePredicates &inst();

    const Ptr apairp;
    const Ptr aatomp;
    const Ptr asymbolp;
    const Ptr aconstp;
    const Ptr amacrop;
    const Ptr aevalp;
    const Ptr abasemacrop;
    const Ptr ausermacrop;
    const Ptr avaluep;

    Ptr populateContext(const Ptr &a) const;
};

} // namespaces
