#include "core.h"

bool operator ==(const Ob * const ob, const Ob::Ptr & p) {return ob == p.ob;}

const Ob::Ptr Ob::anil(new Symbol);
const Ob::Ptr Ob::at(new Symbol);

const Ob::Ptr Evaluator::eempty(new Evaluator(Ob::anil));

string Ob::typeToString() const {return getTypeInfo()->getTypeString();}

TypeInfoBase::TypeInfoBase() : type_id(new Symbol) {}
