OBJECTS = main.o tv.o remote.o tv_exception.o
CC = g++
CFLAGS = -std=c++2a

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o output

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

tv.o: tv.hpp tv.cpp
	$(CC) $(CFLAGS) -c tv.cpp

remote.o: remote.hpp remote.cpp
	$(CC) $(CFLAGS) -c remote.cpp

tv_exception.o: tv_exception.hpp tv_exception.cpp
	$(CC) $(CFLAGS) -c tv_exception.cpp

clean:
	rm *.o output
