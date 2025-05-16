/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:33:48 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/16 19:09:40 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_data *data, int print)
{
	t_stack	*tmp;

	if (data->a == NULL || data->a->next == NULL)
		return ;
	tmp = data->a;
	data->a = data->a->next;
	data->a->prev = NULL;
}

void	rb(t_data *data, int print)
{
	// Rotate stack B (first element becomes last)
}

void	rr(t_data *data)
{
	ra(data, 0);
	rb(data, 0);
	write(1, "rr\n", 3);
}
