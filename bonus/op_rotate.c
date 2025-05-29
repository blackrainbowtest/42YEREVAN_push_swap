/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:33:48 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/30 00:14:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_data *data, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!data->a || !data->a->next)
		return ;
	first = data->a;
	data->a = first->next;
	data->a->prev = NULL;
	last = data->a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_data *data, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!data->b || !data->b->next)
		return ;
	first = data->b;
	data->b = first->next;
	data->b->prev = NULL;
	last = data->b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_data *data, int print)
{
	ra(data, 0);
	rb(data, 0);
	if (print)
		write(1, "rr\n", 3);
}
