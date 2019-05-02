#pragma once

#include "ob.h"

namespace stepone::core {

class Pair final : public Ob {
private:
    Ptr pcar;
    Ptr pcdr;
public:
    Pair(const Ptr & _pcar, const Ptr & _pcdr)
        : Ob(BaseTypeTag::Pair), pcar(_pcar), pcdr(_pcdr) {}

    Ptr car();
    Ptr cdr();

    Ptr eval(const Ptr & a);
};

template <>
inline bool Ob::is<Pair>() const {
    return typeFlags.typeTag == BaseTypeTag::Pair;
}


class Atom : public Ob {
protected:
    using Ob::Ob;
public:
    virtual ~Atom();
};

template <>
inline bool Ob::is<Atom>() const {
    return typeFlags.typeTag != BaseTypeTag::Pair;
}


class Context final {
    Context() = delete;
public:
    static Ptr make(const Ptr & _s, const Ptr & _e, const Ptr & _next) {
        return new Pair(new Pair(_s, _e), _next);
    }
};

class Lazy final : public Ob {
private:
    Ptr e;
    Ptr a;

    void ev();
    void evw();

public:
    Lazy(const Ptr & _e, const Ptr & _a)
        : Ob(BaseTypeTag::Lazy), e(_e), a(_a) {}

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


class Label final : public Ob {
private:
    WPtr v;
    const Ptr * pa;

    Label(const WPtr _v, const Ptr * _a)
        : Ob(BaseTypeTag::Label), v(_v), pa(_a) {}

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


class Symbol final : public Atom {
public:
    Symbol() : Atom(BaseTypeTag::Symbol) {}
    Ptr eval(const Ptr & a);
};

template <>
inline bool Ob::is<Symbol>() const {
    return typeFlags.typeTag == BaseTypeTag::Symbol;
}


class Const : public Atom {
protected:
    using Atom::Atom;
public:
    virtual ~Const();
    Ptr eval(const Ptr &a);
};

template <>
inline bool Ob::is<Const>() const {
    return static_cast<int>(typeFlags.typeTag) > static_cast<int>(BaseTypeTag::Label);
}

} // namespaces
