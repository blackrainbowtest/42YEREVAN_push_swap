/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:44:49 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/07 19:15:42 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "../libft/libft.h"
#include <limits.h>

// radix sort
typedef struct s_stack
{
	void			*value;
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

// init.c
void	init_data(t_data *data);
t_stack	*init_stack_node(int value);

#endif