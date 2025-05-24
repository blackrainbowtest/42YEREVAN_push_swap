MAKEFLAGS += --no-print-directory
NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

# show logs? 1 = yes, 0 = no
LOGS ?= 1
VERBOSE ?= 0 # 0 = no, 1 = yes
WC ?= 1 # 1 = pipe to wc -l, 0 = no pipe

# sources
SRCS := src/main.c src/init.c src/utils_error.c src/parsing.c src/utils_checkers.c src/indexing.c\
		src/op_push.c src/op_reverse.c src/op_rotate.c src/op_swap.c src/sorting.c src/sorting2.c\
		src/sorting3.c
OBJS := $(SRCS:.c=.o)

# libraries
LIBFT := libft/libft.a

# Function to set show commands or not
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
ifeq ($(WC),1)
	-$(QUIET)./$(NAME) "67 29 78 77 22 80 75 89 55 3 91 72 60 64 32 86 27 50 99 88 7 15 12 2 92 94 90 38 54 66 31 21 16 42 34 9 81 56 58 14 97 4 59 11 35 18 17 83 8 47 100 84 49 62 63 73 46 25 5 13 98 96 79 28 23 71 68 69 30 6 82 65 51 10 36 20 70 61 48 76 53 74 1 39 26 57 41 37 44 43 33 52 93 87 19 85 95 45 40 24" | wc -l
else
	-$(QUIET)./$(NAME) "67 29 78 77 22 80 75 89 55 3 91 72 60 64 32 86 27 50 99 88 7 15 12 2 92 94 90 38 54 66 31 21 16 42 34 9 81 56 58 14 97 4 59 11 35 18 17 83 8 47 100 84 49 62 63 73 46 25 5 13 98 96 79 28 23 71 68 69 30 6 82 65 51 10 36 20 70 61 48 76 53 74 1 39 26 57 41 37 44 43 33 52 93 87 19 85 95 45 40 24"
endif
	$(QUIET)echo "=== TEST END ==="
else
	-$(QUIET)./$(NAME) "4 -5 1 2 3" > /dev/null
endif
	$(QUIET)$(MAKE) clean

val: all
	-valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "3 2 1"
	-valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4 5 1 2 3
	$(QUIET)$(MAKE) clean

.PHONY: all clean fclean re test
