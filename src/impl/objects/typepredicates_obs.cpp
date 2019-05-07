#include <impl/objects/typepredicates_obs.h>

#include <impl/operations/typepredicates_ops.h>
#include <impl/base/operations.h>
#include <impl/core/macro.h>
#include <impl/core/value.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseTypePredicates::BaseTypePredicates() :
    fpairp(Ob::of<BaseMacro>(FUnaryOp<TypePUnOp<Pair> >::apply)),
    flazyp(Ob::of<BaseMacro>(FUnaryOp<TypePUnOp<Lazy> >::apply)),
    flabelp(Ob::of<BaseMacro>(FUnaryOp<TypePUnOp<Lazy> >::apply)),
    fatomp(Ob::of<BaseMacro>(FUnaryOp<TypePUnOp<Atom> >::apply)),
    fsymbolp(Ob::of<BaseMacro>(FUnaryOp<TypePUnOp<Symbol> >::apply)),
    fconstp(Ob::of<BaseMacro>(FUnaryOp<TypePUnOp<Const> >::apply)),
    fmacrop(Ob::of<BaseMacro>(FUnaryOp<TypePUnOp<Macro> >::apply)),
    fevalp(Ob::of<BaseMacro>(FUnaryOp<TypePUnOp<Evaluator> >::apply)),
    fbasemacrop(Ob::of<BaseMacro>(FUnaryOp<TypePUnOp<BaseMacro> >::apply)),
    fusermacrop(Ob::of<BaseMacro>(FUnaryOp<TypePUnOp<MacroClosure> >::apply)),
    fvaluep(Ob::of<BaseMacro>(FUnaryOp<TypePUnOp<ValueBase> >::apply))
{}

const BaseTypePredicates &BaseTypePredicates::inst()
{
    static const BaseTypePredicates instance;
    return instance;
}

} // namespaces
