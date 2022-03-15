#pragma once

#include <ptr.h>
#include "core.h"
#include "macro.h"
#include "value.h"
#include "bytearray.h"
#include "vector.h"
#include "error_exception.h"

#include <variant>

namespace stepone::core {

// helper type for the visitor #4
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
// explicit deduction guide (not needed as of C++20)
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

class Ob final {
    friend class Ptr;

    std::variant<
        Pair,
        Symbol,
        Lazy,
        Label,
        Evaluator,
        BaseMacro,
        MacroClosure,
        CurrentContext,
        Vector,
        ByteArray,
        Value<int>,
        Value<float>,
        Value<long long>,
        Value<char>
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
            [](const auto&) { return false; }
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
