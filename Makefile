retouche: retouche.o
	g++ -o retouche main.o
retouche.o: main.cpp
	g++ -c main.cpp
