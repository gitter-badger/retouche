retouche: retouche.o
		g++ -o retouche main.o system.o image.o
retouche.o: main.cpp
		g++ -std=c++0x -c main.cpp system.cpp model/image.cpp
