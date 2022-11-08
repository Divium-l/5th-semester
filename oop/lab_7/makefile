OBJECTS = main.o review.o
CC = g++
CFLAGS = -std=c++2a

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o output

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

review.o: review.hpp review.cpp
	$(CC) $(CFLAGS) -c review.cpp

clean:
	rm *.o output