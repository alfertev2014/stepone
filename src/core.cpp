#include "core.h"

const Ob::Ptr Ob::anil(new Symbol);
const Ob::Ptr Ob::at(new Symbol);

TypeInfoBase::TypeInfoBase() :
    type_id(new Symbol)
{}
