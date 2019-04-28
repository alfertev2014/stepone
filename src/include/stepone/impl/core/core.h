#pragma once

#include "ob.h"

namespace stepone::core {

class Pair : public Ob {
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

template <>
inline bool Ob::is<Pair>() const {
    return typeFlags.obType == TypeFlags::Pair;
}


class Atom : public Ob {
public:
    Atom() {
        typeFlags.obType = TypeFlags::Atom;
    }
    virtual ~Atom();
};

template <>
inline bool Ob::is<Atom>() const {
    return typeFlags.obType == TypeFlags::Atom;
}


class Context {
    Context(){}
public:
    static Ptr make(const Ptr & _s, const Ptr & _e, const Ptr & _next) {
        return new Pair(new Pair(_s, _e), _next);
    }
};

class Lazy : public Ob {
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

template <>
inline bool Ob::is<Lazy>() const {
    return typeFlags.obType == TypeFlags::Lazy;
}


class Label : public Ob {
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

template <>
inline bool Ob::is<Label>() const {
    return typeFlags.obType == TypeFlags::Label;
}


class Symbol : public Atom {
public:
    Symbol() : Atom() {
        typeFlags.atomType = TypeFlags::Symbol;
    }
    Ptr eval(const Ptr & a);
};

template <>
inline bool Ob::is<Symbol>() const {
    return typeFlags.obType == TypeFlags::Atom && typeFlags.atomType == TypeFlags::Symbol;
}


class Const : public Atom {
public:
    Const() : Atom() {
        typeFlags.atomType = TypeFlags::Const;
    }
    virtual ~Const();
    Ptr eval(const Ptr &a);
};

template <>
inline bool Ob::is<Const>() const {
    return typeFlags.obType == TypeFlags::Atom && typeFlags.atomType == TypeFlags::Const;
}

} // namespaces
