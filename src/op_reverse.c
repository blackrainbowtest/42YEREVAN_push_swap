/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:33:41 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/16 19:10:11 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_data *data, int print)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!data->a || !data->a->next)
		return ;
	last = data->a;
	while (last->next)
		last = last->next;
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = data->a;
	data->a->prev = last;
	data->a = last;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_data *data, int print)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!data->b || !data->b->next)
		return ;
	last = data->b;
	while (last->next)
		last = last->next;
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = data->b;
	data->b->prev = last;
	data->b = last;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	rra(data, 0);
	rrb(data, 0);
	write(1, "rrr\n", 4);
}
