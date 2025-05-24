/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:51:00 by root              #+#    #+#             */
/*   Updated: 2025/05/24 15:25:24 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * @brief Sorts a stack of two elements.
 * 
 * @param data The data structure containing the stacks.
 * 
 * @note This function swaps the two elements in stack A if they are not
 * already sorted.
 */
void	fast_sort(t_data *data)
{
	int	a;
	int	b;

	a = data->a->value;
	b = data->a->next->value;
	if (b > a)
		sa(data, 1);
}

/**
 * @brief Sorts a stack of three elements.
 * 
 * @param data The data structure containing the stacks.
 * 
 * @note This function sorts the three elements in stack A using a series
 * of swaps and rotations.
 */
void	quick_sort(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->a->value;
	b = data->a->next->value;
	c = data->a->next->next->value;
	if (a > b && b < c && a < c)
		sa(data, 1);
	else if (a > b && b > c)
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if (a > b && b < c && a > c)
		ra(data, 1);
	else if (a < b && b > c && a < c)
	{
		sa(data, 1);
		ra(data, 1);
	}
	else if (a < b && b > c && a > c)
		rra(data, 1);
}

void	sort_small_stack(t_data *data)
{
	int		push_count;
	t_stack	*min;
	int		pos;

	push_count = 0;
	while (data->size_a > 3)
	{
		min = find_min_node(data->a);
		pos = get_node_position(data->a, min);
		if (pos <= data->size_a / 2)
			while (pos-- > 0)
				ra(data, 1);
		else
			while (pos++ < data->size_a)
				rra(data, 1);
		pb(data);
		push_count++;
	}
	quick_sort(data);
	while (push_count-- > 0)
		pa(data);
}

t_stack	*find_min_node(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->index < min->index)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	get_node_position(t_stack *stack, t_stack *target)
{
	int	i;

	i = 0;
	while (stack && stack != target)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
