retouche: retouche.o
	g++ -o retouche main.o system.o image.o
retouche.o: main.cpp
	g++ -std=c++0x -c main.cpp
image.o: model/image.cpp
	g++ -std=c++0x -c model/image.cpp
system.o: system.cpp
	g++ -std=c++0x -c system.cpp
