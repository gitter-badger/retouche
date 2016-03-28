# Compiler
C = g++
CFLAGS = -std=c++0x -Wall

# Linker
L = ld

OBJECTS = main.o core.o system.o model.o persistence.o manipulation.o
CORE = command_parser.o
MODEL = image.o
PERSISTENCE = bitmap_persister.o jpeg_persister.o png_persister.o
MANIPULATION = blur.o grayscale.o inverse.o flip.o

retouche: $(OBJECTS)
	$(C) -o retouche $(OBJECTS)
main.o: main.cpp
	$(C) $(CFLAGS) -c main.cpp
system.o: system.cpp
	$(C) $(CFLAGS) -c system.cpp

# Core objects
core.o: $(CORE)
	$(L) -r $(CORE) -o core.o
command_parser.o: core/command_parser.cpp
	$(C) $(CFLAGS) -c core/command_parser.cpp

# Model objects
model.o: $(MODEL)
	$(L) -r $(MODEL) -o model.o
image.o: model/image.cpp
	$(C) $(CFLAGS) -c model/image.cpp

# Persistence objects
persistence.o: $(PERSISTENCE)
	$(L) -r $(PERSISTENCE) -o persistence.o
bitmap_persister.o: persistence/bitmap_persister.cpp
	$(C) $(CFLAGS) -c persistence/bitmap_persister.cpp
jpeg_persister.o: persistence/jpeg_persister.cpp jpge.o jpgd.o
	$(C) $(CFLAGS) -c persistence/jpeg_persister.cpp
	$(L) -r jpeg_persister.o jpge.o jpgd.o -o jpeg_persister.o
png_persister.o: persistence/png_persister.cpp lodepng.o
	$(C) $(CFLAGS) -c persistence/png_persister.cpp
	$(L) -r png_persister.o lodepng.o -o png_persister.o
lodepng.o: include/lodepng.cpp
	$(C) $(CFLAGS) -c include/lodepng.cpp
jpge.o: include/jpge.cpp
	$(C) $(CFLAGS) -w -I /usr/include/malloc -c include/jpge.cpp
jpgd.o: include/jpgd.cpp
	$(C) $(CFLAGS) -w -c include/jpgd.cpp

# Manipulation objects
manipulation.o: manipulation/factory.cpp $(MANIPULATION)
	$(C) $(CFLAGS) -c manipulation/factory.cpp manipulation/exceptions.cpp
	$(L) -r factory.o exceptions.o $(MANIPULATION) -o manipulation.o
%.o : manipulation/filter/%.cpp
	$(C) $(CFLAGS) -c $< -o $@
%.o: manipulation/transformation/%.cpp
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm *o retouche
