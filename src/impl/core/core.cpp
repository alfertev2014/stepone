#include <impl/core/core.h>
#include <impl/ptr_impl.h>
#include <impl/core/type_info_inst.h>

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

Ptr Pair::car() {return pcar;}

Ptr Pair::cdr() {return pcdr;}

Ptr Pair::eval(const Ptr &a) {return pcar.eval(a).apply(pcdr, a);}

Atom::~Atom() {}

const TypeInfoBase *Lazy::getTypeInfo() const {return &TypeInfo<Lazy>::instance;}

inline void Lazy::ev() {
    if(!(a == Ptr::anil)) {
        e = e.eval(a);
        a = Ptr::anil;
    }
}

inline void Lazy::evw() {
    ev();
    Lazy * l = e.as<Lazy>();
    while(l != 0) {
        l->ev();
        e = l->e;
        l = e.as<Lazy>();
    }
}

Ptr Lazy::car() {evw(); return e.car();}

Ptr Lazy::cdr() {evw(); return e.cdr();}

Ptr Lazy::eval(const Ptr &a) {evw(); return e.eval(a);}

Ptr Lazy::apply(const Ptr &p, const Ptr &a) {
    evw(); return e.apply(p, a);
}

Ptr Lazy::unlazy() {evw(); return e;}

const TypeInfoBase *Label::getTypeInfo() const {return &TypeInfo<Label>::instance;}

inline Ptr Label::ptr() {
    if(pa) {
        return v.eval(*pa);
    }
    return v;
}

Ptr Label::loop(const Ptr &f, const Ptr &e, const Ptr &a) {
    Label * l = new Label(e, &a);
    Ptr lbl = l;
    Ptr res = e.eval(Context::make(f, lbl, a));
    l->v = res;
    l->pa = 0;
    return res;
}



Ptr Label::car() {return ptr().car();}

Ptr Label::cdr() {return ptr().cdr();}

Ptr Label::eval(const Ptr &a) {return ptr().eval(a);}

Ptr Label::apply(const Ptr &p, const Ptr &a) {return ptr().apply(p, a);}

Ptr Label::unlazy() {return ptr().unlazy();}

const TypeInfoBase *Symbol::getTypeInfo() const {return &TypeInfo<Symbol>::instance;}

Ptr Symbol::eval(const Ptr &a) {
    Ptr p = a;
    while(p != Ptr::anil) {
        Ptr pair = p.car();
        if(pair.car() == this)
            return pair.cdr();
        p = p.cdr();
    }
    DBG("Unknown symbol");
    throw SemanticError();
}

Const::~Const() {}

Ptr Const::eval(const Ptr &a) {return this;}
