/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:33:37 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/30 00:14:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * @brief Push the top element of stack B to stack A.
 * 
 * This function removes the top element from stack B
 * and adds it to the top of stack A.
 * If stack B is empty, no action is taken.
 * 
 * @param data Pointer to the data structure containing the stacks.
 * 
 * @return This function does not return; it modifies the stacks in place.
 */
void	pa(t_data *data, int print)
{
	t_stack	*tmp;

	if (data->b == NULL)
		return ;
	tmp = data->b;
	data->b = data->b->next;
	if (data->b)
		data->b->prev = NULL;
	tmp->next = data->a;
	if (data->a)
		data->a->prev = tmp;
	data->a = tmp;
	data->size_a++;
	data->size_b--;
	if (print)
		write(1, "pa\n", 3);
}

/**
 * @brief Push the top element of stack A to stack B.
 * 
 * This function removes the top element from stack A
 * and adds it to the top of stack B.
 * If stack A is empty, no action is taken.
 * 
 * @param data Pointer to the data structure containing the stacks.
 * 
 * @return This function does not return; it modifies the stacks in place.
 */
void	pb(t_data *data, int print)
{
	t_stack	*tmp;

	if (data->a == NULL)
		return ;
	tmp = data->a;
	data->a = data->a->next;
	if (data->a)
		data->a->prev = NULL;
	tmp->next = data->b;
	if (data->b)
		data->b->prev = tmp;
	data->b = tmp;
	data->size_a--;
	data->size_b++;
	if (print)
		write(1, "pb\n", 3);
}
