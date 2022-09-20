OBJECTS = main.o cd.o classic.o
CC = g++
CFLAGS = -std=c++20

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o output

main.o: main.cpp
	$(CC) -c main.cpp

cd.o: cd.cpp cd.hpp
	$(CC) -c cd.cpp cd.hpp

classic.o: classic.cpp classic.hpp
	$(CC) -c classic.cpp classic.hpp

clean:
	rm *.o output