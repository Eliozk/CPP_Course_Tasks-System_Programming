# Specify the C++ compiler to be used
CXX = clang++

# Set compiler flags, including C++ version and warnings
CXXFLAGS = -std=c++11 -Werror -Wsign-conversion

# Define the target executable names
DEMO_TARGET = bin/demo
# to bring back later
# TEST_TARGET = bin/test

# Define the source files
SOURCES = Algorithms.cpp Demo.cpp Graph.cpp 
#  TestCounter.cpp

# Generate object file names from source files
OBJECTS = $(addprefix bin/, $(SOURCES:.cpp=.o))

# Default target: build both demo and test executables
all: $(DEMO_TARGET) 
#  to put back in all later
# $(TEST_TARGET)

# Rule to build the demo executable
$(DEMO_TARGET): $(OBJECTS) | bin
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to build the test executable
# $(TEST_TARGET): $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to compile each source file into an object file
bin/%.o: %.cpp | bin
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target to run the demo executable
run:
	./$(DEMO_TARGET)

# Create the bin directory if it doesn't exist
bin:
	mkdir -p bin

# Clean up generated files
clean:
	rm -f bin/*.o $(DEMO_TARGET)

# Phony targets to avoid conflicts with file names
.PHONY: all run clean
