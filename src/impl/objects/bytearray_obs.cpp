#include "bytearray_obs.h"

#include <impl/operations/bytearray_ops.h>
#include <impl/base/operations.h>

ByteArrayFunctions::ByteArrayFunctions() :
    fbarrayp(new FTypeP<ByteArray>),
    fbarraylen(new FUnaryOp<ByteArrayLengthUnOp>),
    fbarrayclone(new FUnaryOp<ByteArrayCloneUnOp>),
    fbarraycmp(new FBinaryOp<CompareByteArrayBinOp>),
    fbarrayncmp(new FTernaryOp<NCompareByteArrayTerOp>),
    fbarrayfindch(new FBinaryOp<FindCharByteArrayBinOp>),
    fbarrayfind(new FBinaryOp<FindCharsByteArrayBinOp>),
    fbarraycat(new FBinaryOp<ConcatByteArrayBinOp>),
    fbarraymid(new FTernaryOp<MidByteArrayTerOp>),
    fbarrayslice(new FTernaryOp<SliceByteArrayTerOp>),


    fserint(new FUnaryOp<SerializeUnOp<int> >),
    fserfloat(new FUnaryOp<SerializeUnOp<float> >),
    fserchar(new FUnaryOp<SerializeUnOp<char> >),

    fgetint(new FBinaryOp<ByteArrayGetBinOp<int> >),
    fgetfloat(new FBinaryOp<ByteArrayGetBinOp<float> >),
    fgetchar(new FBinaryOp<ByteArrayGetBinOp<char> >)
{}


const ByteArrayFunctions &ByteArrayFunctions::inst()
{
    static const ByteArrayFunctions instance;
    return instance;
}
