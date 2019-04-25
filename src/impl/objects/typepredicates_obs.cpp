#include <impl/objects/typepredicates_obs.h>

#include <impl/operations/typepredicates_ops.h>
#include <impl/base/operations.h>
#include <impl/core/macro.h>
#include <impl/core/value.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

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

} // namespaces
