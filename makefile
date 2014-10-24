all: main

main: main.o morseTree.o
	g++ main.o morseTree.o -o main -std=gnu++11
main.o: main.cpp
	g++ -c main.cpp -std=gnu++11
morseTree.o: morseTree.cpp morseTree.hpp
	g++ -c morseTree.cpp -std=gnu++11
