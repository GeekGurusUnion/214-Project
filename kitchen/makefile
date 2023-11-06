CXX = g++
CXXFLAGS = -std=c++17 -Wall
EXECUTABLE = myprogram

SRC_FILES = $(wildcard *.cpp)
OBJ_FILES = $(patsubst %.cpp, %.o, $(SRC_FILES))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(OBJ_FILES)

.PHONY: all run clean

.PHONY: valgrind
valgrind: $(EXECUTABLE)
	@valgrind --leak-check=full ./$(EXECUTABLE)
