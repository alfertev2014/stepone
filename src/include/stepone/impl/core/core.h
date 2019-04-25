#pragma once

#include "ob.h"

namespace stepone::core {

class Pair : public Ob {
public:
    const Ptr getTypeInfo() const;
private:
    Ptr pcar;
    Ptr pcdr;
public:
    Pair(const Ptr & _pcar, const Ptr & _pcdr)
        : pcar(_pcar), pcdr(_pcdr) {
        typeFlags.obType = TypeFlags::Pair;
    }

    Ptr car();
    Ptr cdr();

    Ptr eval(const Ptr & a);
};

class Atom : public Ob {
public:
    Atom() {
        typeFlags.obType = TypeFlags::Atom;
    }
    virtual ~Atom();
};

class Context {
    Context(){}
public:
    static Ptr make(const Ptr & _s, const Ptr & _e, const Ptr & _next) {
        return new Pair(new Pair(_s, _e), _next);
    }
};

class Lazy : public Ob {
public:
    const Ptr getTypeInfo() const;
private:
    Ptr e;
    Ptr a;

    void ev();
    void evw();

public:
    Lazy(const Ptr & _e, const Ptr & _a)
        : e(_e), a(_a) {
        typeFlags.obType = TypeFlags::Lazy;
    }

    Ptr car();
    Ptr cdr();

    Ptr eval(const Ptr &a);
    Ptr apply(const Ptr &p, const Ptr &a);
    Ptr unlazy();
};

class Label : public Ob {
public:
    const Ptr getTypeInfo() const;
private:
    const Ptr * pa;
    WPtr v;

    Label(const WPtr _v, const Ptr * _a) : v(_v), pa(_a) {
        typeFlags.obType = TypeFlags::Label;
    }

    Ptr ptr();

public:
    static Ptr loop(const Ptr & f, const Ptr & e, const Ptr & a);

    Ptr car();
    Ptr cdr();

    Ptr eval(const Ptr &a);
    Ptr apply(const Ptr &p, const Ptr &a);
    Ptr unlazy();
};


class Symbol : public Atom {
public:
    const Ptr getTypeInfo() const;
public:
    Symbol() : Atom() {
        typeFlags.atomType = TypeFlags::Symbol;
    }
    Ptr eval(const Ptr & a);
};

class Const : public Atom {
public:
    Const() : Atom() {
        typeFlags.atomType = TypeFlags::Const;
    }
    virtual ~Const();
    Ptr eval(const Ptr &a);
};


template<>
Atom *Ob::as<Atom>();

template<>
Lazy *Ob::as<Lazy>();

template<>
Pair *Ob::as<Pair>();

template<>
Label *Ob::as<Label>();

template<>
Symbol *Ob::as<Symbol>();

template<>
Const *Ob::as<Const>();

} // namespaces
