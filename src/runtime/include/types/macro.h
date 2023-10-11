#pragma once

#include "core.h"

namespace stepone::types {

// TODO: De we need separate type for Evaluator? May be Context will be enough?
// TODO: It could be good idea to pass const Ptr &context arguments as of special Context type.
// So contexts may have separate memory allocator.
class Evaluator final : public Macro {
public:
    const Ptr context;

    Evaluator(Ptr context) : context(context) {}

    Ptr apply(const Ptr &argument, const Ptr &context) const;
    Ptr assoc(const Ptr &symbol) const;
    Ptr push(const Ptr &symbol, const Ptr &value) const;

    static Ptr eempty();
};


using BaseMacroApplyFunction = Ptr(*)(const Ptr &argument, const Ptr &context);

class BaseMacro final : public Macro {
private:
    const BaseMacroApplyFunction applyFunction;
public:
    BaseMacro(const BaseMacroApplyFunction &applyFunction) : applyFunction(applyFunction) {}

    template <typename Func>
    BaseMacro(const Func &) : applyFunction([](const Ptr &argument, const Ptr &context) { return Func()(argument, context); }) {}

    Ptr apply(const Ptr &argument, const Ptr &context) const {return applyFunction(argument, context);}
};

// TODO: Do we need both MacroClosure and CurrentContext to write macros.
class MacroClosure final : public Macro {
private:
    const Ptr argumentSymbol;
    const Ptr callingContextSymbol;
    const Ptr bodyExpression;
    const Ptr creationContext;
public:
    MacroClosure(const Ptr &argumentSymbol, const Ptr &callingContextSymbol, const Ptr &expression, const Ptr &context)
        : argumentSymbol(argumentSymbol),
          callingContextSymbol(callingContextSymbol),
          bodyExpression(expression),
          creationContext(context) {}

    Ptr apply(const Ptr &argument, const Ptr &context) const;
};

} // namespaces
