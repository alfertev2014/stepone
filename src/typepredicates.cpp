#include "typepredicates.h"
#include "operations.h"

const Ob::Ptr BaseTypePredicates::fpairp(new FUnaryOp<PairPUnOp>);
const Ob::Ptr BaseTypePredicates::flazyp(new FUnaryOp<LazyPUnOp>);
const Ob::Ptr BaseTypePredicates::flabelp(new FUnaryOp<LabelPUnOp>);
const Ob::Ptr BaseTypePredicates::fcontextp(new FUnaryOp<ContextPUnOp>);
const Ob::Ptr BaseTypePredicates::fatomp(new FUnaryOp<AtomPUnOp>);
const Ob::Ptr BaseTypePredicates::fsymbolp(new FUnaryOp<SymbolPUnOp>);
const Ob::Ptr BaseTypePredicates::fconstp(new FUnaryOp<ConstPUnOp>);
const Ob::Ptr BaseTypePredicates::fmacrop(new FUnaryOp<MacroPUnOp>);
const Ob::Ptr BaseTypePredicates::fevalp(new FUnaryOp<EvaluatorPUnOp>);
const Ob::Ptr BaseTypePredicates::fbasemacrop(new FUnaryOp<BaseMacroPUnOp>);
const Ob::Ptr BaseTypePredicates::fusermacrop(new FUnaryOp<UserMacroPUnOp>);
const Ob::Ptr BaseTypePredicates::fvaluep(new FUnaryOp<ValuePUnOp>);
