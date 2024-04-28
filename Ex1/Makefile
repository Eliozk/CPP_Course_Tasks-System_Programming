# Specify the C++ compiler to be used
CXX = clang++

# Set compiler flags, including C++ version and warnings
CXXFLAGS = -std=c++11 -Werror -Wsign-conversion

# Define the target executable names
DEMO_TARGET = demo
TEST_TARGET = test

# Define the source files
SOURCES = Algorithms.cpp Demo.cpp Graph.cpp Test.cpp TestCounter.cpp

# Generate object file names from source files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target: build both demo and test executables
all: $(DEMO_TARGET) $(TEST_TARGET)

# Rule to build the demo executable
$(DEMO_TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to build the test executable
$(TEST_TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^

# Clean up generated files
clean:
	rm -f *.o  $(DEMO_TARGET) $(TEST_TARGET)
