#include <objects/vector_obs.h>

#include <core/ob.h>
#include <operations/vector_ops.h>
#include <operations/typepredicates_ops.h>
#include <base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

VectorFunctions::VectorFunctions() :
    avecp(Ob::of<Symbol>()),
    amkvec(Ob::of<Symbol>()),
    avecclone(Ob::of<Symbol>()),
    aveclen(Ob::of<Symbol>()),
    avecmid(Ob::of<Symbol>()),
    avecslice(Ob::of<Symbol>()),
    avecel(Ob::of<Symbol>()),
    aveccat(Ob::of<Symbol>())
{}


Ptr VectorFunctions::populateContext(const Ptr &a) const
{
    Ptr ctx = Context::make(avecp, Ob::of<BaseMacro>(Function<TypePUnOp<Vector>>()), a);
    ctx = Context::make(amkvec, Ob::of<BaseMacro>(Function<FMakeVector>()), ctx);
    ctx = Context::make(avecclone, Ob::of<BaseMacro>(Function<VectorCloneUnOp>()), ctx);
    ctx = Context::make(aveclen, Ob::of<BaseMacro>(Function<VectorLengthUnOp>()), ctx);
    ctx = Context::make(avecmid, Ob::of<BaseMacro>(Function<VectorMidTerOp>()), ctx);
    ctx = Context::make(avecel, Ob::of<BaseMacro>(Function<VectorElBinOp>()), ctx);
    ctx = Context::make(aveccat, Ob::of<BaseMacro>(Function<VectorConcatBinOp>()), ctx);

    return ctx;
}

const VectorFunctions &VectorFunctions::inst()
{
    static const VectorFunctions instance;
    return instance;
}

} // namespaces
