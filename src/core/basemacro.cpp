#include <basemacro.h>

const TypeInfoBase *MQuote::getTypeInfo() const {return &TypeInfo<MQuote>::instance;}

Ob::Ptr MQuote::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    return p;
}

const TypeInfoBase *MApply::getTypeInfo() const {return &TypeInfo<MApply>::instance;}

Ob::Ptr MApply::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    return p->car()->eval(a)->apply(p->cdr(), a);
}

const TypeInfoBase *MIf::getTypeInfo() const {return &TypeInfo<MIf>::instance;}

Ob::Ptr MIf::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    if(p->car()->eval(a) == Ob::anil)
        return p->cdr()->cdr()->eval(a);
    else
        return p->cdr()->car()->eval(a);
}

const TypeInfoBase *MLet::getTypeInfo() const {return &TypeInfo<MLet>::instance;}

Ob::Ptr MLet::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    Ob::Ptr val = p->cdr();
    return val->cdr()->eval(Context::make(p->car(), val->car()->eval(a), a));
}

const TypeInfoBase *MLazy::getTypeInfo() const {return &TypeInfo<MLazy>::instance;}

Ob::Ptr MLazy::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    return new Lazy(p, a);
}

const TypeInfoBase *MUnlazy::getTypeInfo() const {return &TypeInfo<MUnlazy>::instance;}

Ob::Ptr MUnlazy::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    return p->eval(a)->unlazy();
}

const TypeInfoBase *MLabel::getTypeInfo() const {return &TypeInfo<MLabel>::instance;}

Ob::Ptr MLabel::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    return Label::loop(p->car(), p->cdr(), a);
}

const TypeInfoBase *MLambda::getTypeInfo() const {return &TypeInfo<MLambda>::instance;}

Ob::Ptr MLambda::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    return new Closure(p->car(), p->cdr(), a);
}

const TypeInfoBase *MMacro::getTypeInfo() const {return &TypeInfo<MMacro>::instance;}

Ob::Ptr MMacro::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    return new MacroClosure(p->car(), p->cdr(), a);
}

const TypeInfoBase *MCurrentContext::getTypeInfo() const {return &TypeInfo<MCurrentContext>::instance;}

Ob::Ptr MCurrentContext::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    return new CurrentContext(p->car(), p->cdr(), a);
}

const TypeInfoBase *MTry::getTypeInfo() const {return &TypeInfo<MTry>::instance;}

Ob::Ptr MTry::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    try {
        return p->car()->eval(a);
    } catch(SemanticError e) {
        return p->cdr()->eval(a);
    }
}

const TypeInfoBase *MBot::getTypeInfo() const {return &TypeInfo<MBot>::instance;}

Ob::Ptr MBot::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    throw SemanticError();
}

const TypeInfoBase *MGenSymbol::getTypeInfo() const {return &TypeInfo<MGenSymbol>::instance;}

Ob::Ptr MGenSymbol::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    return new Symbol;
}
