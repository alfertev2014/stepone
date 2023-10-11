#pragma once

#include <ptr.h>
#include "types/core.h"
#include "types/macro.h"
#include "types/value.h"
#include "types/bytearray.h"
#include "types/vector.h"
#include "error_exception.h"

#include <variant>

#include "util.h"

namespace stepone {

class Ob final {
    friend class Ptr;

    const std::variant<
        types::Pair,
        types::Symbol,
        types::Evaluator,
        types::BaseMacro,
        types::MacroClosure,
        types::Vector,
        types::ByteArray,
        types::Value<double>,
        types::Value<long>,
        types::Value<char>
    > v;

public:
    template <class T>
    explicit Ob(T&& t) : v(std::forward<T>(t)) {}

    Ptr car() const;
    Ptr cdr() const;

    template <class T>
    const T * as() const {
        return std::get_if<T>(&v);
    }

    template <class T>
    bool is() const {
        return visit(overloaded {
            [](const T &) { return true; },
            [](const types::Any&) { return false; }
        });
    }

    template <class T>
    const T &cast() const {
        if (const auto * p = as<T>(); !p) {
            throw TypeError("error cast");
        } else {
            return *p;
        }
    }

    template <typename Visitor>
    decltype(auto) visit(Visitor&& visitor) const {
        return std::visit(std::forward<Visitor>(visitor), v);
    }
};

} // namespaces
