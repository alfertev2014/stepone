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
        typeFlags.typeTag = BaseTypeTag::Pair;
    }

    Ptr car();
    Ptr cdr();

    Ptr eval(const Ptr & a);
};

template <>
inline bool Ob::is<Pair>() const {
    return typeFlags.typeTag == BaseTypeTag::Pair;
}


class Atom : public Ob {
public:
    virtual ~Atom();
};

template <>
inline bool Ob::is<Atom>() const {
    return typeFlags.typeTag != BaseTypeTag::Pair;
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
        typeFlags.typeTag = BaseTypeTag::Lazy;
    }

    Ptr car();
    Ptr cdr();

    Ptr eval(const Ptr &a);
    Ptr apply(const Ptr &p, const Ptr &a);
    Ptr unlazy();
};

template <>
inline bool Ob::is<Lazy>() const {
    return typeFlags.typeTag == BaseTypeTag::Lazy;
}


class Label : public Ob {
private:
    const Ptr * pa;
    WPtr v;

    Label(const WPtr _v, const Ptr * _a) : v(_v), pa(_a) {
        typeFlags.typeTag = BaseTypeTag::Label;
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
    return typeFlags.typeTag == BaseTypeTag::Label;
}


class Symbol : public Atom {
public:
    Symbol() : Atom() {
        typeFlags.typeTag = BaseTypeTag::Symbol;
    }
    Ptr eval(const Ptr & a);
};

template <>
inline bool Ob::is<Symbol>() const {
    return typeFlags.typeTag == BaseTypeTag::Symbol;
}


class Const : public Atom {
public:
    virtual ~Const();
    Ptr eval(const Ptr &a);
};

template <>
inline bool Ob::is<Const>() const {
    return static_cast<int>(typeFlags.typeTag) > static_cast<int>(BaseTypeTag::Label);
}

} // namespaces
