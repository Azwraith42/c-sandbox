#include "hello_world.h"
#include <iostream>

using std::holds_alternative;
using std::get;
using std::cout;
using std::cerr;
using std::endl;

int main() {
    hello_world::Result result = hello_world::greet("World");
    
    if (holds_alternative<string>(result)) {
        cout << get<string>(result) << endl;
        return 0;
    } else {
        cerr << "Error occurred while greeting" << endl;
        return 1;
    }
}