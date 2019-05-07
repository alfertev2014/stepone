#include <impl/objects/bytearray_obs.h>

#include <impl/operations/bytearray_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

ByteArrayFunctions::ByteArrayFunctions() :
    fbarrayp(Ob::of<BaseMacro>(FTypeP<ByteArray>::apply)),
    fbarraylen(Ob::of<BaseMacro>(FUnaryOp<ByteArrayLengthUnOp>::apply)),
    fbarrayclone(Ob::of<BaseMacro>(FUnaryOp<ByteArrayCloneUnOp>::apply)),
    fbarraycmp(Ob::of<BaseMacro>(FBinaryOp<CompareByteArrayBinOp>::apply)),
    fbarrayncmp(Ob::of<BaseMacro>(FTernaryOp<NCompareByteArrayTerOp>::apply)),
    fbarrayfindch(Ob::of<BaseMacro>(FBinaryOp<FindCharByteArrayBinOp>::apply)),
    fbarrayfind(Ob::of<BaseMacro>(FBinaryOp<FindCharsByteArrayBinOp>::apply)),
    fbarraycat(Ob::of<BaseMacro>(FBinaryOp<ConcatByteArrayBinOp>::apply)),
    fbarraymid(Ob::of<BaseMacro>(FTernaryOp<MidByteArrayTerOp>::apply)),

    fserint(Ob::of<BaseMacro>(FUnaryOp<SerializeUnOp<int> >::apply)),
    fserfloat(Ob::of<BaseMacro>(FUnaryOp<SerializeUnOp<float> >::apply)),
    fserchar(Ob::of<BaseMacro>(FUnaryOp<SerializeUnOp<char> >::apply)),

    fgetint(Ob::of<BaseMacro>(FBinaryOp<ByteArrayGetBinOp<int> >::apply)),
    fgetfloat(Ob::of<BaseMacro>(FBinaryOp<ByteArrayGetBinOp<float> >::apply)),
    fgetchar(Ob::of<BaseMacro>(FBinaryOp<ByteArrayGetBinOp<char> >::apply))
{}


const ByteArrayFunctions &ByteArrayFunctions::inst()
{
    static const ByteArrayFunctions instance;
    return instance;
}

} // namespaces
