#include <objects/bytearray_obs.h>

#include <operations/bytearray_ops.h>
#include <operations/typepredicates_ops.h>
#include <builtin/operations.h>

namespace stepone::objects {

using namespace builtin;
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
    Ptr ctx = Context::make(abarrayp, Ptr::of<BuiltInMacro>(Function<TypePUnOp<ByteArray>>()), a);
    ctx = Context::make(abarraylen, Ptr::of<BuiltInMacro>(Function<ByteArrayLengthUnOp>()), ctx);
    ctx = Context::make(abarrayclone, Ptr::of<BuiltInMacro>(Function<ByteArrayCloneUnOp>()), ctx);
    ctx = Context::make(abarraycmp, Ptr::of<BuiltInMacro>(Function<CompareByteArrayBinOp>()), ctx);
    ctx = Context::make(abarrayncmp, Ptr::of<BuiltInMacro>(Function<NCompareByteArrayTerOp>()), ctx);
    ctx = Context::make(abarrayfindch, Ptr::of<BuiltInMacro>(Function<FindCharByteArrayBinOp>()), ctx);
    ctx = Context::make(abarrayfind, Ptr::of<BuiltInMacro>(Function<FindCharsByteArrayBinOp>()), ctx);
    ctx = Context::make(abarraycat, Ptr::of<BuiltInMacro>(Function<ConcatByteArrayBinOp>()), ctx);
    ctx = Context::make(abarraymid, Ptr::of<BuiltInMacro>(Function<MidByteArrayTerOp>()), ctx);

    ctx = Context::make(aserint, Ptr::of<BuiltInMacro>(Function<SerializeUnOp<long> >()), ctx);
    ctx = Context::make(aserfloat, Ptr::of<BuiltInMacro>(Function<SerializeUnOp<double> >()), ctx);
    ctx = Context::make(aserchar, Ptr::of<BuiltInMacro>(Function<SerializeUnOp<char> >()), ctx);

    ctx = Context::make(agetint, Ptr::of<BuiltInMacro>(Function<ByteArrayGetBinOp<long> >()), ctx);
    ctx = Context::make(agetfloat, Ptr::of<BuiltInMacro>(Function<ByteArrayGetBinOp<double> >()), ctx);
    ctx = Context::make(agetchar, Ptr::of<BuiltInMacro>(Function<ByteArrayGetBinOp<char> >()), ctx);

    return ctx;
}

const ByteArrayFunctions &ByteArrayFunctions::inst()
{
    static const ByteArrayFunctions instance;
    return instance;
}

} // namespaces
