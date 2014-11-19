#include "io.h"

Ob::Ptr IOFunctions::finputp(new FTypeP<InputDescriptor>);
Ob::Ptr IOFunctions::foutputp(new FTypeP<OutputDescriptor>);
Ob::Ptr IOFunctions::fopenin(new FUnaryOp<InputOpenUnOp>);
Ob::Ptr IOFunctions::fopenout(new FUnaryOp<OutputOpenUnOp>);
Ob::Ptr IOFunctions::fread(new FBinaryOp<ReadBinOp>);
Ob::Ptr IOFunctions::fwrite(new FBinaryOp<WriteBinOp>);
