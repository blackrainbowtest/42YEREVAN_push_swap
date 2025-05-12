/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:33:37 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/12 20:46:12 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * @brief Push the top element of stack B to stack A.
 * 
 * This function removes the top element from stack B and adds it to the top of stack A.
 * If stack B is empty, no action is taken.
 * 
 * @param data Pointer to the data structure containing the stacks.
 * 
 * @return This function does not return; it modifies the stacks in place.
 */
void	pa(t_data *data)
{
	t_data	*tmp;

	if (data->b == NULL)
		return ;
	tmp = data->b;
}

/**
 * @brief Push the top element of stack A to stack B.
 * 
 * This function removes the top element from stack A and adds it to the top of stack B.
 * If stack A is empty, no action is taken.
 * 
 * @param data Pointer to the data structure containing the stacks.
 * 
 * @return This function does not return; it modifies the stacks in place.
 */
void	pb(t_data *data)
{
	t_data	*tmp;

	if (data->a == NULL)
		return ;
	tmp = data->a;
}
