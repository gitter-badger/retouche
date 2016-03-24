WARN_FLAGS=-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

retouche: retouche.o
	g++ -o retouche main.o image.o
retouche.o: main.cpp
	g++ -std=c++0x -c $(WARN_FLAGS) main.cpp model/image.cpp
