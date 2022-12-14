NAME = output

CC = g++ 

CFLAGS = -std=c++2a -Wall -Wextra -Werror

OBJECTS = main.o
	
all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean: 
	rm -rf $(NAME) *.o

re: clean all