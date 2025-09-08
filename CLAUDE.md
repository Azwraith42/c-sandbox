# C++ TDD Learning Project

## Build Commands

```bash
# Build the main application
make all

# Run tests (builds and executes test suite)
make test

# Build and run the application
make run

# Clean build artifacts
make clean

# Show available targets
make help
```

## Project Standards

### Code Style
- Use C++17 standard
- Favor composition over inheritance
- Use functional error handling with `std::variant<T, ErrorType>`
- Keep functions small and focused
- Use structured enums for error types, not string literals
- Dependency injection for testability

### Testing Standards
- All tests must be self-contained and deterministic
- Test through public interfaces, stub only edge dependencies
- Use simple assertion-based testing (no external frameworks initially)
- Ideal test runtime: <10ms, warning: >20ms, failure: >100ms
- No file system, network, DB, or global resources in tests
- Test naming: `should_do_x_when_y` pattern

### Error Handling
- Use `std::variant<SuccessType, ErrorType>` pattern
- Structured enums for error categories
- Clear, actionable error messages
- No exceptions for expected error cases

### Project Structure
```
src/          # Application source code
test/         # Unit tests
build/        # Build artifacts (generated)
Makefile      # Simple build configuration
```

## Development Workflow
1. Write failing test first
2. Implement minimal code to pass
3. Refactor while keeping tests green
4. Run `make test` after each change