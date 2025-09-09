#pragma once

#include <string>
#include <variant>

using std::string;
using std::variant;

namespace hello_world {

enum class ErrorType {
    INVALID_NAME,
    EMPTY_NAME
};

using Result = variant<string, ErrorType>;

Result greet(const string& name);

}