CFLAGS = -std=c++11 -O3 -g -Wall -lm

main: main.o tree.o
	g++ $(CFLAGS) main.o tree.o -o main

main.o: main.cpp 
	g++ $(CFLAGS) main.cpp -o main.o

tree.o: tree.cpp
	g++ $(CFLAGS) tree.cpp -o tree.o

clean:
	rm -rf *.out *.out.dSYM *.dSYM *.o
