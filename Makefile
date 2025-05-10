MAKEFLAGS += --no-print-directory
NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

# show logs? 1 = yes, 0 = no
LOGS ?= 1
VERBOSE ?= 0  # 1 для вывода команд, 0 для без вывода

# sources
SRCS := src/main.c src/init.c src/utils_error.c src/parsing.c src/utils_checkers.c
OBJS := $(SRCS:.c=.o)

# libraries
LIBFT := libft/libft.a

# Функция для определения, выводить команду или нет
QUIET = $(if $(filter 0,$(VERBOSE)),@,)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(QUIET)$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(QUIET)$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(QUIET)make -C libft

clean:
	$(QUIET)$(RM) $(OBJS)
	$(QUIET)make clean -C libft

fclean: clean
	$(QUIET)$(RM) $(NAME)
	$(QUIET)make fclean -C libft

re: fclean all

# test
test: all
ifeq ($(LOGS),1)
	$(QUIET)echo "=== TEST START ==="
	$(QUIET)./$(NAME) 3 2 1
	$(QUIET)./$(NAME) "4 -5 1 2 3"
	$(QUIET)echo "=== TEST END ==="
else
	$(QUIET)./$(NAME) 3 2 1 > /dev/null
	$(QUIET)./$(NAME) "4 5 1 2 3" > /dev/null
endif
	$(QUIET)$(MAKE) clean

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "3 2 1"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4 5 1 2 3

.PHONY: all clean fclean re test
