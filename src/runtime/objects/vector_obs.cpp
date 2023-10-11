#include <objects/vector_obs.h>

#include <ob.h>
#include <operations/vector_ops.h>
#include <operations/typepredicates_ops.h>
#include <builtin/operations.h>

namespace stepone::objects {

using namespace builtin;
using namespace operations;

VectorFunctions::VectorFunctions() :
    avecp(Ptr::of<Symbol>()),
    amkvec(Ptr::of<Symbol>()),
    avecclone(Ptr::of<Symbol>()),
    aveclen(Ptr::of<Symbol>()),
    avecmid(Ptr::of<Symbol>()),
    avecslice(Ptr::of<Symbol>()),
    avecel(Ptr::of<Symbol>()),
    aveccat(Ptr::of<Symbol>())
{}


Ptr VectorFunctions::populateContext(const Ptr &a) const
{
    Ptr ctx = Context::make(avecp, Ptr::of<BuiltInMacro>(Function<TypePUnOp<Vector>>()), a);
    ctx = Context::make(amkvec, Ptr::of<BuiltInMacro>(Function<FMakeVector>()), ctx);
    ctx = Context::make(avecclone, Ptr::of<BuiltInMacro>(Function<VectorCloneUnOp>()), ctx);
    ctx = Context::make(aveclen, Ptr::of<BuiltInMacro>(Function<VectorLengthUnOp>()), ctx);
    ctx = Context::make(avecmid, Ptr::of<BuiltInMacro>(Function<VectorMidTerOp>()), ctx);
    ctx = Context::make(avecel, Ptr::of<BuiltInMacro>(Function<VectorElBinOp>()), ctx);
    ctx = Context::make(aveccat, Ptr::of<BuiltInMacro>(Function<VectorConcatBinOp>()), ctx);

    return ctx;
}

const VectorFunctions &VectorFunctions::inst()
{
    static const VectorFunctions instance;
    return instance;
}

} // namespaces
