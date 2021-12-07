CFLAGS = -std=c++11 -O3 -g -Wall -lm

main: main.cpp
	g++ $(CFLAGS) main.cpp -o main

clean:
	rm -rf *.out *.out.dSYM *.dSYM
