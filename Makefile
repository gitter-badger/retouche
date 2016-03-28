# Compiler
CFLAGS = -std=c++11 -Wall

# Linker
L = ld

OBJECTS = main.o core.o system.o model.o persistence.o manipulation.o
CORE = command_parser.o
MODEL = image.o
PERSISTENCE = bitmap_persister.o jpeg_persister.o png_persister.o
MANIPULATION = blur.o grayscale.o inverse.o flip.o

.PHONY: test clean

all: test retouche

# Program
retouche: $(OBJECTS)
	$(CXX) -o retouche $(OBJECTS)
main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp
system.o: system.cpp
	$(CXX) $(CFLAGS) -c system.cpp

# Tests
test: command_parser_test.o array_test.o
	$(CXX) -o test test.cpp command_parser.o command_parser_test.o array_test.o
	./test
command_parser_test.o: core/command_parser.cpp core/command_parser_test.cpp
	$(CXX) $(CFLAGS) -c core/command_parser.cpp core/command_parser_test.cpp
array_test.o: core/array_test.cpp
	$(CXX) $(CFLAGS) -c core/array_test.cpp

# Core objects
core.o: $(CORE)
	$(L) -r $(CORE) -o core.o
command_parser.o: core/command_parser.cpp
	$(CXX) $(CFLAGS) -c core/command_parser.cpp

# Model objects
model.o: $(MODEL)
	$(L) -r $(MODEL) -o model.o
image.o: model/image.cpp
	$(CXX) $(CFLAGS) -c model/image.cpp

# Persistence objects
persistence.o: $(PERSISTENCE)
	$(L) -r $(PERSISTENCE) -o persistence.o
bitmap_persister.o: persistence/bitmap_persister.cpp
	$(CXX) $(CFLAGS) -c persistence/bitmap_persister.cpp
jpeg_persister.o: persistence/jpeg_persister.cpp jpge.o jpgd.o
	$(CXX) $(CFLAGS) -c persistence/jpeg_persister.cpp
	$(L) -r jpeg_persister.o jpge.o jpgd.o -o jpeg_persister.o
png_persister.o: persistence/png_persister.cpp lodepng.o
	$(CXX) $(CFLAGS) -c persistence/png_persister.cpp
	$(L) -r png_persister.o lodepng.o -o png_persister.o
lodepng.o: include/lodepng.cpp
	$(CXX) $(CFLAGS) -c include/lodepng.cpp
jpge.o: include/jpge.cpp
	$(CXX) $(CFLAGS) -w -I /usr/include/malloc -c include/jpge.cpp
jpgd.o: include/jpgd.cpp
	$(CXX) $(CFLAGS) -w -c include/jpgd.cpp

# Manipulation objects
manipulation.o: manipulation/factory.cpp $(MANIPULATION)
	$(CXX) $(CFLAGS) -c manipulation/factory.cpp manipulation/exceptions.cpp
	$(L) -r factory.o exceptions.o $(MANIPULATION) -o manipulation.o
%.o : manipulation/filter/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@
%.o: manipulation/transformation/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm *o test retouche
