compile:
	g++ -g --std=c++14 $(filter-out unitTests_Iwan.cpp, $(filter-out unitTests_Stephan.cpp, $(filter-out unitTests_Tiaan.cpp, $(filter-out unitTests_Xavier.cpp, $(wildcard *.cpp))))) -o main.o
errorCount:
	g++ --std=c++14 -w main.cpp 2>&1 | grep -c "error:"
run:
	./main.o
leaks:
	leaks -atExit -- ./main.o

CXX = g++
CXXFLAGS = -std=c++17 -Wall
EXECUTABLE = myprogram
VALGRIND = valgrind

SRC_FILES = $(wildcard *.cpp)
OBJ_FILES = $(patsubst %.cpp, %.o, $(SRC_FILES))

# all: $(EXECUTABLE)

# $(EXECUTABLE): $(OBJ_FILES)
# 	$(CXX) $(CXXFLAGS) -o $@ $^

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c -o $@ $<

# run: $(EXECUTABLE)
# 	./$(EXECUTABLE)

# valgrind: $(EXECUTABLE)
# 	$(VALGRIND) --leak-check=full ./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(OBJ_FILES)

# .PHONY: all run valgrind clean
