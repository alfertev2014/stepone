#include "bytearray.h"
#include "operations.h"

const Ob::Ptr ByteArrayFunctions::fbarrayp(new FTypeP<ByteArray>);
const Ob::Ptr ByteArrayFunctions::fbarraylen(new FByteArrayLength);
const Ob::Ptr ByteArrayFunctions::fbarrayclone(new FByteArrayClone);
const Ob::Ptr ByteArrayFunctions::fbarraycmp(new FBinaryOp<CompareByteArrayBinOp>);
const Ob::Ptr ByteArrayFunctions::fbarrayncmp(new FTernaryOp<NCompareByteArrayTerOp>);
const Ob::Ptr ByteArrayFunctions::fbarrayfindch(new FBinaryOp<FindCharByteArrayBinOp>);
const Ob::Ptr ByteArrayFunctions::fbarrayfind(new FBinaryOp<FindCharsByteArrayBinOp>);
const Ob::Ptr ByteArrayFunctions::fbarraycat(new FBinaryOp<ConcatByteArrayBinOp>);
const Ob::Ptr ByteArrayFunctions::fbarraymid(new FTernaryOp<MidByteArrayTerOp>);
const Ob::Ptr ByteArrayFunctions::fbarrayslice(new FTernaryOp<SliceByteArrayTerOp>);


const Ob::Ptr ByteArrayFunctions::fserint(new FSerialize<int>);
const Ob::Ptr ByteArrayFunctions::fserfloat(new FSerialize<float>);
const Ob::Ptr ByteArrayFunctions::fserchar(new FSerialize<char>);

const Ob::Ptr ByteArrayFunctions::fgetint(new FBinaryOp<ByteArrayGetBinOp<int> >);
const Ob::Ptr ByteArrayFunctions::fgetfloat(new FBinaryOp<ByteArrayGetBinOp<float> >);
const Ob::Ptr ByteArrayFunctions::fgetchar(new FBinaryOp<ByteArrayGetBinOp<char> >);
