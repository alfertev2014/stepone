#pragma once

#include "core.h"

namespace stepone::core {

class Macro : public Const {
public:
    virtual ~Macro();
};

template <>
inline bool Ob::is<Macro>() const {
    return typeFlags.isMacro();
}


class Evaluator : public Macro {
private:
    Ptr a;
public:
    static const Ptr eempty;

    Evaluator(Ptr _a) : Macro(), a(_a) {
        typeFlags.typeTag = BaseTypeTag::Evaluator;
    }
    Ptr getContext() const;
    Ptr apply(const Ptr &p, const Ptr &a);
};

template <>
inline bool Ob::is<Evaluator>() const {
    return typeFlags.typeTag == BaseTypeTag::Evaluator;
}


class BaseMacro : public Macro {
public:
    BaseMacro(): Macro() {
        typeFlags.typeTag = BaseTypeTag::BaseMacro;
    }
    virtual ~BaseMacro();
};

template <>
inline bool Ob::is<BaseMacro>() const {
    return typeFlags.typeTag == BaseTypeTag::BaseMacro;
}


/// TODO: remove it
class Closure : public Macro {
private:
    Ptr sp;
    Ptr e;
    Ptr a;
public:
    Closure(const Ptr & _sp, const Ptr & _e, const Ptr & _a)
        : Macro(), sp(_sp), e(_e), a(_a) {
        typeFlags.typeTag = BaseTypeTag::MacroClosure;
    }

    Ptr apply(const Ptr &p, const Ptr &a);
};

template <>
inline bool Ob::is<Closure>() const {
    return typeFlags.typeTag == BaseTypeTag::MacroClosure;
}


class MacroClosure : public Macro {
private:
    Ptr sp;
    Ptr e;
    Ptr a;
public:
    MacroClosure(const Ptr & _sp, const Ptr & _e, const Ptr & _a)
        : Macro(), sp(_sp), e(_e), a(_a) {
        typeFlags.typeTag = BaseTypeTag::MacroClosure;
    }

    Ptr apply(const Ptr &p, const Ptr &a);
};

template <>
inline bool Ob::is<MacroClosure>() const {
    return typeFlags.typeTag == BaseTypeTag::MacroClosure;
}


class CurrentContext : public Macro {
private:
    Ptr sa;
    Ptr e;
    Ptr a;
public:
    CurrentContext(const Ptr & _sa, const Ptr & _e, const Ptr & _a)
        : Macro(), sa(_sa), e(_e), a(_a) {
        typeFlags.typeTag = BaseTypeTag::CurrentContext;
    }

    Ptr apply(const Ptr &p, const Ptr &a);
};

template <>
inline bool Ob::is<CurrentContext>() const {
    return typeFlags.typeTag == BaseTypeTag::CurrentContext;
}

} // namespaces
