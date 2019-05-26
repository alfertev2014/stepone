#include <impl/objects/typepredicates_obs.h>

#include <impl/operations/typepredicates_ops.h>
#include <impl/base/operations.h>
#include <impl/core/macro.h>
#include <impl/core/value.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

BaseTypePredicates::BaseTypePredicates() :
    fpairp(Ob::of<BaseMacro>(Function<TypePUnOp<Pair>>())),
    flazyp(Ob::of<BaseMacro>(Function<TypePUnOp<Lazy>>())),
    flabelp(Ob::of<BaseMacro>(Function<TypePUnOp<Lazy>>())),
    fatomp(Ob::of<BaseMacro>(Function<TypePUnOp<Atom>>())),
    fsymbolp(Ob::of<BaseMacro>(Function<TypePUnOp<Symbol>>())),
    fconstp(Ob::of<BaseMacro>(Function<TypePUnOp<Const>>())),
    fmacrop(Ob::of<BaseMacro>(Function<TypePUnOp<Macro>>())),
    fevalp(Ob::of<BaseMacro>(Function<TypePUnOp<Evaluator>>())),
    fbasemacrop(Ob::of<BaseMacro>(Function<TypePUnOp<BaseMacro>>())),
    fusermacrop(Ob::of<BaseMacro>(Function<TypePUnOp<MacroClosure>>())),
    fvaluep(Ob::of<BaseMacro>(Function<TypePUnOp<ValueBase>>()))
{}

const BaseTypePredicates &BaseTypePredicates::inst()
{
    static const BaseTypePredicates instance;
    return instance;
}

} // namespaces
