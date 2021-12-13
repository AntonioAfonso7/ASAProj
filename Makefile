CFLAGS = -std=c++11 -O3 -g -Wall

main: main.o treeNode.o tree.o matrix.o
	g++ $(CFLAGS) main.o matrix.o tree.o treeNode.o -lm -o main

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

tree.o: tree.cpp tree.h
	g++ $(CFLAGS) -c tree.cpp 

treeNode.o: treeNode.cpp treeNode.h
	g++ $(CFLAGS) -c treeNode.cpp

matrix.o: matrix.cpp matrix.h
	g++ $(CFLAGS) -c matrix.cpp

clean:
	rm -rf *.out *.out.dSYM *.dSYM *.o
