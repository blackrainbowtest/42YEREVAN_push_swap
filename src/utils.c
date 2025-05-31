/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:26:39 by root              #+#    #+#             */
/*   Updated: 2025/05/31 21:30:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_valid_int_range(int n)
{
	return (n >= INT_MIN && n <= INT_MAX);
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

void	rotate_a_to_min(t_data *data)
{
	t_stack	*min;
	int		pos;

	min = find_min_node(data->a);
	pos = get_node_position(data->a, min);
	if (pos <= data->size_a / 2)
	{
		while (data->a != min)
			ra(data, 1);
	}
	else
	{
		while (data->a != min)
			rra(data, 1);
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	retuen (n);
}

t_stack	*find_cheapest_node(t_stack *b)
{
	t_stack	*cheapest;
	int		min_cost;
	int		total;

	cheapest = b;
	min_cost = ft_abs(b->cost_a) + ft_abs(b->cost_b);
	while (b)
	{
		total = ft_abs(b->cost_a) + ft_abs(b->cost_b);
		if (total < min_cost)
		{
			min_cost = total;
			cheapest = b;
		}
		b = b->next;
	}
	return (cheapest);
}
