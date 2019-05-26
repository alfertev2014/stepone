#pragma once

#include "core.h"
#include <functional>

namespace stepone::core {

class Macro : public Const {};


class Evaluator final : public Macro {
private:
    Ptr a;
public:
    static const Ptr eempty;

    Evaluator(Ptr _a) : a(_a) {}
    Ptr getContext() const;
    Ptr apply(const Ptr &p, const Ptr &a);
    Ptr assoc(const Ptr &s) const;
};


using BaseMacroApplyFunction = Ptr(*)(const Ptr &p, const Ptr &a);

class BaseMacro final : public Macro {
private:
    BaseMacroApplyFunction applyFunction;
public:
    BaseMacro(const BaseMacroApplyFunction &applyFunction) : applyFunction(applyFunction) {}

    template <typename Func>
    BaseMacro(const Func &f) : applyFunction([](const Ptr &p, const Ptr &a) { return Func()(p, a); }) {}

    Ptr apply(const Ptr &p, const Ptr &a) {return applyFunction(p, a);}
};


class MacroClosure final : public Macro {
private:
    Ptr sp;
    Ptr e;
    Ptr a;
public:
    MacroClosure(const Ptr & _sp, const Ptr & _e, const Ptr & _a)
        : sp(_sp), e(_e), a(_a) {}

    Ptr apply(const Ptr &p, const Ptr &a);
};


class CurrentContext final : public Macro {
private:
    Ptr sa;
    Ptr e;
    Ptr a;
public:
    CurrentContext(const Ptr & _sa, const Ptr & _e, const Ptr & _a)
        : sa(_sa), e(_e), a(_a) {}

    Ptr apply(const Ptr &p, const Ptr &a);
};

} // namespaces
