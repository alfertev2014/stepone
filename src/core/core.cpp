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

template<>
Atom *Ob::as<Atom>() {return typeFlags.obType == TypeFlags::Atom ? dynamic_cast<Atom*>(this) : 0;}

template<>
Lazy *Ob::as<Lazy>() {return typeFlags.obType == TypeFlags::Lazy ? dynamic_cast<Lazy*>(this) : 0;}

template<>
Pair *Ob::as<Pair>() {return typeFlags.obType == TypeFlags::Pair ? dynamic_cast<Pair*>(this) : 0;}

template<>
Label *Ob::as<Label>() {return typeFlags.obType == TypeFlags::Label ? dynamic_cast<Label*>(this) : 0;}

template<>
Symbol *Ob::as<Symbol>() {return typeFlags.atomType == TypeFlags::Symbol ? dynamic_cast<Symbol*>(this) : 0;}

template<>
Const *Ob::as<Const>() {return typeFlags.atomType == TypeFlags::Const ? dynamic_cast<Const*>(this) : 0;}

const TypeInfoBase *Pair::getTypeInfo() const {return &TypeInfo<Pair>::instance;}

Ob::Ptr Pair::car() {return pcar;}

Ob::Ptr Pair::cdr() {return pcdr;}

Ob::Ptr Pair::eval(const Ob::Ptr &a) {return pcar->eval(a)->apply(pcdr, a);}

Atom::~Atom() {}

const TypeInfoBase *Lazy::getTypeInfo() const {return &TypeInfo<Lazy>::instance;}

inline void Lazy::ev() {
    if(!(a == Ob::anil)) {
        e = e->eval(a);
        a = Ob::anil;
    }
}

inline void Lazy::evw() {
    ev();
    Lazy * l = e->as<Lazy>();
    while(l != 0) {
        l->ev();
        e = l->e;
        l = e->as<Lazy>();
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
