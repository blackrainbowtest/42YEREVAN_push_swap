/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:42:16 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/24 16:32:03 by aramarak         ###   ########.fr       */
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
			pb(data);
		else
			ra(data, 1);
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
