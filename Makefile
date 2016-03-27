retouche: retouche.o
		g++ -o retouche main.o system.o image.o lodepng.o jpge.o jpgd.o
retouche.o: main.cpp
		g++ -std=c++0x -I /usr/include/malloc -c main.cpp system.cpp model/image.cpp include/lodepng.cpp include/jpge.cpp include/jpgd.cpp
