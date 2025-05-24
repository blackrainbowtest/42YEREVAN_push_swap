/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:21:19 by root              #+#    #+#             */
/*   Updated: 2025/05/24 15:27:08 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	radix_sorting(t_data *data)
{
	int	max_bits;
	int	max_index;
	int	size;
	int	i;
	int	j;

	max_bits = 0;
	max_index = data->max_size - 1;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = data->size_a;
		while (j < size)
		{
			if (((data->a->index >> i) & 1) == 0)
				pb(data);
			else
				ra(data, 1);
			j++;
		}
		while (data->size_b > 0)
			pa(data);
		i++;
	}
}

void	middle_sort(t_data *data)
{
	t_stack	*current;
	int		next_index;
	t_stack	*target;

	next_index = 0;
	while (next_index < data->max_size)
	{
		current = data->a;
		target = NULL;
		while (current)
		{
			if (current->index == next_index++)
			{
				target = current;
				break ;
			}
			current = current->next;
		}
		if (!target)
			break ;
		best_move_to_top_a(data, target);
		pb(data);
	}
	while (data->size_b > 0)
		pa(data);
}

void	best_move_to_top_a(t_data *data, t_stack *node)
{
	int		pos;
	int		size;
	t_stack	*temp;

	pos = 0;
	temp = data->a;
	while (temp && temp != node)
	{
		pos++;
		temp = temp->next;
	}
	size = data->size_a;
	if (pos <= size / 2)
	{
		while (data->a != node)
			ra(data, 1);
	}
	else
	{
		while (data->a != node)
			rra(data, 1);
	}
}
