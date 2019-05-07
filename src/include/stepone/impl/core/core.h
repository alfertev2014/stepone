#pragma once

#include <ptr.h>

namespace stepone::core {

class Pair final {
private:
    Ptr pcar;
    Ptr pcdr;
public:
    Pair(const Ptr & _pcar, const Ptr & _pcdr)
        : pcar(_pcar), pcdr(_pcdr) {}

    Ptr car();
    Ptr cdr();

    Ptr eval(const Ptr & a);
};


class Atom {};


class Context final {
    Context() = delete;
public:
    static Ptr make(const Ptr & _s, const Ptr & _e, const Ptr & _next);
};


class Lazy final {
private:
    Ptr e;
    Ptr a;

    void ev();
    void evw();

public:
    Lazy(const Ptr & _e, const Ptr & _a)
        : e(_e), a(_a) {}

    Ptr car();
    Ptr cdr();

    Ptr eval(const Ptr &a);
    Ptr apply(const Ptr &p, const Ptr &a);
    Ptr unlazy();
};


class Label final {
    friend class Ob;
private:
    WPtr v;
    const Ptr * pa;

    Label(const WPtr _v, const Ptr * _a)
        : v(_v), pa(_a) {}

    Ptr ptr();

public:
    static Ptr loop(const Ptr & f, const Ptr & e, const Ptr & a);

    Ptr car();
    Ptr cdr();

    Ptr eval(const Ptr &a);
    Ptr apply(const Ptr &p, const Ptr &a);
    Ptr unlazy();
};


class Symbol final : public Atom {
public:
    Ptr eval(const Ptr & a);
};


class Const : public Atom {};

} // namespaces
