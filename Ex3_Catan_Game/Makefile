CC = g++
Flags = -Wall -g -Wextra -DDEBUG

all: demoMain

demoMain: $(OBJS)
	$(CC) $(Flags) -o demoMain src/demoMain.cpp src/Tile.cpp src/Settlement.cpp src/Player.cpp src/Board.cpp -I./hppFiles

run: demoMain
	./demoMain

debug: demoMain
	ulimit -c unlimited && ddd ./demoMain &

clean:
	rm -f demoMain
