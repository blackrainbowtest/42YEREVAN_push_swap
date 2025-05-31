/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:03:55 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/31 15:03:59 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->max_size = 0;
}

void	fill_stack_a(t_data *data, int *values, int *sorted)
{
	int			i;
	int			index;
	t_stack		*new;

	i = 0;
	while (i < data->max_size)
	{
		index = find_index(sorted, data->max_size, values[i]);
		new = init_stack_node(values[i], index);
		if (!new)
		{
			free(values);
			exit_error(data, NULL);
		}
		stack_add_back(&data->a, new);
		i++;
	}
}

t_stack	*init_stack_node(int value, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	find_index(int *arr, int len, int value)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	*copy_and_sort(int *src, int len)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * len);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sorted[i] = src[i];
		i++;
	}
	bubble_sort(sorted, len);
	return (sorted);
}
