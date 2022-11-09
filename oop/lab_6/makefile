NAME = control

CC = g++ 

# CFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp tv.cpp remote.cpp tv_exception.cpp

HEAD = remote.hpp tv.hpp tv_exception.hpp

OBJS = $(SRCS:.c = .o)

$(NAME) : $(OBJS) $(HEAD)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.c:%.o 
	$(CC) -c $< -o $@

all: $(NAME)

clean: 
	rm -rf $(NAME)

re: clean all