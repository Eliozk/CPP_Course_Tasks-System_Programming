CC=g++
CFLAGS=-std=c++17 -Wall -Wextra -g
LDFLAGS=

SRCS=main.cpp  # Only main.cpp here
OBJS=$(SRCS:.cpp=.o)
EXEC=main

all: $(EXEC)

$(EXEC): $(OBJS) KaryTree.tpp  # Add KaryTree.tpp here as a dependency
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

debug: CFLAGS += -DDEBUG
debug: all
#equal for "make run" to run main
tree: all
	./$(EXEC)

.PHONY: all clean debug tree
