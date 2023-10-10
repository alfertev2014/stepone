#pragma once

#include <exception>

namespace stepone {

class TypeError : public std::exception {
private:
    const char * message;
public:
    TypeError() noexcept
        : message("Unknown TypeError") {}

    TypeError(const char * message) noexcept
        : message(message) {}

    const char * what() const noexcept override {
        return message;
    }
};

} // namespace
