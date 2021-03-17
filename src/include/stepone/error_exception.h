#pragma once

#include <exception>

namespace stepone {

class SemanticError : public std::exception
{
    const char * message;
public:
    SemanticError() noexcept
        : message("Unknown SemanticError") {}
    
    SemanticError(const char * message) noexcept
        : message(message) {}
    
    const char * what() const noexcept override {
        return message;
    }
};

} // namespace
