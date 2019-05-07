#include <impl/objects/typepredicates_obs.h>

#include <impl/operations/typepredicates_ops.h>
#include <impl/base/operations.h>
#include <impl/core/macro.h>
#include <impl/core/value.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseTypePredicates::BaseTypePredicates() :
    fpairp(new Ob(BaseMacro(FUnaryOp<TypePUnOp<Pair> >::apply))),
    flazyp(new Ob(BaseMacro(FUnaryOp<TypePUnOp<Lazy> >::apply))),
    flabelp(new Ob(BaseMacro(FUnaryOp<TypePUnOp<Lazy> >::apply))),
    fatomp(new Ob(BaseMacro(FUnaryOp<TypePUnOp<Atom> >::apply))),
    fsymbolp(new Ob(BaseMacro(FUnaryOp<TypePUnOp<Symbol> >::apply))),
    fconstp(new Ob(BaseMacro(FUnaryOp<TypePUnOp<Const> >::apply))),
    fmacrop(new Ob(BaseMacro(FUnaryOp<TypePUnOp<Macro> >::apply))),
    fevalp(new Ob(BaseMacro(FUnaryOp<TypePUnOp<Evaluator> >::apply))),
    fbasemacrop(new Ob(BaseMacro(FUnaryOp<TypePUnOp<BaseMacro> >::apply))),
    fusermacrop(new Ob(BaseMacro(FUnaryOp<TypePUnOp<MacroClosure> >::apply))),
    fvaluep(new Ob(BaseMacro(FUnaryOp<TypePUnOp<ValueBase> >::apply)))
{}

const BaseTypePredicates &BaseTypePredicates::inst()
{
    static const BaseTypePredicates instance;
    return instance;
}

} // namespaces
