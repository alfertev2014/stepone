#include "bytearray.h"
#include "operations.h"

const Ob::Ptr ByteArrayFunctions::fbarrayp(new FTypeP<ByteArray>);
const Ob::Ptr ByteArrayFunctions::fbarraylen(new FUnaryOp<ByteArrayLengthUnOp>);
const Ob::Ptr ByteArrayFunctions::fbarrayclone(new FUnaryOp<ByteArrayCloneUnOp>);
const Ob::Ptr ByteArrayFunctions::fbarraycmp(new FBinaryOp<CompareByteArrayBinOp>);
const Ob::Ptr ByteArrayFunctions::fbarrayncmp(new FTernaryOp<NCompareByteArrayTerOp>);
const Ob::Ptr ByteArrayFunctions::fbarrayfindch(new FBinaryOp<FindCharByteArrayBinOp>);
const Ob::Ptr ByteArrayFunctions::fbarrayfind(new FBinaryOp<FindCharsByteArrayBinOp>);
const Ob::Ptr ByteArrayFunctions::fbarraycat(new FBinaryOp<ConcatByteArrayBinOp>);
const Ob::Ptr ByteArrayFunctions::fbarraymid(new FTernaryOp<MidByteArrayTerOp>);
const Ob::Ptr ByteArrayFunctions::fbarrayslice(new FTernaryOp<SliceByteArrayTerOp>);


const Ob::Ptr ByteArrayFunctions::fserint(new FUnaryOp<SerializeUnOp<int> >);
const Ob::Ptr ByteArrayFunctions::fserfloat(new FUnaryOp<SerializeUnOp<float> >);
const Ob::Ptr ByteArrayFunctions::fserchar(new FUnaryOp<SerializeUnOp<char> >);

const Ob::Ptr ByteArrayFunctions::fgetint(new FBinaryOp<ByteArrayGetBinOp<int> >);
const Ob::Ptr ByteArrayFunctions::fgetfloat(new FBinaryOp<ByteArrayGetBinOp<float> >);
const Ob::Ptr ByteArrayFunctions::fgetchar(new FBinaryOp<ByteArrayGetBinOp<char> >);
