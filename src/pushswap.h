/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:44:49 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/11 10:01:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "../libft/libft.h"
#include <limits.h>

// radix sort
typedef struct s_stack
{
	int			    value;
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

// utils_error.c
void	ft_error(void);
void	ft_exit_error(t_data *data, void *ptr);
void	ft_free_stack(t_stack *stack);
void	ft_exit_success(t_data *data, void *ptr);
char	**ft_free(char **split);

// utils_checkers.c
int		*ft_check_values(char **values, t_data *data);
int		ft_arrlen(char **arr);
void	ft_only_digits(char **values, t_data *data, int ind);

// init.c
void	init_data(t_data *data);
t_stack	*init_stack_node(int value);

// parsing.c
void	parse_and_fill(t_data *data, int argc, char **argv);
char	**ft_get_all_values(int argc, char **argv);

// indexing.c
int		*copy_and_sort(int *src, int len);
void	bubble_sort(int *arr, int len);



#endif