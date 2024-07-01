CC = g++
Flags = -Wall -g -Wextra 
#-DDEBUG
INCLUDES = -I./hppFiles
SRCS = src/demoMain.cpp src/Tile.cpp src/Settlement.cpp src/Player.cpp src/Board.cpp src/Card.cpp src/Vertex.cpp src/Edge.cpp src/Catan.cpp src/GamePlay.cpp
#src/Game.cpp
# src/InitGame.cpp
# what folder to put object files.
BUILD_DIR = build
OBJS = $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
EXEC = demoMain

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(Flags) $(INCLUDES) -o $@ $^

$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CC) $(Flags) $(INCLUDES) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run: $(EXEC)
	./$(EXEC)

catan:
	./$(EXEC)

debug: $(EXEC)
	gdb ./$(EXEC)
#gdb ./Ex3_Catan_Game /mnt/wslg/dumps/core.demoMain.188698 -replace only the core
#to find dumped core  "ls -l /mnt/wslg/dumps/"
clean:
	rm -rf $(EXEC) $(BUILD_DIR)

.PHONY: all run debug clean
