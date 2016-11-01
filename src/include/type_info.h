#pragma once

#include "core.h"

class TypeInfoBase {
public:
    TypeInfoBase();
    const Ptr type_id;
};

inline Ptr Ptr::typeId() const
{
    return ob->getTypeInfo()->type_id;
}
