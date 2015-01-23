#include "basefunc.h"
#include "operations.h"

BaseFunctions::BaseFunctions() :
    fcar(new FUnaryOp<CarUnOp>),
    fcdr(new FUnaryOp<CdrUnOp>),
    fcons(new FBinaryOp<ConsBinOp>),
    feq(new FBinaryOp<EqBinOp>),
    fgettype(new FUnaryOp<GetTypeUnOp>),
    fctxget(new FBinaryOp<ContextGetBinOp>),
    fctxpush(new FTernaryOp<ContextPushTerOp>)
{}

const BaseFunctions &BaseFunctions::inst()
{
    static const BaseFunctions instance;
    return instance;
}
