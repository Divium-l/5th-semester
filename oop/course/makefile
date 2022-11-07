OBJECTS = main.o cinema.o session.o time_range.o
CC = g++
CFLAGS = -std=c++2a

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o output

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

cinema.o: cinema.hpp cinema.cpp
	$(CC) $(CFLAGS) -c cinema.cpp

session.o: session.hpp session.cpp
	$(CC) $(CFLAGS) -c session.cpp

time_range.o: time_range.hpp time_range.cpp
	$(CC) $(CFLAGS) -c time_range.cpp

clean:
	rm *.o output