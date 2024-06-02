# ID - 208762765
# GMAIL - kolanielioz@gmail.com

# Compiler and flags
CXX=clang++                       # Define the C++ compiler
CXXFLAGS=-std=c++11               # Define the C++ standard and additional compiler flags
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99  # Define valgrind flags for memory checking

# Source and object files
SOURCES=Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp main.cpp  # List of source files
OBJECTS=$(patsubst %.cpp, bin/%.o, $(SOURCES))                      # Convert source files to object files
TEST_OBJECTS=$(filter bin/TestCounter.o bin/Test.o,$(OBJECTS))      # Filter out test object files
MAIN_OBJECTS=$(filter-out bin/TestCounter.o bin/Test.o bin/main.o,$(OBJECTS))  # Filter out non-main object files

# Run the main executable
run: main
	./$^                          # Run the main executable

# Build the main executable
main: bin/main.o $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o main # Link object files to create the main executable

# Build the test executable
test: $(TEST_OBJECTS) $(filter-out bin/main.o,$(OBJECTS))
	$(CXX) $(CXXFLAGS) $^ -o test # Link object files to create the test executable

# Run the test executable
runtest: test
	./test                        # Run the test executable

# Run clang-tidy for static analysis
tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --  # Run clang-tidy on source files

# Run valgrind for memory checking
valgrind: main test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main 2>&1 | { egrep "lost| at " || true; }  # Run valgrind on the main executable
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }  # Run valgrind on the test executable

# Compile source files to object files and place them in the bin directory
bin/%.o: %.cpp
	@mkdir -p bin                 # Create the bin directory if it doesn't exist
	$(CXX) $(CXXFLAGS) --compile $< -o $@  # Compile each source file to an object file

# Clean the build artifacts
clean:
	rm -f bin/*.o main test       # Remove object files and executables
