#include <impl/objects/bytearray_obs.h>

#include <impl/operations/bytearray_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

ByteArrayFunctions::ByteArrayFunctions() :
    fbarrayp(new Ob(FTypeP<ByteArray>::apply)),
    fbarraylen(new Ob(FUnaryOp<ByteArrayLengthUnOp>::apply)),
    fbarrayclone(new Ob(FUnaryOp<ByteArrayCloneUnOp>::apply)),
    fbarraycmp(new Ob(FBinaryOp<CompareByteArrayBinOp>::apply)),
    fbarrayncmp(new Ob(FTernaryOp<NCompareByteArrayTerOp>::apply)),
    fbarrayfindch(new Ob(FBinaryOp<FindCharByteArrayBinOp>::apply)),
    fbarrayfind(new Ob(FBinaryOp<FindCharsByteArrayBinOp>::apply)),
    fbarraycat(new Ob(FBinaryOp<ConcatByteArrayBinOp>::apply)),
    fbarraymid(new Ob(FTernaryOp<MidByteArrayTerOp>::apply)),


    fserint(new Ob(FUnaryOp<SerializeUnOp<int> >::apply)),
    fserfloat(new Ob(FUnaryOp<SerializeUnOp<float> >::apply)),
    fserchar(new Ob(FUnaryOp<SerializeUnOp<char> >::apply)),

    fgetint(new Ob(FBinaryOp<ByteArrayGetBinOp<int> >::apply)),
    fgetfloat(new Ob(FBinaryOp<ByteArrayGetBinOp<float> >::apply)),
    fgetchar(new Ob(FBinaryOp<ByteArrayGetBinOp<char> >::apply))
{}


const ByteArrayFunctions &ByteArrayFunctions::inst()
{
    static const ByteArrayFunctions instance;
    return instance;
}

} // namespaces
