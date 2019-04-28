#include <impl/core/core.h>
#include <impl/ptr_impl.h>

namespace stepone::core {

Ptr Pair::car() {return pcar;}

Ptr Pair::cdr() {return pcdr;}

Ptr Pair::eval(const Ptr &a) {return pcar.eval(a).apply(pcdr, a);}

Atom::~Atom() {}

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

Ptr Symbol::eval(const Ptr &a) {
    Ptr p = a;
    while(p != Ptr::anil) {
        Ptr pair = p.car();
        if(pair.car() == this)
            return pair.cdr();
        p = p.cdr();
    }
    throw SemanticError("Unknown symbol");
}

Const::~Const() {}

Ptr Const::eval(const Ptr &a) {return this;}

} // namespaces
