#include <impl/objects/bytearray_obs.h>

#include <impl/operations/bytearray_ops.h>
#include <impl/operations/typepredicates_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

ByteArrayFunctions::ByteArrayFunctions() :
    fbarrayp(Ob::of<BaseMacro>(Function<TypePUnOp<ByteArray>>())),
    fbarraylen(Ob::of<BaseMacro>(Function<ByteArrayLengthUnOp>())),
    fbarrayclone(Ob::of<BaseMacro>(Function<ByteArrayCloneUnOp>())),
    fbarraycmp(Ob::of<BaseMacro>(Function<CompareByteArrayBinOp>())),
    fbarrayncmp(Ob::of<BaseMacro>(Function<NCompareByteArrayTerOp>())),
    fbarrayfindch(Ob::of<BaseMacro>(Function<FindCharByteArrayBinOp>())),
    fbarrayfind(Ob::of<BaseMacro>(Function<FindCharsByteArrayBinOp>())),
    fbarraycat(Ob::of<BaseMacro>(Function<ConcatByteArrayBinOp>())),
    fbarraymid(Ob::of<BaseMacro>(Function<MidByteArrayTerOp>())),

    fserint(Ob::of<BaseMacro>(Function<SerializeUnOp<int> >())),
    fserfloat(Ob::of<BaseMacro>(Function<SerializeUnOp<float> >())),
    fserchar(Ob::of<BaseMacro>(Function<SerializeUnOp<char> >())),

    fgetint(Ob::of<BaseMacro>(Function<ByteArrayGetBinOp<int> >())),
    fgetfloat(Ob::of<BaseMacro>(Function<ByteArrayGetBinOp<float> >())),
    fgetchar(Ob::of<BaseMacro>(Function<ByteArrayGetBinOp<char> >()))
{}


const ByteArrayFunctions &ByteArrayFunctions::inst()
{
    static const ByteArrayFunctions instance;
    return instance;
}

} // namespaces
