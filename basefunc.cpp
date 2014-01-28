#include "basefunc.h"

const Ob::Ptr BaseFunctions::fcar(new FCar);
const Ob::Ptr BaseFunctions::fcdr(new FCdr);
const Ob::Ptr BaseFunctions::fcons(new FCons);
const Ob::Ptr BaseFunctions::feq(new FEq);
const Ob::Ptr BaseFunctions::fctxget(new FContextGet);
const Ob::Ptr BaseFunctions::fctxpush(new FContextPush);
