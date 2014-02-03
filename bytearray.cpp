#include "bytearray.h"
#include "funcstemp.h"

const Ob::Ptr ByteArrayFunctions::fbytesp(new FTypeP<ByteArray>);
const Ob::Ptr ByteArrayFunctions::fbytescat(new FBinaryOp<ConcatByteArrayBinOp>);
const Ob::Ptr ByteArrayFunctions::fbytesmid(new FTernaryOp<MidByteArrayTerOp>);
const Ob::Ptr ByteArrayFunctions::fserint(new FSerialize<int>);
const Ob::Ptr ByteArrayFunctions::fserfloat(new FSerialize<float>);
const Ob::Ptr ByteArrayFunctions::fgetint(new FBinaryOp<ByteArrayGetBinOp<int> >);
const Ob::Ptr ByteArrayFunctions::fgetfloat(new FBinaryOp<ByteArrayGetBinOp<int> >);
