OBJECTS = main.o
CC = g++
CFLAGS = -std=c++20

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o output

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm *.o output