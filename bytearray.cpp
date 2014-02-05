#include "bytearray.h"
#include "funcstemp.h"

const Ob::Ptr ByteArrayFunctions::fbytesp(new FTypeP<ByteArray>);
const Ob::Ptr ByteArrayFunctions::fbyteslen(new FByteArrayLength);
const Ob::Ptr ByteArrayFunctions::fbytescat(new FBinaryOp<ConcatByteArrayBinOp>);
const Ob::Ptr ByteArrayFunctions::fbytesmid(new FTernaryOp<MidByteArrayTerOp>);
const Ob::Ptr ByteArrayFunctions::fserint(new FSerialize<int>);
const Ob::Ptr ByteArrayFunctions::fserfloat(new FSerialize<float>);
const Ob::Ptr ByteArrayFunctions::fserbyte(new FSerializeBytes<char>);
const Ob::Ptr ByteArrayFunctions::fser2bytes(new FSerializeBytes<short>);
const Ob::Ptr ByteArrayFunctions::fser4bytes(new FSerializeBytes<int>);
const Ob::Ptr ByteArrayFunctions::fser8bytes(new FSerializeBytes<long long>);
const Ob::Ptr ByteArrayFunctions::fgetint(new FBinaryOp<ByteArrayGetBinOp<int> >);
const Ob::Ptr ByteArrayFunctions::fgetfloat(new FBinaryOp<ByteArrayGetBinOp<float> >);
const Ob::Ptr ByteArrayFunctions::fgetbyte(new FBinaryOp<ByteArrayGetBytesBinOp<char> >);
const Ob::Ptr ByteArrayFunctions::fget2bytes(new FBinaryOp<ByteArrayGetBytesBinOp<short> >);
const Ob::Ptr ByteArrayFunctions::fget4bytes(new FBinaryOp<ByteArrayGetBytesBinOp<int> >);
const Ob::Ptr ByteArrayFunctions::fget8bytes(new FBinaryOp<ByteArrayGetBytesBinOp<long long> >);
