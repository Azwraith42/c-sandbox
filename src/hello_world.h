#pragma once

#include <string>
#include <variant>

namespace hello_world {

enum class ErrorType {
    INVALID_NAME,
    EMPTY_NAME
};

using Result = std::variant<std::string, ErrorType>;

Result greet(const std::string& name);

}