#pragma once

#include "core.h"

namespace stepone::types {

// TODO: De we need separate type for Evaluator? May be Context will be enough?
// TODO: It could be good idea to pass const Ptr &context arguments as of special Context type.
// So contexts may have separate memory allocator.
class Evaluator final : public Macro {
private:
    Ptr context;
public:
    static Ptr eempty();

    Evaluator(Ptr context) : context(context) {}
    Ptr getContext() const;
    Ptr apply(const Ptr &argument, const Ptr &context);
    Ptr assoc(const Ptr &symbol) const;
    Ptr push(const Ptr &symbol, const Ptr &value) const;
};


using BaseMacroApplyFunction = Ptr(*)(const Ptr &argument, const Ptr &context);

class BaseMacro final : public Macro {
private:
    BaseMacroApplyFunction applyFunction;
public:
    BaseMacro(const BaseMacroApplyFunction &applyFunction) : applyFunction(applyFunction) {}

    template <typename Func>
    BaseMacro(const Func &) : applyFunction([](const Ptr &argument, const Ptr &context) { return Func()(argument, context); }) {}

    Ptr apply(const Ptr &argument, const Ptr &context) {return applyFunction(argument, context);}
};

// TODO: Do we need both MacroClosure and CurrentContext to write macros.
class MacroClosure final : public Macro {
private:
    Ptr symbol;
    Ptr expression;
    Ptr context;
public:
    MacroClosure(const Ptr & symbol, const Ptr & expression, const Ptr & context)
        : symbol(symbol), expression(expression), context(context) {}

    Ptr apply(const Ptr &argument, const Ptr &context);
};


class CurrentContext final : public Macro {
private:
    Ptr symbol;
    Ptr expression;
    Ptr context;
public:
    CurrentContext(const Ptr &symbol, const Ptr & expression, const Ptr & context)
        : symbol(symbol), expression(expression), context(context) {}

    Ptr apply(const Ptr &argument, const Ptr &context);
};

} // namespaces
