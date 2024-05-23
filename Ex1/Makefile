# ID - 208762765
# GMAIL - kolanielioz@gmail.com

CXX=clang++
CXXFLAGS=-std=c++11
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99

SOURCES=Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp main.cpp
OBJECTS=$(patsubst %.cpp, bin/%.o, $(SOURCES))
TEST_OBJECTS=$(filter bin/TestCounter.o bin/Test.o,$(OBJECTS))
MAIN_OBJECTS=$(filter-out bin/TestCounter.o bin/Test.o bin/main.o,$(OBJECTS))

run: main
	./$^

main: bin/main.o $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o main

test: $(TEST_OBJECTS) $(filter-out bin/main.o,$(OBJECTS))
	$(CXX) $(CXXFLAGS) $^ -o test

runtest: test
	./test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: main test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

bin/%.o: %.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f bin/*.o main test
