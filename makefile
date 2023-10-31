compile:
	# g++ --std=c++11 -ferror-limit=1 main.cpp -o main.o 
	g++ --std=c++11 -w main.cpp 2>&1 | grep -c "error:"
run:
	./main.o
leaks:
	leaks -atExit -- ./main.o
