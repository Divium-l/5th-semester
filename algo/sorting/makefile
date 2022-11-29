OBJECTS = main.o sort.o
CC = g++
CFLAGS = -std=c++2a

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o output

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

sort.o: sort.hpp sort.cpp
	$(CC) $(CFLAGS) -c sort.cpp

clean:
	rm *.o output