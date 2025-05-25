/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:42:16 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/25 12:28:57 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	chunk_sort(t_data *data)
{
	int	chunk_size;
	int	chunk_count;
	int	i;

	chunk_count = (int)(data->max_size * 0.05);
	if (chunk_count < 1)
		chunk_count = 1;
	chunk_size = data->max_size / chunk_count;
	i = 0;
	while (i < chunk_count)
	{
		split_chunk(data, i, chunk_size, chunk_count);
		i++;
	}
	return_sorted_to_a(data);
}

void	split_chunk(t_data *data, int i, int chunk_size, int chunk_count)
{
	int	start_index;
	int	end_index;

	start_index = i * chunk_size;
	end_index = start_index + chunk_size - 1;
	if (i == chunk_count - 1)
		end_index = data->max_size - 1;
	while (still_has_elements(data->a, start_index, end_index))
	{
		if (data->a->index >= start_index && data->a->index <= end_index)
		{
			pb(data);
			if (data->b && data->b->index < (start_index + end_index) / 2)
				rb(data, 1);
		}
		else
		{
			ra(data, 1);
		}
	}
}

void	return_sorted_to_a(t_data *data)
{
	t_stack	*max_node;
	int		pos;


	while (data->size_b > 0)
	{
		max_node = find_max_node(data->b);
		pos = get_node_position(data->b, max_node);
		if (pos <= data->size_b / 2)
		{
			while (data->b != max_node)
				rb(data, 1);
		}
		else
		{
			while (data->b != max_node)
				rrb(data, 1);
		}
		pa(data);
	}
}

int	still_has_elements(t_stack *stack, int start_index, int end_index)
{
	while (stack)
	{
		if (stack->index >= start_index && stack->index <= end_index)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_stack	*find_max_node(t_stack *stack)
{
	t_stack *max = stack;

	while (stack)
	{
		if (stack->index > max->index)
			max = stack;
		stack = stack->next;
	}
	return (max);
}