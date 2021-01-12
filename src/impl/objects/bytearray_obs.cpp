#include <objects/bytearray_obs.h>

#include <operations/bytearray_ops.h>
#include <operations/typepredicates_ops.h>
#include <base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

ByteArrayFunctions::ByteArrayFunctions() :
    abarrayp(Ob::of<Symbol>()),
    abarraylen(Ob::of<Symbol>()),
    abarrayclone(Ob::of<Symbol>()),
    abarraycmp(Ob::of<Symbol>()),
    abarrayncmp(Ob::of<Symbol>()),
    abarrayfindch(Ob::of<Symbol>()),
    abarrayfind(Ob::of<Symbol>()),
    abarraycat(Ob::of<Symbol>()),
    abarraymid(Ob::of<Symbol>()),
    abarrayslice(Ob::of<Symbol>()),

    aserint(Ob::of<Symbol>()),
    aserfloat(Ob::of<Symbol>()),
    aserchar(Ob::of<Symbol>()),

    agetint(Ob::of<Symbol>()),
    agetfloat(Ob::of<Symbol>()),
    agetchar(Ob::of<Symbol>())
{}


Ptr ByteArrayFunctions::populateContext(const Ptr &a) const
{
    Ptr ctx = Context::make(abarrayp, Ob::of<BaseMacro>(Function<TypePUnOp<ByteArray>>()), a);
    ctx = Context::make(abarraylen, Ob::of<BaseMacro>(Function<ByteArrayLengthUnOp>()), ctx);
    ctx = Context::make(abarrayclone, Ob::of<BaseMacro>(Function<ByteArrayCloneUnOp>()), ctx);
    ctx = Context::make(abarraycmp, Ob::of<BaseMacro>(Function<CompareByteArrayBinOp>()), ctx);
    ctx = Context::make(abarrayncmp, Ob::of<BaseMacro>(Function<NCompareByteArrayTerOp>()), ctx);
    ctx = Context::make(abarrayfindch, Ob::of<BaseMacro>(Function<FindCharByteArrayBinOp>()), ctx);
    ctx = Context::make(abarrayfind, Ob::of<BaseMacro>(Function<FindCharsByteArrayBinOp>()), ctx);
    ctx = Context::make(abarraycat, Ob::of<BaseMacro>(Function<ConcatByteArrayBinOp>()), ctx);
    ctx = Context::make(abarraymid, Ob::of<BaseMacro>(Function<MidByteArrayTerOp>()), ctx);

    ctx = Context::make(aserint, Ob::of<BaseMacro>(Function<SerializeUnOp<int> >()), ctx);
    ctx = Context::make(aserfloat, Ob::of<BaseMacro>(Function<SerializeUnOp<float> >()), ctx);
    ctx = Context::make(aserchar, Ob::of<BaseMacro>(Function<SerializeUnOp<char> >()), ctx);

    ctx = Context::make(agetint, Ob::of<BaseMacro>(Function<ByteArrayGetBinOp<int> >()), ctx);
    ctx = Context::make(agetfloat, Ob::of<BaseMacro>(Function<ByteArrayGetBinOp<float> >()), ctx);
    ctx = Context::make(agetchar, Ob::of<BaseMacro>(Function<ByteArrayGetBinOp<char> >()), ctx);

    return ctx;
}

const ByteArrayFunctions &ByteArrayFunctions::inst()
{
    static const ByteArrayFunctions instance;
    return instance;
}

} // namespaces
