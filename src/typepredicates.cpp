#include "typepredicates.h"

const Ob::Ptr BaseTypePredicates::fpairp(new FPairP);
const Ob::Ptr BaseTypePredicates::flazyp(new FLazyP);
const Ob::Ptr BaseTypePredicates::flabelp(new FLabelP);
const Ob::Ptr BaseTypePredicates::fcontextp(new FContextP);
const Ob::Ptr BaseTypePredicates::fatomp(new FAtomP);
const Ob::Ptr BaseTypePredicates::fsymbolp(new FSymbolP);
const Ob::Ptr BaseTypePredicates::fconstp(new FConstP);
const Ob::Ptr BaseTypePredicates::fmacrop(new FMacroP);
const Ob::Ptr BaseTypePredicates::fevalp(new FEvaluatorP);
const Ob::Ptr BaseTypePredicates::fbasemacrop(new FBaseMacroP);
const Ob::Ptr BaseTypePredicates::fusermacrop(new FUserMacroP);
const Ob::Ptr BaseTypePredicates::ffunctionp(new FFunctionP);
const Ob::Ptr BaseTypePredicates::fbasefunctionp(new FBaseFunctionP);
const Ob::Ptr BaseTypePredicates::fclosurep(new FClosureP);
const Ob::Ptr BaseTypePredicates::fspectypep(new FSpecTypeP);
