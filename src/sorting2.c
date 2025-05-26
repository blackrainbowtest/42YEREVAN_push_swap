/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:51:00 by root              #+#    #+#             */
/*   Updated: 2025/05/26 22:27:05 by root             ###   ########.fr       */
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

/**
* @brief Sorts a small stack of 4 or 5 elements.
*
* This function first pushes elements from stack A to stack B until only
* 3 elements remain in stack A. It then sorts the remaining elements using
* `quick_sort`. After sorting, it pushes the elements back from stack B to
* stack A in the correct order.
*
* @param data The data structure containing the stacks to be sorted.
*
* @return void
*/
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

/**
* @brief Finds the node with the minimum index in the stack.
*
* This function iterates through the stack and returns the node with the
* smallest index value. If the stack is empty, it returns NULL.
*
* @param stack The stack to search for the minimum node.
*
* @return A pointer to the node with the minimum index, 
* or NULL if the stack is empty.
*/
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

/**
* @brief Gets the position of a target node in the stack.
*
* This function traverses the stack and returns the index of the target node.
* If the target node is not found, it returns the index of the last node.
*
* @param stack The stack to search in.
* @param target The target node whose position is to be found.
*
* @return The index of the target node in the stack, or -1 if not found.
*/
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
