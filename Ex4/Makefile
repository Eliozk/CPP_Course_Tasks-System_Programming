CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = main
TEST_TARGET = test_cases

all: $(TARGET) $(TEST_TARGET)

$(TARGET): main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

main.o: main.cpp Tree.hpp Tree.tpp
	$(CXX) $(CXXFLAGS) -c main.cpp

$(TEST_TARGET): test_cases.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

test_cases.o: test_cases.cpp Tree.hpp Tree.tpp 
	$(CXX) $(CXXFLAGS) -c test_cases.cpp

tree:
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET) *.o
