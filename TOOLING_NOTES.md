# C++ Tooling Improvement Opportunities

This project intentionally starts simple to focus on learning C++ and TDD fundamentals. Below are idiomatic tools and practices to consider as the project grows.

## Build Systems

### Current: Simple Makefile
- ✅ No external dependencies
- ✅ Easy to understand
- ❌ Limited cross-platform support
- ❌ Manual dependency tracking

### Upgrade Path: CMake
```cmake
# Example CMakeLists.txt structure
cmake_minimum_required(VERSION 3.16)
project(hello_world)
set(CMAKE_CXX_STANDARD 17)
```
**Benefits**: Cross-platform, better dependency management, IDE integration

### Advanced: Bazel
**Benefits**: Hermetic builds, excellent for large codebases, remote caching

## Testing Frameworks

### Current: Simple Assertions
- ✅ No dependencies
- ✅ Clear test structure
- ❌ Limited reporting
- ❌ No test fixtures or parameterization

### Upgrade Options:
1. **Google Test (gtest)** - Industry standard, rich assertions
2. **Catch2** - Header-only, BDD-style syntax
3. **doctest** - Fastest compile times, similar to Catch2

## Package Management

### Current: Manual Dependencies
- ✅ Full control
- ❌ No version management
- ❌ Manual integration

### Upgrade Options:
1. **Conan** - Cross-platform, integrates with CMake
2. **vcpkg** - Microsoft-backed, good Windows support  
3. **CPM.cmake** - CMake-native, simple setup

## Code Quality Tools

### Static Analysis
- **clang-tidy** - Comprehensive linting and modernization
- **cppcheck** - Additional static analysis
- **PVS-Studio** - Commercial, very thorough

### Formatting
- **clang-format** - Automatic code formatting
- **include-what-you-use** - Header dependency optimization

### Example .clang-format:
```yaml
BasedOnStyle: Google
IndentWidth: 4
ColumnLimit: 100
```

**Note**: Current project uses selective `using` declarations (e.g., `using std::string;`) instead of `std::` prefixes for cleaner syntax while avoiding namespace pollution.

## CI/CD Integration

### GitLab CI Example:
```yaml
# .gitlab-ci.yml
test:
  image: gcc:latest
  script:
    - make test
build:
  image: gcc:latest  
  script:
    - make all
  artifacts:
    paths:
      - build/
```

## Debugging & Profiling

### Development Tools
- **gdb** - Command-line debugging
- **valgrind** - Memory leak detection
- **AddressSanitizer** - Runtime error detection
- **perf** - Performance profiling

### IDE Integration
- **CLion** - JetBrains C++ IDE
- **VS Code** with C++ extensions
- **Qt Creator** - Cross-platform IDE

## When to Upgrade

1. **Multiple developers** → Add CMake + clang-format
2. **External libraries** → Add package manager (Conan/vcpkg)
3. **Complex testing needs** → Add Google Test
4. **CI/CD pipeline** → Add static analysis tools
5. **Performance concerns** → Add profiling tools

Remember: Only add complexity when it solves a real problem you're experiencing.