#include <core.h>

const Ob::Ptr Ob::anil(new Symbol);
const Ob::Ptr Ob::at(new Symbol);

TypeInfoBase::TypeInfoBase() :
    type_id(new Symbol)
{}

Ob::~Ob() {}

Ob::Ptr Ob::car() {DBG("throw car "); throw SemanticError();}

Ob::Ptr Ob::cdr() {DBG("throw cdr "); throw SemanticError();}

Ob::Ptr Ob::eval(const Ob::Ptr &a) {throw SemanticError();}

Ob::Ptr Ob::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    if(p == Ob::anil) return this;
    DBG("apply of not applyable"); throw SemanticError();
}

Ob::Ptr Ob::unlazy() {return this;}

Ob::Ptr Ob::assoc(const Ob::Ptr &s) const {DBG("throw assoc "); throw SemanticError();}

Atom *Ob::asAtom() {return typeFlags.obType == TypeFlags::Atom ? reinterpret_cast<Atom*>(this) : 0;}

Lazy *Ob::asLazy() {return typeFlags.obType == TypeFlags::Lazy ? reinterpret_cast<Lazy*>(this) : 0;}

Pair *Ob::asPair() {return typeFlags.obType == TypeFlags::Pair ? reinterpret_cast<Pair*>(this) : 0;}

Label *Ob::asLabel() {return typeFlags.obType == TypeFlags::Label ? reinterpret_cast<Label*>(this) : 0;}

Symbol *Ob::asSymbol() {return typeFlags.atomType == TypeFlags::Symbol ? reinterpret_cast<Symbol*>(this) : 0;}

Const *Ob::asConst() {return typeFlags.atomType == TypeFlags::Const ? reinterpret_cast<Const*>(this) : 0;}

Macro *Ob::asMacro() {return typeFlags.constType == TypeFlags::Macro ? reinterpret_cast<Macro*>(this) : 0;}

ValueBase *Ob::asValue() {return typeFlags.constType == TypeFlags::ValueBase ? reinterpret_cast<ValueBase*>(this) : 0;}

Evaluator *Ob::asEvaluator() {return typeFlags.macroValueType == TypeFlags::Evaluator ? reinterpret_cast<Evaluator*>(this) : 0;}

BaseMacro *Ob::asBaseMacro() {return typeFlags.macroValueType == TypeFlags::BaseMacro ? reinterpret_cast<BaseMacro*>(this) : 0;}

MacroClosure *Ob::asMacroClosure() {return typeFlags.macroValueType == TypeFlags::MacroClosure ? reinterpret_cast<MacroClosure*>(this) : 0;}

CurrentContext *Ob::asCurrentContext() {return typeFlags.macroValueType == TypeFlags::CurrentContext ? reinterpret_cast<CurrentContext*>(this) : 0;}



const TypeInfoBase *Pair::getTypeInfo() const {return &TypeInfo<Pair>::instance;}

Ob::Ptr Pair::car() {return pcar;}

Ob::Ptr Pair::cdr() {return pcdr;}

Ob::Ptr Pair::eval(const Ob::Ptr &a) {return pcar->eval(a)->apply(pcdr, a);}

Atom::~Atom() {}

const TypeInfoBase *Lazy::getTypeInfo() const {return &TypeInfo<Lazy>::instance;}

inline void Lazy::ev() {
    if(!ready) {
        e = e->eval(a);
        ready = true;
        a = Ob::anil;
    }
}

inline void Lazy::evw() {
    ev();
    Lazy * l = e->asLazy();
    while(l != 0) {
        l->ev();
        e = l->e;
        l = e->asLazy();
    }
}

Ob::Ptr Lazy::car() {evw(); return e->car();}

Ob::Ptr Lazy::cdr() {evw(); return e->cdr();}

Ob::Ptr Lazy::eval(const Ob::Ptr &a) {evw(); return e->eval(a);}

Ob::Ptr Lazy::apply(const Ob::Ptr &p, const Ob::Ptr &a) {
    evw(); return e->apply(p, a);
}

Ob::Ptr Lazy::unlazy() {evw(); return e;}

const TypeInfoBase *Label::getTypeInfo() const {return &TypeInfo<Label>::instance;}

inline Ob::Ptr Label::ptr() {
    if(pa) {
        return v->eval(*pa);
    }
    return v;
}



Ob::Ptr Label::car() {return ptr()->car();}

Ob::Ptr Label::cdr() {return ptr()->cdr();}

Ob::Ptr Label::eval(const Ob::Ptr &a) {return ptr()->eval(a);}

Ob::Ptr Label::apply(const Ob::Ptr &p, const Ob::Ptr &a) {return ptr()->apply(p, a);}

Ob::Ptr Label::unlazy() {return ptr()->unlazy();}

const TypeInfoBase *Symbol::getTypeInfo() const {return &TypeInfo<Symbol>::instance;}

Ob::Ptr Symbol::eval(const Ob::Ptr &a) {
    Ptr p = a;
    while(!(p == anil)) {
        Ptr pair = p->car();
        if(pair->car().getPointer() == this)
            return pair->cdr();
        p = p->cdr();
    }
    DBG("Unknown symbol");
    throw SemanticError();
}

Const::~Const() {}

Ob::Ptr Const::eval(const Ob::Ptr &a) {return this;}
