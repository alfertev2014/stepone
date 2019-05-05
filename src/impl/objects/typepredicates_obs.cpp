#include <impl/objects/typepredicates_obs.h>

#include <impl/operations/typepredicates_ops.h>
#include <impl/base/operations.h>
#include <impl/core/macro.h>
#include <impl/core/value.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseTypePredicates::BaseTypePredicates() :
    fpairp(new Ob(FUnaryOp<TypePUnOp<Pair> >::apply)),
    flazyp(new Ob(FUnaryOp<TypePUnOp<Lazy> >::apply)),
    flabelp(new Ob(FUnaryOp<TypePUnOp<Lazy> >::apply)),
    fatomp(new Ob(FUnaryOp<TypePUnOp<Atom> >::apply)),
    fsymbolp(new Ob(FUnaryOp<TypePUnOp<Symbol> >::apply)),
    fconstp(new Ob(FUnaryOp<TypePUnOp<Const> >::apply)),
    fmacrop(new Ob(FUnaryOp<TypePUnOp<Macro> >::apply)),
    fevalp(new Ob(FUnaryOp<TypePUnOp<Evaluator> >::apply)),
    fbasemacrop(new Ob(FUnaryOp<TypePUnOp<BaseMacro> >::apply)),
    fusermacrop(new Ob(FUnaryOp<TypePUnOp<MacroClosure> >::apply)),
    fvaluep(new Ob(FUnaryOp<TypePUnOp<ValueBase> >::apply))
{}

const BaseTypePredicates &BaseTypePredicates::inst()
{
    static const BaseTypePredicates instance;
    return instance;
}

} // namespaces
