CXX = g++
CXXFLAGS = -std=c++17 -Wall
EXECUTABLE = myprogram
VALGRIND = valgrind

SRC_FILES = $(wildcard *.cpp)
OBJ_FILES = $(patsubst %.cpp, %.o, $(SRC_FILES))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: $(EXECUTABLE)
	./$(EXECUTABLE)

valgrind: $(EXECUTABLE)
	$(VALGRIND) --leak-check=full ./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(OBJ_FILES)

.PHONY: all run valgrind clean
