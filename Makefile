MAKEFLAGS += --no-print-directory
NAME := push_swap
BONUS_NAME := checker

CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

# show logs? 1 = yes, 0 = no
LOGS ?= 1
VERBOSE ?= 0 # 0 = no, 1 = yes
WC ?= 1 # 1 = pipe to wc -l, 0 = no pipe

# Function to set show commands or not
QUIET = $(if $(filter 0,$(VERBOSE)),@,)

# sources
SRCS := src/push_swap.c src/init.c src/utils_error.c src/parsing.c src/utils_checkers.c src/indexing.c\
		src/op_push.c src/op_reverse.c src/op_rotate.c src/op_swap.c src/sorting.c src/sorting2.c\
		src/sorting3.c src/sorting4.c src/utils.c
BONUS_SRCS := bonus/checker.c bonus/utils_exit.c bonus/utils_free.c bonus/init.c bonus/parsing.c bonus/utils_checkers.c\
		bonus/utils_sort.c bonus/op_push.c bonus/op_reverse.c bonus/op_rotate.c bonus/op_swap.c

OBJS := $(SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

# libraries
LIBFT := libft/libft.a
GNL := get_next_line/get_next_line.a

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(QUIET)$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(GNL)
	$(QUIET)$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(GNL) -o $(BONUS_NAME)

%.o: %.c
	$(QUIET)$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(QUIET)make -C libft fclean
	$(QUIET)make -C libft

$(GNL):
	$(QUIET)make -C get_next_line fclean
	$(QUIET)make -C get_next_line

clean:
	$(QUIET)$(RM) $(OBJS) $(BONUS_OBJS)
	$(QUIET)make clean -C libft
	$(QUIET)make clean -C get_next_line

fclean: clean
	$(QUIET)$(RM) $(NAME) $(BONUS_NAME)
	$(QUIET)make fclean -C libft
	$(QUIET)make fclean -C get_next_line

re: fclean all

ARGS := 1 2 3 4
ARGS100 := "67 29 78 77 22 80 75 89 55 3 91 72 60 64 32 86 27 50 99 88 7 15 12 2 92 94 90 38 54 66 31 21 16 42 34 9 81 56 58 14 97 4 59 11 35 18 17 83 8 47 100 84 49 62 63 73 46 25 5 13 98 96 79 28 23 71 68 69 30 6 82 65 51 10 36 20 70 61 48 76 53 74 1 39 26 57 41 37 44 43 33 52 93 87 19 85 95 45 40 24"
# test
test: all
ifeq ($(LOGS),1)
ifeq ($(WC),1)
	-$(QUIET)./$(NAME) $(ARGS100) | wc -l
else
	-$(QUIET)./$(NAME) $(ARGS100)
endif
else
	-$(QUIET)./$(NAME) $(ARGS100) > /dev/null
endif
	$(QUIET)$(MAKE) clean

val: all
	-valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS100)
	$(QUIET)$(MAKE) clean

chok: bonus
	-$(QUIET)./push_swap $(ARGS) | ./checker $(ARGS)
	$(QUIET)$(MAKE) clean

chko: bonus
	-$(QUIET)echo "pb\nsa\npa" | ./checker $(ARGS)
	$(QUIET)$(MAKE) clean

val_chok: bonus
	-$(QUIET)./push_swap $(ARGS) > .commands.txt
	-valgrind --leak-check=full --show-leak-kinds=all ./checker $(ARGS) < .commands.txt
	$(RM) .commands.txt
	$(QUIET)$(MAKE) clean

val_chko: bonus
	echo "pb\nsa\npa" | valgrind --leak-check=full --show-leak-kinds=all ./checker $(ARGS)
	$(QUIET)$(MAKE) clean

.PHONY: all clean fclean re test
