#pragma once

#include "type_flags.h"

#include "core.h"
#include "macro.h"
#include "value.h"
#include "bytearray.h"
#include "vector.h"

namespace stepone::core {

template <BaseTypeTag TAG>
struct TypeTagValue {
    static constexpr BaseTypeTag typeTagValue {TAG};
};

template <class T>
struct TypeTagOf;

template <>
struct TypeTagOf<Pair> : TypeTagValue<BaseTypeTag::Pair> {};

template <>
struct TypeTagOf<Lazy> : TypeTagValue<BaseTypeTag::Lazy> {};

template <>
struct TypeTagOf<Label> : TypeTagValue<BaseTypeTag::Label> {};

template <>
struct TypeTagOf<Symbol> : TypeTagValue<BaseTypeTag::Symbol> {};

template <>
struct TypeTagOf<Evaluator> : TypeTagValue<BaseTypeTag::Evaluator> {};

template <>
struct TypeTagOf<BaseMacro> : TypeTagValue<BaseTypeTag::BaseMacro> {};

template <>
struct TypeTagOf<MacroClosure> : TypeTagValue<BaseTypeTag::MacroClosure> {};

template <>
struct TypeTagOf<CurrentContext> : TypeTagValue<BaseTypeTag::CurrentContext> {};

template <>
struct TypeTagOf<BaseValue> : TypeTagValue<BaseTypeTag::BaseValue> {};

template <>
struct TypeTagOf<ByteArray> : TypeTagValue<BaseTypeTag::ByteArray> {};

template <>
struct TypeTagOf<Vector> : TypeTagValue<BaseTypeTag::Vector> {};

template <>
struct TypeTagOf<Value<int>> : TypeTagValue<BaseTypeTag::Int> {};

template <>
struct TypeTagOf<Value<float>> : TypeTagValue<BaseTypeTag::Float> {};

template <>
struct TypeTagOf<Value<char>> : TypeTagValue<BaseTypeTag::Char> {};

template <>
struct TypeTagOf<Value<long long>> : TypeTagValue<BaseTypeTag::Long> {};

} // namespaces
