# Simple C++ Makefile for TDD development
# NOTE: For larger projects, consider CMake or Bazel for better dependency management
# and cross-platform compatibility

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g
SRCDIR = src
TESTDIR = test
BUILDDIR = build

# Source and test files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
TEST_SOURCES = $(wildcard $(TESTDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)
TEST_OBJECTS = $(TEST_SOURCES:$(TESTDIR)/%.cpp=$(BUILDDIR)/test_%.o)

# Targets
TARGET = $(BUILDDIR)/hello_world
TEST_TARGET = $(BUILDDIR)/test_runner

.PHONY: all test clean run help

all: $(TARGET)

# Build main application
$(TARGET): $(BUILDDIR) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Build and run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Build test executable
$(TEST_TARGET): $(BUILDDIR) $(TEST_OBJECTS) $(filter-out $(BUILDDIR)/main.o,$(OBJECTS))
	$(CXX) $(CXXFLAGS) $(TEST_OBJECTS) $(filter-out $(BUILDDIR)/main.o,$(OBJECTS)) -o $(TEST_TARGET)

# Compile source files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files
$(BUILDDIR)/test_%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -c $< -o $@

# Create build directory
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Run the application
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -rf $(BUILDDIR)

# Display help
help:
	@echo "Available targets:"
	@echo "  all     - Build the main application"
	@echo "  test    - Build and run tests"
	@echo "  run     - Build and run the application"
	@echo "  clean   - Remove build artifacts"
	@echo "  help    - Show this help message"