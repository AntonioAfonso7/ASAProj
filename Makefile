CFLAGS = -std=c++11 -O3 -g -Wall

main: main.o treeNode.o tree.o
	g++ $(CFLAGS) main.o tree.o treeNode.o -lm -o main

main.o: main.cpp
	g++ $(CFLAGS) -c -lm main.cpp

tree.o: tree.cpp tree.h
	g++ $(CFLAGS) -c -lm tree.cpp 

treeNode.o: treeNode.cpp treeNode.h
	g++ $(CFLAGS) -c -lm treeNode.cpp

clean:
	rm -rf *.out *.out.dSYM *.dSYM *.o
