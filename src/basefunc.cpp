#include "basefunc.h"
#include "operations.h"

const Ob::Ptr BaseFunctions::fcar(new FCar);
const Ob::Ptr BaseFunctions::fcdr(new FCdr);
const Ob::Ptr BaseFunctions::fcons(new FBinaryOp<ConsBinOp>);
const Ob::Ptr BaseFunctions::feq(new FBinaryOp<EqBinOp>);
const Ob::Ptr BaseFunctions::fgettype(new FGetType);
const Ob::Ptr BaseFunctions::fctxget(new FBinaryOp<ContextGetBinOp>);
const Ob::Ptr BaseFunctions::fctxpush(new FTernaryOp<ContextPushTerOp>);
