/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:07:39 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/11 13:39:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->max_size = 0;
}

t_stack	*init_stack_node(int value, int index, t_stack *prev)
{
	t_stack *node;
	node = malloc(sizeof(t_stack));
	if (!node)
		ft_error();
	node->value = value;
	node->index = index;
	node->next = NULL;
	node->prev = prev;
	return (node);
}

void	fill_stack_a(t_data *data, int *values, int *sorted)
{
	
}