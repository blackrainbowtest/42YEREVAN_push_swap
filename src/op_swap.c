/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:33:45 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/16 19:05:45 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_data *data, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!data->a || !data->a->next)
		return ;
	first = data->a;
	second = data->a->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	data->a = second;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_data *data, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!data->b || !data->b->next)
		return ;
	first = data->b;
	second = data->b->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	data->b = second;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	sa(data, 0);
	sb(data, 0);
	write(1, "ss\n", 3);
}
