OBJECTS = main.o session.o
CC = g++
CFLAGS = -std=c++2a

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o output

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

session.o: session.hpp session.cpp
	$(CC) $(CFLAGS) -c session.cpp

clean:
	rm *.o output