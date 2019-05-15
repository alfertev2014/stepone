#include <impl/objects/bytearray_obs.h>

#include <impl/operations/bytearray_ops.h>
#include <impl/operations/typepredicates_ops.h>
#include <impl/base/operations.h>

namespace stepone::objects {

using namespace base;
using namespace operations;

ByteArrayFunctions::ByteArrayFunctions() :
    fbarrayp(Ob::of<BaseMacro>(Function(TypePUnOp<ByteArray>::op))),
    fbarraylen(Ob::of<BaseMacro>(Function(ByteArrayLengthUnOp::op))),
    fbarrayclone(Ob::of<BaseMacro>(Function(ByteArrayCloneUnOp::op))),
    fbarraycmp(Ob::of<BaseMacro>(Function(CompareByteArrayBinOp::op))),
    fbarrayncmp(Ob::of<BaseMacro>(Function(NCompareByteArrayTerOp::op))),
    fbarrayfindch(Ob::of<BaseMacro>(Function(FindCharByteArrayBinOp::op))),
    fbarrayfind(Ob::of<BaseMacro>(Function(FindCharsByteArrayBinOp::op))),
    fbarraycat(Ob::of<BaseMacro>(Function(ConcatByteArrayBinOp::op))),
    fbarraymid(Ob::of<BaseMacro>(Function(MidByteArrayTerOp::op))),

    fserint(Ob::of<BaseMacro>(Function(SerializeUnOp<int> ::op))),
    fserfloat(Ob::of<BaseMacro>(Function(SerializeUnOp<float> ::op))),
    fserchar(Ob::of<BaseMacro>(Function(SerializeUnOp<char> ::op))),

    fgetint(Ob::of<BaseMacro>(Function(ByteArrayGetBinOp<int> ::op))),
    fgetfloat(Ob::of<BaseMacro>(Function(ByteArrayGetBinOp<float> ::op))),
    fgetchar(Ob::of<BaseMacro>(Function(ByteArrayGetBinOp<char> ::op)))
{}


const ByteArrayFunctions &ByteArrayFunctions::inst()
{
    static const ByteArrayFunctions instance;
    return instance;
}

} // namespaces
