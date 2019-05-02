#pragma once

#include "core.h"

namespace stepone::core {

class Macro : public Const {
protected:
    using Const::Const;
public:
    virtual ~Macro();
};

template <>
inline bool Ob::is<Macro>() const {
    return typeFlags.isMacro();
}


class Evaluator final : public Macro {
private:
    Ptr a;
public:
    static const Ptr eempty;

    Evaluator(Ptr _a) : Macro(BaseTypeTag::Evaluator), a(_a) {}
    Ptr getContext() const;
    Ptr apply(const Ptr &p, const Ptr &a);
};

template <>
inline bool Ob::is<Evaluator>() const {
    return typeFlags.typeTag == BaseTypeTag::Evaluator;
}


class BaseMacro : public Macro {
public:
    BaseMacro(): Macro(BaseTypeTag::BaseMacro) {}
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
        : Macro(BaseTypeTag::MacroClosure), sp(_sp), e(_e), a(_a) {}

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
        : Macro(BaseTypeTag::MacroClosure), sp(_sp), e(_e), a(_a) {}

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
        : Macro(BaseTypeTag::CurrentContext), sa(_sa), e(_e), a(_a) {}

    Ptr apply(const Ptr &p, const Ptr &a);
};

template <>
inline bool Ob::is<CurrentContext>() const {
    return typeFlags.typeTag == BaseTypeTag::CurrentContext;
}

} // namespaces
