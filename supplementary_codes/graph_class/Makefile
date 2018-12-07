main.out: main.o
	g++ -std=c11 -Wall -O2 main.o -o main.out -g
main.o: main.cpp graph.h
	g++ -std=c++11 -Wall -O2 -c main.cpp -g
clean:
	rm *.o *.out
