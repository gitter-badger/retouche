retouche: retouche.o
		g++ -o retouche main.o system.o image.o lodepng.o
retouche.o: main.cpp
		g++ -std=c++0x -c main.cpp system.cpp model/image.cpp include/lodepng.cpp
