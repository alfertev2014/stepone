#pragma once

namespace stepone::core {

enum class BaseTypeTag : int {
    Pair = 0,
    Symbol = 0b01,
    Lazy = 0b10,
    Label = 0b11,

    BaseMacro = 0b0100,
    Evaluator = 0b0101,
    MacroClosure = 0b0110,
    CurrentContext = 0b0111,

    BaseValue = 0b1000,
    ByteArray = 0b1001,
    Vector = 0b1010,
    Other = 0b1011,
};

struct TypeFlags {
    BaseTypeTag typeTag {};

    TypeFlags() = default;
    TypeFlags(BaseTypeTag typeTag)
        : typeTag(typeTag) {}

    bool isMacro() const {
        return (static_cast<int>(typeTag) & 0b1100) == 0b0100;
    }

    bool isValue() const {
        return (static_cast<int>(typeTag) & 0b1100) == 0b1000;
    }
};

} // namespaces
