#pragma once

namespace stepone::core {

enum class BaseTypeTag : int {
    Pair,
    Symbol,
    Lazy,
    Label,

    BaseMacro,
    Evaluator,
    MacroClosure,
    CurrentContext,

    BaseValue = 0b1000,
    ByteArray = 0b1001,
    Vector = 0b1010,

    Int,
    Float,
    Char,
    Long,

    LastValue = Long
};

struct TypeFlags {
    BaseTypeTag typeTag {};

    TypeFlags() = default;
    TypeFlags(BaseTypeTag typeTag)
        : typeTag(typeTag) {}

    bool isMacro() const {
        return typeTag >= BaseTypeTag::BaseMacro && typeTag <= BaseTypeTag::CurrentContext;
    }

    bool isValue() const {
        return typeTag >= BaseTypeTag::BaseValue && typeTag <= BaseTypeTag::LastValue;
    }
};

} // namespaces
