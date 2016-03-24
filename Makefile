retouche: retouche.o
	g++ -o retouche main.o image.o
retouche.o: main.cpp
	g++ -std=c++0x -c main.cpp model/image.cpp
