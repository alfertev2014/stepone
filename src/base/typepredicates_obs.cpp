#include "typepredicates_obs.h"

#include "typepredicates_ops.h"
#include <operations.h>
#include <macro.h>
#include <value.h>

BaseTypePredicates::BaseTypePredicates() :
    fpairp(new FUnaryOp<TypePUnOp<Pair> >),
    flazyp(new FUnaryOp<TypePUnOp<Lazy> >),
    flabelp(new FUnaryOp<TypePUnOp<Lazy> >),
    fatomp(new FUnaryOp<TypePUnOp<Atom> >),
    fsymbolp(new FUnaryOp<TypePUnOp<Symbol> >),
    fconstp(new FUnaryOp<TypePUnOp<Const> >),
    fmacrop(new FUnaryOp<TypePUnOp<Macro> >),
    fevalp(new FUnaryOp<TypePUnOp<Evaluator> >),
    fbasemacrop(new FUnaryOp<TypePUnOp<BaseMacro> >),
    fusermacrop(new FUnaryOp<TypePUnOp<MacroClosure> >),
    fvaluep(new FUnaryOp<TypePUnOp<ValueBase> >)
{}

const BaseTypePredicates &BaseTypePredicates::inst()
{
    static const BaseTypePredicates instance;
    return instance;
}
