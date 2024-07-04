CXX = g++
# Compiler flags including debugging symbols
CXXFLAGS = -std=c++14 -Wall -Wextra -pedantic -g -O3
# Linker flags for profiling (you can keep this if needed)
LDFLAGS = -pg
# Executable name
TARGET = run

# List of source files
SOURCES = main.cpp KaryTree.cpp 

# Object files (automatically generated)
OBJECTS = $(SOURCES:.cpp=.o)

# Main target
all: $(TARGET)

# Linking step
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) -o $(TARGET)

# Compiling step for each source file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the executable using gdb
debug: $(TARGET)
	gdb ./$(TARGET)

# Clean generated files
clean:
	rm -f $(OBJECTS) $(TARGET) gmon.out

.PHONY: all debug clean
