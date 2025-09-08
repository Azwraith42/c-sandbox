#include "../src/hello_world.h"
#include <iostream>
#include <cassert>
#include <string>

namespace test_hello_world {

class TestRunner {
public:
    static int run_all_tests() {
        int failures = 0;
        
        failures += run_test("should_greet_valid_name", test_should_greet_valid_name);
        failures += run_test("should_return_error_for_empty_name", test_should_return_error_for_empty_name);
        failures += run_test("should_return_error_for_whitespace_only_name", test_should_return_error_for_whitespace_only_name);
        failures += run_test("should_greet_name_with_spaces", test_should_greet_name_with_spaces);
        
        if (failures == 0) {
            std::cout << "All tests passed!" << std::endl;
        } else {
            std::cout << failures << " test(s) failed." << std::endl;
        }
        
        return failures;
    }

private:
    static int run_test(const std::string& test_name, void (*test_func)()) {
        try {
            test_func();
            std::cout << "✓ " << test_name << std::endl;
            return 0;
        } catch (const std::exception& e) {
            std::cout << "✗ " << test_name << " - " << e.what() << std::endl;
            return 1;
        }
    }

    static void test_should_greet_valid_name() {
        auto result = hello_world::greet("World");
        
        assert(std::holds_alternative<std::string>(result));
        assert(std::get<std::string>(result) == "Hello, World!");
    }

    static void test_should_return_error_for_empty_name() {
        auto result = hello_world::greet("");
        
        assert(std::holds_alternative<hello_world::ErrorType>(result));
        assert(std::get<hello_world::ErrorType>(result) == hello_world::ErrorType::EMPTY_NAME);
    }

    static void test_should_return_error_for_whitespace_only_name() {
        auto result = hello_world::greet("   ");
        
        assert(std::holds_alternative<hello_world::ErrorType>(result));
        assert(std::get<hello_world::ErrorType>(result) == hello_world::ErrorType::INVALID_NAME);
    }

    static void test_should_greet_name_with_spaces() {
        auto result = hello_world::greet("John Doe");
        
        assert(std::holds_alternative<std::string>(result));
        assert(std::get<std::string>(result) == "Hello, John Doe!");
    }
};

}

int main() {
    return test_hello_world::TestRunner::run_all_tests();
}