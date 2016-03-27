CC = g++
CFLAGS = -std=c++0x -Wall

OBJECTS = main.o system.o image.o lodepng.o jpge.o jpgd.o

retouche: $(OBJECTS)
	$(CC) -o retouche $(OBJECTS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
image.o: model/image.cpp
	$(CC) $(CFLAGS) -c model/image.cpp
lodepng.o: include/lodepng.cpp
	$(CC) $(CFLAGS) -c include/lodepng.cpp
system.o: system.cpp
	$(CC) $(CFLAGS) -c system.cpp
jpge.o: include/jpge.cpp
	$(CC) $(CFLAGS) -w -I /usr/include/malloc -c include/jpge.cpp
jpgd.o: include/jpgd.cpp
	$(CC) $(CFLAGS) -w -c include/jpgd.cpp

clean:
	rm *o retouche
