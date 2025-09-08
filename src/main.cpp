#include "hello_world.h"
#include <iostream>

int main() {
    auto result = hello_world::greet("World");
    
    if (std::holds_alternative<std::string>(result)) {
        std::cout << std::get<std::string>(result) << std::endl;
        return 0;
    } else {
        std::cerr << "Error occurred while greeting" << std::endl;
        return 1;
    }
}