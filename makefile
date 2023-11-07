SRC_TEST_EXCLUDE = $(wildcard *test*.cpp *Test*.cpp *main*.cpp)

ifdef INCLUDE_TEST
SRC_TEST_EXCLUDE := $(filter-out $(INCLUDE_TEST),$(SRC_TEST_EXCLUDE))
endif

test_sources := $(filter-out $(SRC_TEST_EXCLUDE), $(wildcard *.cpp))

build:
	make compile INCLUDE_TEST=main.cpp

run:
	./main.o

leaks:
	leaks -atExit -- ./main.o

valgrind:
	valgrind --leak-check=full ./main.o

compile: $(test_sources)
	g++ -g --std=c++14 $(test_sources) -o main.o

test: $(test_sources)
	g++ -g --std=c++14 $(test_sources) -o main_test.o -lgtest -lgmock -lgtest_main -lpthread
	./main_test.o

CXX = g++
CXXFLAGS = -std=c++17 -Wall
EXECUTABLE = myprogram
VALGRIND = valgrind

KITCHEN_DIR = kitchen

SRC_FILES = $(wildcard *.cpp) $(wildcard $(KITCHEN_DIR)/*.cpp)
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
