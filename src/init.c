/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:07:39 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/11 14:53:46 by root             ###   ########.fr       */
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

t_stack	*init_stack_node(int value, int index)
{
	t_stack *node;
	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	fill_stack_a(t_data *data, int *values, int *sorted)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (i < data->max_size)
	{
		int index = find_index(sorted, data->max_size, values[i]);
		new = init_stack_node(values[i], index);
		if (!new)
		{
			free(values);
			free(sorted);
			ft_exit_error(data, NULL);
		}
		stack_add_back(&data->a, new);
		i++;
	}
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return;
	if (!*stack)
	{
		*stack = new;
		return;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}