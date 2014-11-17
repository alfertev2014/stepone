#include "basemacro.h"

const Ob::Ptr BaseMacroses::mquote(new MQuote());
const Ob::Ptr BaseMacroses::mapply(new MApply());
const Ob::Ptr BaseMacroses::mif(new MIf());
const Ob::Ptr BaseMacroses::mlet(new MLet());
const Ob::Ptr BaseMacroses::mlazy(new MLazy());
const Ob::Ptr BaseMacroses::munlazy(new MUnlazy());
const Ob::Ptr BaseMacroses::mlabel(new MLabel());
const Ob::Ptr BaseMacroses::mlambda(new MLambda());
const Ob::Ptr BaseMacroses::mmacro(new MMacro());
const Ob::Ptr BaseMacroses::mcurctx(new MCurrentContext());
const Ob::Ptr BaseMacroses::mtry(new MTry());
const Ob::Ptr BaseMacroses::mbot(new MBot());
const Ob::Ptr BaseMacroses::mgensym(new MGenSymbol());
const Ob::Ptr BaseMacroses::mgettype(new MGetType());
