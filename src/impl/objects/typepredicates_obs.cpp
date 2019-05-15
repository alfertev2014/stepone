#include <impl/objects/typepredicates_obs.h>

#include <impl/operations/typepredicates_ops.h>
#include <impl/base/operations.h>
#include <impl/core/macro.h>
#include <impl/core/value.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseTypePredicates::BaseTypePredicates() :
    fpairp(Ob::of<BaseMacro>(Function(TypePUnOp<Pair>::op))),
    flazyp(Ob::of<BaseMacro>(Function(TypePUnOp<Lazy>::op))),
    flabelp(Ob::of<BaseMacro>(Function(TypePUnOp<Lazy>::op))),
    fatomp(Ob::of<BaseMacro>(Function(TypePUnOp<Atom>::op))),
    fsymbolp(Ob::of<BaseMacro>(Function(TypePUnOp<Symbol>::op))),
    fconstp(Ob::of<BaseMacro>(Function(TypePUnOp<Const>::op))),
    fmacrop(Ob::of<BaseMacro>(Function(TypePUnOp<Macro>::op))),
    fevalp(Ob::of<BaseMacro>(Function(TypePUnOp<Evaluator>::op))),
    fbasemacrop(Ob::of<BaseMacro>(Function(TypePUnOp<BaseMacro>::op))),
    fusermacrop(Ob::of<BaseMacro>(Function(TypePUnOp<MacroClosure>::op))),
    fvaluep(Ob::of<BaseMacro>(Function(TypePUnOp<ValueBase>::op)))
{}

const BaseTypePredicates &BaseTypePredicates::inst()
{
    static const BaseTypePredicates instance;
    return instance;
}

} // namespaces
