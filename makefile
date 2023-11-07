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

LINT_SRC_EXCLUDE = $(wildcard *test*.cpp *Test*.cpp *main*.cpp)
LINT_FILES := $(filter-out $(LINT_SRC_EXCLUDE), $(wildcard *.cpp) $(wildcard $(KITCHEN_DIR)/*.cpp))
lint:
	clang-tidy $(LINT_FILES) -- -std=c++17

clean:
	rm -f $(wildcard *.o)


