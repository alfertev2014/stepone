#include "stepone.h"

bool operator ==(const Ob * const ob, const Ob::Ptr & p) {return ob == p.ob;}

int TypeId::gt = 0;

const Ob::Ptr Ob::anil(new Symbol);
const Ob::Ptr Ob::at(new Symbol);
const Ob::Ptr Ob::aquote(new Symbol);
const Ob::Ptr Ob::aif(new Symbol);
const Ob::Ptr Ob::alambda(new Symbol);
const Ob::Ptr Ob::alet(new Symbol);
const Ob::Ptr Ob::alazy(new Symbol);
const Ob::Ptr Ob::aunlazy(new Symbol);
const Ob::Ptr Ob::alabel(new Symbol);
const Ob::Ptr Ob::aeval(new Symbol);

