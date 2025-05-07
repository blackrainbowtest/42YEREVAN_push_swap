NAME := push_swap

cc := cc

#CFLAGS := -Wall -Wextra -Werror

RM := rm -f

# C sources
SRCS := src/main.c\
		src/utils_error.c\

OBJS := $(SRCS:.c=.o)

#SRCSB

$(NAME): $(OBJS)
		make -C libft
		$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

all : $(NAME)

fclean : clean
		$(RM) $(NAME)
		make fclean -C libft

clean :
		$(RM) $(OBJS)
		make clean -C libft

re : fclean all

#bonus : 