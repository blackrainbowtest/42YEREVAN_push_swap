NAME := push_swap

cc := cc

CFLAGS := -Wall -Wextra -Werror

RM := rm -f

# C sources
SRCS := src/main.c\
		libft/libft.a\

#SRCSB

$(NAME) :
		make bonus -C libft
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
		$(RM) $(NAME)
		make fclean -C libft

clean :
		$(RM) $(NAME)
		make clean -C libft

re : fclean all

#bonus : 