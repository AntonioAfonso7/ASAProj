CFLAGS = -std=c++11 -O3 -g -Wall -lm 

main: main.o treeNode.o tree.o
	g++ $(CFLAGS) main.o tree.o treeNode.o -o main

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

tree.o: tree.cpp tree.h
	g++ $(CFLAGS) -c tree.cpp

treeNode.o: treeNode.cpp treeNode.h
	g++ $(CFLAGS) -c treeNode.cpp

clean:
	rm -rf *.out *.out.dSYM *.dSYM *.o
