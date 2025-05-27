/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:50:12 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/28 00:14:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

// utils_checkers.c
int	is_sorted(t_stack *stack);

// utils_exit.c
void	exit_ok(t_data *data, void *ptr);
void	exit_ko(t_data *data, void *ptr);
void	exit_error(t_data *data, void *ptr);

// utils_free.c
void	multiply_clear(t_data *data, void *ptr);
#endif