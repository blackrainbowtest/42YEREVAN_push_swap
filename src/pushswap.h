/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:44:49 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/07 17:28:12 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/libft.h"
# include <limits.h>

// radix sort
typedef struct s_stack
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				next_direction;
}					t_stack;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	int			size_a;
	int			size_b;
	int			max_size;
}				t_data;

typedef struct s_arrays
{
	int			*values;
	int			*sorted;
	int			size;
}				t_arrays;

// indexing.c
int		*copy_and_sort(int *src, int len);
void	bubble_sort(int *arr, int len);
int		find_index(int *arr, int len, int value);
int		find_next_direction(t_arrays *arr, int i, int index);

// init.c
void	init_data(t_data *data);
void	fill_stack_a(t_data *data, int *values, int *sorted);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*init_stack_node(int value, int index, int next_direction);

// op_push.c
void	pa(t_data *data);
void	pb(t_data *data);

// op_reverse.c
void	rra(t_data *data, int print);
void	rrb(t_data *data, int print);
void	rrr(t_data *data);

// op_rotate.c
void	ra(t_data *data, int print);
void	rb(t_data *data, int print);
void	rr(t_data *data);

// op_swap.c
void	sa(t_data *data, int print);
void	sb(t_data *data, int print);
void	ss(t_data *data);

// parsing.c
void	parse_and_fill(t_data *data, int argc, char **argv);
char	**ft_get_all_values(int argc, char **argv);
int		has_duplicates(int *arr, int size);

// sorting.c
void	radix_sorting(t_data *data);
void	middle_sort(t_data *data);
void	best_move_to_top_a(t_data *data, t_stack *node);

// sorting2.c
void	fast_sort(t_data *data);
void	quick_sort(t_data *data);
void	sort_small_stack(t_data *data);
t_stack	*find_min_node(t_stack *stack);
int		get_node_position(t_stack *stack, t_stack *target);

// sorting3.c
void	chunk_sort(t_data *data);
void	split_chunk(t_data *data, int i, int chunk_size, int chunk_count);
void	return_sorted_to_a(t_data *data);
int		get_target_position(t_stack *a, int index_b);
void	calculate_costs(t_data *data);

// sorting4.c
void	move_stacks(t_data *data, int cost_a, int cost_b);

// utils_checkers.c
int		*ft_check_values(char **values, t_data *data);
int		ft_arrlen(char **arr);
int		is_sorted(t_stack *stack);
void	ft_only_digits(char **values, t_data *data, int ind, int *int_values);

// utils_error.c
char	**ft_free(char **split);
void	ft_error(void);
void	ft_exit_error(t_data *data, void *ptr);
void	ft_free_stack(t_stack **stack);
void	ft_exit_success(t_data *data, void *ptr);

// utils.c
int		is_valid_int_range(int n);
int		still_has_elements(t_stack *stack, int start_index, int end_index);
void	rotate_a_to_min(t_data *data);
t_stack	*find_cheapest_node(t_stack *b);
#endif