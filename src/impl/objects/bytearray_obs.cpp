#include <impl/objects/bytearray_obs.h>

#include <impl/operations/bytearray_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

ByteArrayFunctions::ByteArrayFunctions() :
    fbarrayp(new Ob(BaseMacro(FTypeP<ByteArray>::apply))),
    fbarraylen(new Ob(BaseMacro(FUnaryOp<ByteArrayLengthUnOp>::apply))),
    fbarrayclone(new Ob(BaseMacro(FUnaryOp<ByteArrayCloneUnOp>::apply))),
    fbarraycmp(new Ob(BaseMacro(FBinaryOp<CompareByteArrayBinOp>::apply))),
    fbarrayncmp(new Ob(BaseMacro(FTernaryOp<NCompareByteArrayTerOp>::apply))),
    fbarrayfindch(new Ob(BaseMacro(FBinaryOp<FindCharByteArrayBinOp>::apply))),
    fbarrayfind(new Ob(BaseMacro(FBinaryOp<FindCharsByteArrayBinOp>::apply))),
    fbarraycat(new Ob(BaseMacro(FBinaryOp<ConcatByteArrayBinOp>::apply))),
    fbarraymid(new Ob(BaseMacro(FTernaryOp<MidByteArrayTerOp>::apply))),

    fserint(new Ob(BaseMacro(FUnaryOp<SerializeUnOp<int> >::apply))),
    fserfloat(new Ob(BaseMacro(FUnaryOp<SerializeUnOp<float> >::apply))),
    fserchar(new Ob(BaseMacro(FUnaryOp<SerializeUnOp<char> >::apply))),

    fgetint(new Ob(BaseMacro(FBinaryOp<ByteArrayGetBinOp<int> >::apply))),
    fgetfloat(new Ob(BaseMacro(FBinaryOp<ByteArrayGetBinOp<float> >::apply))),
    fgetchar(new Ob(BaseMacro(FBinaryOp<ByteArrayGetBinOp<char> >::apply)))
{}


const ByteArrayFunctions &ByteArrayFunctions::inst()
{
    static const ByteArrayFunctions instance;
    return instance;
}

} // namespaces
