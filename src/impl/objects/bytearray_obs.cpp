#include <objects/bytearray_obs.h>

#include <operations/bytearray_ops.h>
#include <operations/typepredicates_ops.h>
#include <base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

ByteArrayFunctions::ByteArrayFunctions() :
    abarrayp(Ptr::of<Symbol>()),
    abarraylen(Ptr::of<Symbol>()),
    abarrayclone(Ptr::of<Symbol>()),
    abarraycmp(Ptr::of<Symbol>()),
    abarrayncmp(Ptr::of<Symbol>()),
    abarrayfindch(Ptr::of<Symbol>()),
    abarrayfind(Ptr::of<Symbol>()),
    abarraycat(Ptr::of<Symbol>()),
    abarraymid(Ptr::of<Symbol>()),
    abarrayslice(Ptr::of<Symbol>()),

    aserint(Ptr::of<Symbol>()),
    aserfloat(Ptr::of<Symbol>()),
    aserchar(Ptr::of<Symbol>()),

    agetint(Ptr::of<Symbol>()),
    agetfloat(Ptr::of<Symbol>()),
    agetchar(Ptr::of<Symbol>())
{}


Ptr ByteArrayFunctions::populateContext(const Ptr &a) const
{
    Ptr ctx = Context::make(abarrayp, Ptr::of<BaseMacro>(Function<TypePUnOp<ByteArray>>()), a);
    ctx = Context::make(abarraylen, Ptr::of<BaseMacro>(Function<ByteArrayLengthUnOp>()), ctx);
    ctx = Context::make(abarrayclone, Ptr::of<BaseMacro>(Function<ByteArrayCloneUnOp>()), ctx);
    ctx = Context::make(abarraycmp, Ptr::of<BaseMacro>(Function<CompareByteArrayBinOp>()), ctx);
    ctx = Context::make(abarrayncmp, Ptr::of<BaseMacro>(Function<NCompareByteArrayTerOp>()), ctx);
    ctx = Context::make(abarrayfindch, Ptr::of<BaseMacro>(Function<FindCharByteArrayBinOp>()), ctx);
    ctx = Context::make(abarrayfind, Ptr::of<BaseMacro>(Function<FindCharsByteArrayBinOp>()), ctx);
    ctx = Context::make(abarraycat, Ptr::of<BaseMacro>(Function<ConcatByteArrayBinOp>()), ctx);
    ctx = Context::make(abarraymid, Ptr::of<BaseMacro>(Function<MidByteArrayTerOp>()), ctx);

    ctx = Context::make(aserint, Ptr::of<BaseMacro>(Function<SerializeUnOp<int> >()), ctx);
    ctx = Context::make(aserfloat, Ptr::of<BaseMacro>(Function<SerializeUnOp<double> >()), ctx);
    ctx = Context::make(aserchar, Ptr::of<BaseMacro>(Function<SerializeUnOp<char> >()), ctx);

    ctx = Context::make(agetint, Ptr::of<BaseMacro>(Function<ByteArrayGetBinOp<int> >()), ctx);
    ctx = Context::make(agetfloat, Ptr::of<BaseMacro>(Function<ByteArrayGetBinOp<double> >()), ctx);
    ctx = Context::make(agetchar, Ptr::of<BaseMacro>(Function<ByteArrayGetBinOp<char> >()), ctx);

    return ctx;
}

const ByteArrayFunctions &ByteArrayFunctions::inst()
{
    static const ByteArrayFunctions instance;
    return instance;
}

} // namespaces
