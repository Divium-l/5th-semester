NAME = output

CC = g++ 

CFLAGS = -std=c++2a -Wall -Wextra -Werror -Wno-unknown-pragmas

SRCS = main.cpp cinema.cpp session.cpp time_range.cpp

HEAD = cinema.hpp session.hpp time_range.hpp

OBJS = $(SRCS:.c = .o)

$(NAME) : $(OBJS) $(HEAD)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.cpp:%.o 
	$(CC) -c $< -o $@

all: $(NAME)

clean: 
	rm -rf $(NAME)

re: clean all