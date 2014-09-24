#include "bytearray.h"
#include "operations.h"

const Ob::Ptr ByteArrayFunctions::fbarrayp(new FTypeP<ByteArray>);
const Ob::Ptr ByteArrayFunctions::fbslicep(new FTypeP<ByteArraySlice>);
const Ob::Ptr ByteArrayFunctions::fbarraylen(new FByteArrayLength);
const Ob::Ptr ByteArrayFunctions::fbslicelen(new FByteArraySliceLength);
const Ob::Ptr ByteArrayFunctions::fbarraycat(new FBinaryOp<ConcatByteArrayBinOp>);
const Ob::Ptr ByteArrayFunctions::fbslicecat(new FBinaryOp<ConcatByteArraySliceBinOp>);
const Ob::Ptr ByteArrayFunctions::fbarraymid(new FTernaryOp<MidByteArrayTerOp>);
const Ob::Ptr ByteArrayFunctions::fbslicemid(new FTernaryOp<MidByteArraySliceTerOp>);


const Ob::Ptr ByteArrayFunctions::fserint(new FSerialize<int>);
const Ob::Ptr ByteArrayFunctions::fserfloat(new FSerialize<float>);
const Ob::Ptr ByteArrayFunctions::fserchar(new FSerialize<char>);

const Ob::Ptr ByteArrayFunctions::fgetint(new FBinaryOp<ByteArrayGetBinOp<int> >);
const Ob::Ptr ByteArrayFunctions::fgetfloat(new FBinaryOp<ByteArrayGetBinOp<float> >);
const Ob::Ptr ByteArrayFunctions::fgetchar(new FBinaryOp<ByteArrayGetBinOp<char> >);
