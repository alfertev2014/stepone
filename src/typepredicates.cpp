#include "typepredicates.h"
#include "operations.h"

BaseTypePredicates::BaseTypePredicates() :
    fpairp(new FUnaryOp<PairPUnOp>),
    flazyp(new FUnaryOp<LazyPUnOp>),
    flabelp(new FUnaryOp<LabelPUnOp>),
    fatomp(new FUnaryOp<AtomPUnOp>),
    fsymbolp(new FUnaryOp<SymbolPUnOp>),
    fconstp(new FUnaryOp<ConstPUnOp>),
    fmacrop(new FUnaryOp<MacroPUnOp>),
    fevalp(new FUnaryOp<EvaluatorPUnOp>),
    fbasemacrop(new FUnaryOp<BaseMacroPUnOp>),
    fusermacrop(new FUnaryOp<UserMacroPUnOp>),
    fvaluep(new FUnaryOp<ValuePUnOp>)
{}

const BaseTypePredicates &BaseTypePredicates::inst()
{
    static const BaseTypePredicates instance;
    return instance;
}
