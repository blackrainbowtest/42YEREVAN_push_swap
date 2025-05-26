/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:21:19 by root              #+#    #+#             */
/*   Updated: 2025/05/26 21:28:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
* @brief Processes the current bit of the stack.
*
* This function iterates through the stack 'a' and checks the current bit
* of the index of each element. If the bit is 0, it pushes the element to
* stack 'b'; otherwise, it rotates the element to the top of stack 'a'.
*
* @param data The data structure containing the stacks to be processed.
* @param bit The current bit position to check in the index.
*
* @return void
*/
static void	process_current_bit(t_data *data, int bit)
{
	int	j;
	int	size;

	j = 0;
	size = data->size_a;
	while (j < size)
	{
		if (((data->a->index >> bit) & 1) == 0)
			pb(data);
		else
			ra(data, 1);
		j++;
	}
}

static t_stack	*find_target_node(t_stack *current, int next_index)
{
	t_stack	*target;

	target = NULL;
	while (current)
	{
		if (current->index == next_index)
		{
			target = current;
			break ;
		}
		current = current->next;
	}
	return (target);
}

/**
* @brief Sorts the stack using radix sort algorithm.
*
* This function sorts the stack 'a' in the data structure using the radix sort
* algorithm. It determines the maximum number of bits required to represent
* the largest index in the stack, and then sorts the elements based on each bit.
* It repeatedly pushes elements to stack 'b' based on the current bit,
* and then pushes them back to stack 'a' after processing all bits.
*
* @param data The data structure containing the stacks to be sorted.
*
* @return void
*/
void	radix_sorting(t_data *data)
{
	int	max_bits;
	int	max_index;
	int	i;

	max_bits = 0;
	max_index = data->max_size - 1;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		process_current_bit(data, i);
		while (data->size_b > 0)
			pa(data);
		i++;
	}
}

/**
* @brief Sorts a small stack of 5 or fewer elements.
*
* This function sorts the stack 'a' in the data structure when it contains
* 5 or fewer elements. It uses a simple sorting algorithm to arrange the
* elements in ascending order. The function repeatedly finds the minimum
* element in the stack and moves it to the top, then pushes it to stack 'b'.
*
* @param data The data structure containing the stacks to be sorted.
*
* @return void
*/
void	middle_sort(t_data *data)
{
	t_stack	*current;
	int		next_index;
	t_stack	*target;

	next_index = 0;
	while (next_index < data->max_size)
	{
		current = data->a;
		target = find_target_node(current, next_index);
		if (!target)
			break ;
		best_move_to_top_a(data, target);
		pb(data);
		next_index++;
	}
	while (data->size_b > 0)
		pa(data);
}

/**
* @brief Moves the specified node to the top of stack 'a'.
*
* This function finds the position of the specified node in stack 'a' and
* rotates the stack to bring that node to the top. It uses either a
* clockwise or counter-clockwise rotation based on the position of the node
* relative to the size of the stack.
*
* @param data The data structure containing the stacks.
* @param node The node to be moved to the top of stack 'a'.
*
* @return void
*/
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
