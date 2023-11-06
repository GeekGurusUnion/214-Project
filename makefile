compile:
	g++ -g --std=c++14 $(filter-out test_main.cpp, $(filter-out unitTest_Facade.cpp, $(filter-out unitTests_Iwan.cpp, $(filter-out unitTests_Stephan.cpp, $(filter-out unitTests_Tiaan.cpp, $(filter-out unitTests_Xavier.cpp, $(wildcard *.cpp))))))) -o main.o
errorCount:
	g++ --std=c++14 -w main.cpp 2>&1 | grep -c "error:"
run:
	./main.o
leaks:
	leaks -atExit -- ./main.o

test: 
	g++ -g --std=c++14 $(filter-out main.cpp, $(filter-out unitTests_Tiaan.cpp, $(filter-out unitTests_Stephan.cpp, $(filter-out unitTests_Iwan.cpp, $(filter-out unitTests_Xavier.cpp, $(wildcard *.cpp)))))) -o main_testFacade.o -lgtest -lgmock -lgtest_main -lpthread
	./main_testFacade.o

testIwan:
	g++ -g --std=c++14 $(filter-out unitTest_Facade.cpp, $(filter-out main.cpp, $(filter-out unitTests_Stephan.cpp, $(filter-out unitTests_Tiaan.cpp, $(filter-out unitTests_Xavier.cpp, $(wildcard *.cpp)))))) -o main_testIwan.o -lgtest -lgmock -lgtest_main -lpthread
	./main_testIwan.o

testStephan:
	g++ -g --std=c++14 $(filter-out unitTest_Facade.cpp, $(filter-out main.cpp, $(filter-out unitTests_Iwan.cpp, $(filter-out unitTests_Tiaan.cpp, $(filter-out unitTests_Xavier.cpp, $(wildcard *.cpp)))))) -o main_testStephan.o -lgtest  -lgmock -lgtest_main -lpthread
	./main_testStephan.o

testXavier:
	g++ -g --std=c++14 $(filter-out unitTest_Facade.cpp, $(filter-out main.cpp, $(filter-out unitTests_Stephan.cpp, $(filter-out unitTests_Tiaan.cpp, $(filter-out unitTests_Iwan.cpp, $(wildcard *.cpp)))))) -o main_testXavier.o -lgtest  -lgmock -lgtest_main -lpthread
	./main_testXavier.o

testTiaan:
	g++ -g --std=c++14 $(filter-out unitTest_Facade.cpp, $(filter-out main.cpp, $(filter-out unitTests_Stephan.cpp, $(filter-out unitTests_Iwan.cpp, $(filter-out unitTests_Xavier.cpp, $(wildcard *.cpp)))))) -o main_testTiaan.o -lgtest -lgmock -lgtest_main -lpthread
	./main_testTiaan.o

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
