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

    std::variant<
        types::Pair,
        types::Symbol,
        types::Lazy,
        types::Evaluator,
        types::BaseMacro,
        types::MacroClosure,
        types::CurrentContext,
        types::Vector,
        types::ByteArray,
        types::Value<double>,
        types::Value<long>,
        types::Value<char>
    > v;

public:
    template <class T>
    explicit Ob(T&& t) : v(std::forward<T>(t)) {}

    Ptr car();
    Ptr cdr();

    template <class T>
    T * as() {
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
    T &cast() {
        if (auto * p = as<T>(); !p) {
            throw SemanticError("error cast");
        } else {
            return *p;
        }
    }

    template <typename Visitor>
    decltype(auto) visit(Visitor&& visitor) {
        return std::visit(std::forward<Visitor>(visitor), v);
    }

    template <typename Visitor>
    decltype(auto) visit(Visitor&& visitor) const {
        return std::visit(std::forward<Visitor>(visitor), v);
    }
};

} // namespaces
