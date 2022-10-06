OBJECTS = main.o emp.o
CC = g++
CFLAGS = -std=c++2a

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o output

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

emp.o: emp.cpp
	$(CC) $(CFLAGS) -c emp.cpp

clean:
	rm *.o output