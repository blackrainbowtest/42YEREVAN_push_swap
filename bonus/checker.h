/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:50:12 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/31 15:04:12 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line_bonus.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	int			size_a;
	int			size_b;
	int			max_size;
}				t_data;

// init.c
void	init_data(t_data *data);
void	fill_stack_a(t_data *data, int *values, int *sorted);
t_stack	*init_stack_node(int value, int index);
int		find_index(int *arr, int len, int value);
int		*copy_and_sort(int *src, int len);

// op_push.c
void	pa(t_data *data, int print);
void	pb(t_data *data, int print);

// op_reverse.c
void	rra(t_data *data, int print);
void	rrb(t_data *data, int print);
void	rrr(t_data *data, int print);

// op_rotate.c
void	ra(t_data *data, int print);
void	rb(t_data *data, int print);
void	rr(t_data *data, int print);

// op_swap.c
void	sa(t_data *data, int print);
void	sb(t_data *data, int print);
void	ss(t_data *data, int print);

// parsing.c
char	**ft_get_all_values(int argc, char **argv);
int		has_duplicates(int *arr, int size);
void	parse_and_fill(t_data *data, int argc, char **argv);
void	stack_add_back(t_stack **stack, t_stack *new);
int		is_valid_int_range(int n);

// utils_checkers.c
int		is_sorted(t_stack *stack);
int		*ft_check_values(char **unchecked_values, t_data *data);
int		ft_arrlen(char **arr);

// utils_exit.c
void	exit_ok(t_data *data, void *ptr);
void	exit_ko(t_data *data, void *ptr);
void	exit_error(t_data *data, void *ptr);

// utils_free.c
void	multiply_clear(t_data *data, void *ptr);
void	ft_free_stack(t_stack **stack);
char	**ft_free(char **split);

// utils_sort.c
void	bubble_sort(int *arr, int len);
#endif