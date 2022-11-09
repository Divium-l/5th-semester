NAME = control

CC = clang++ 

# CFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp tv.cpp remote.cpp tv_exception.cpp

HEAD = Remote.hpp Tv.hpp

OBJS = $(SRCS:.c = .o)

$(NAME) : $(OBJS) $(HEAD)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.c:%.o 
	$(CC) -c $< -o $@

all: $(NAME)

clean: 
	rm -rf $(NAME)

re: clean all