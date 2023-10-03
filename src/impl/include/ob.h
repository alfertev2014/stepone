#pragma once

#include <ptr.h>
#include "core/core.h"
#include "core/macro.h"
#include "core/value.h"
#include "core/bytearray.h"
#include "core/vector.h"
#include "error_exception.h"

#include <variant>

#include "util.h"

namespace stepone {

class Ob final {
    friend class Ptr;

    std::variant<
        core::Pair,
        core::Symbol,
        core::Lazy,
        core::Label,
        core::Evaluator,
        core::BaseMacro,
        core::MacroClosure,
        core::CurrentContext,
        core::Vector,
        core::ByteArray,
        core::Value<int>,
        core::Value<double>,
        core::Value<long long>,
        core::Value<char>
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
            [](const core::Any&) { return false; }
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
