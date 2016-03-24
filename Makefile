retouche: retouche.o
	g++ -o retouche main.o
retouche.o: main.cpp
	g++ -std=c++0x -c main.cpp
