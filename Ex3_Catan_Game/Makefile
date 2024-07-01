CC = g++
Flags = -Wall -g -Wextra
INCLUDES = -I./hppFiles
SRCS = src/demoMain.cpp src/Tile.cpp src/Settlement.cpp src/Player.cpp \
       src/Board.cpp src/Card.cpp src/Vertex.cpp src/Edge.cpp \
       src/Catan.cpp src/GamePlay.cpp
BUILD_DIR = build
OBJS = $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
EXEC = demoMain
TEST_EXEC = testCatan

# Default target
all: $(EXEC)

# Executable target
$(EXEC): $(OBJS)
	$(CC)  $(INCLUDES) -o $@ $^
#$(Flags)
# Object files compilation
$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CC)  $(INCLUDES) -c $< -o $@
#$(Flags)
# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Run the main executable
run: $(EXEC)
	./$(EXEC)

# Target for running the Catan game
catan:
	./$(EXEC)

# Debugging target with gdb
debug: $(EXEC)
	gdb ./$(EXEC)

# Clean up target to remove executable and object files
clean:
	rm -rf $(EXEC) $(BUILD_DIR) $(TEST_EXEC)

# Test target using doctest
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Build and compile the test executable
$(TEST_EXEC): src/testCatan.cpp $(filter-out $(BUILD_DIR)/demoMain.o, $(OBJS))
	$(CC)  $(INCLUDES) $^ -o $@
#$(Flags)
.PHONY: all run catan debug clean test
