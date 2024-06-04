# ID - 208762765
# GMAIL - kolanielioz@gmail.com

# Compiler and flags
CXX = clang++                      # Define the C++ compiler
CXXFLAGS = -std=c++11              # Define the C++ standard and additional compiler flags

# Source and object files
SOURCES = Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp Demo.cpp  # List of source files
OBJECTS = $(patsubst %.cpp, bin/%.o, $(SOURCES))                      # Convert source files to object files
TEST_OBJECTS = bin/TestCounter.o bin/Test.o                           # Test object files
MAIN_OBJECTS = $(filter-out $(TEST_OBJECTS), $(OBJECTS))               # Main object files

# Default target: just build the object files
all: $(OBJECTS)

# Run the main executable
run: Demo
	./Demo                         # Run the main executable

# Build the main executable
Demo: bin/Demo.o $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o Demo  # Link object files to create the main executable

# Build the test executable
test: $(TEST_OBJECTS) $(filter-out bin/Demo.o,$(OBJECTS))
	$(CXX) $(CXXFLAGS) $^ -o test  # Link object files to create the test executable

# Run the test executable
runtest: test
	./test                         # Run the test executable

# Compile source files to object files and place them in the bin directory
bin/%.o: %.cpp
	@mkdir -p bin                  # Create the bin directory if it doesn't exist
	$(CXX) $(CXXFLAGS) -c $< -o $@  # Compile each source file to an object file

# Clean the build artifacts
clean:
	rm -f bin/*.o Demo test
