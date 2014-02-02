#include "core.h"

template <class T>
const Ob::Ptr TypeInfo(new Symbol);

bool operator ==(const Ob * const ob, const Ob::Ptr & p) {return ob == p.ob;}

const Ob::Ptr Ob::anil(new Symbol);
const Ob::Ptr Ob::at(new Symbol);
const Ob::Ptr Ob::aquote(new Symbol);
const Ob::Ptr Ob::aif(new Symbol);
const Ob::Ptr Ob::alambda(new Symbol);
const Ob::Ptr Ob::alet(new Symbol);
const Ob::Ptr Ob::alazy(new Symbol);
const Ob::Ptr Ob::aunlazy(new Symbol);
const Ob::Ptr Ob::alabel(new Symbol);
const Ob::Ptr Ob::amacro(new Symbol);
const Ob::Ptr Ob::aeval(new Symbol);
const Ob::Ptr Ob::agensym(new Symbol);

const Ob::Ptr Evaluator::eempty(new Evaluator(Ob::anil));
