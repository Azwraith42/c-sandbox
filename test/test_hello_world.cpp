#include "../src/hello_world.h"
#include <iostream>
#include <cassert>
#include <string>

using std::cout;
using std::endl;
using std::exception;
using std::holds_alternative;
using std::get;

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
            cout << "All tests passed!" << endl;
        } else {
            cout << failures << " test(s) failed." << endl;
        }
        
        return failures;
    }

private:
    static int run_test(const string& test_name, void (*test_func)()) {
        try {
            test_func();
            cout << "✓ " << test_name << endl;
            return 0;
        } catch (const exception& e) {
            cout << "✗ " << test_name << " - " << e.what() << endl;
            return 1;
        }
    }

    static void test_should_greet_valid_name() {
        hello_world::Result result = hello_world::greet("World");
        
        assert(holds_alternative<string>(result));
        assert(get<string>(result) == "Hello, World!");
    }

    static void test_should_return_error_for_empty_name() {
        hello_world::Result result = hello_world::greet("");
        
        assert(holds_alternative<hello_world::ErrorType>(result));
        assert(get<hello_world::ErrorType>(result) == hello_world::ErrorType::EMPTY_NAME);
    }

    static void test_should_return_error_for_whitespace_only_name() {
        hello_world::Result result = hello_world::greet("   ");
        
        assert(holds_alternative<hello_world::ErrorType>(result));
        assert(get<hello_world::ErrorType>(result) == hello_world::ErrorType::INVALID_NAME);
    }

    static void test_should_greet_name_with_spaces() {
        hello_world::Result result = hello_world::greet("John Doe");
        
        assert(holds_alternative<string>(result));
        assert(get<string>(result) == "Hello, John Doe!");
    }
};

}

int main() {
    return test_hello_world::TestRunner::run_all_tests();
}