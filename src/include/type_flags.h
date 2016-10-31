#pragma once

struct TypeFlags {
    enum ObType {
        Pair = 0,
        Atom,
        Lazy,
        Label
    };

    enum AtomType {
        Symbol = 0,
        Const
    };

    enum ConstType {
        Macro = 0,
        ValueBase
    };

    enum MacroType {
        Evaluator = 0,
        BaseMacro,
        MacroClosure,
        CurrentContext
    };

    enum ValueType {
        ByteArray = 0,
        Vector,
        IOStream,
        Other
    };

    int obType : 2;
    int atomType: 1;
    int constType: 1;
    int macroValueType: 2;

    TypeFlags() :
        obType(0),
        atomType(0),
        constType(0),
        macroValueType(0)
    {}
};

