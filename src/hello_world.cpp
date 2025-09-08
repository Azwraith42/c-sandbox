#include "hello_world.h"
#include <algorithm>
#include <cctype>

namespace hello_world {

Result greet(const std::string& name) {
    if (name.empty()) {
        return ErrorType::EMPTY_NAME;
    }
    
    if (std::all_of(name.begin(), name.end(), [](char c) { return std::isspace(c); })) {
        return ErrorType::INVALID_NAME;
    }
    
    return "Hello, " + name + "!";
}

}