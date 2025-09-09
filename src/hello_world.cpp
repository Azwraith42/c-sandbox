#include "hello_world.h"
#include <algorithm>
#include <cctype>

using std::all_of;
using std::isspace;

namespace hello_world {

Result greet(const string& name) {
    if (name.empty()) {
        return ErrorType::EMPTY_NAME;
    }
    
    if (all_of(name.begin(), name.end(), [](char c) { return isspace(c); })) {
        return ErrorType::INVALID_NAME;
    }
    
    return "Hello, " + name + "!";
}

}