OBJECTS = main.o wine.o
CC = g++
CFLAGS = -std=c++2a

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o output

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

wine.o: wine.hpp wine.cpp
	$(CC) $(CFLAGS) -c wine.cpp

clean:
	rm *.o output