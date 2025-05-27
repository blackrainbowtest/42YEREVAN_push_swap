/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:49:51 by root              #+#    #+#             */
/*   Updated: 2025/05/27 18:10:39 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	move_stack_a(t_data *data, int cost_a)
{
	while (cost_a > 0)
	{
		ra(data, 1);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(data, 1);
		cost_a++;
	}
}

static void	move_stack_b(t_data *data, int cost_b)
{
	while (cost_b > 0)
	{
		rb(data, 1);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(data, 1);
		cost_b++;
	}
}

void	move_stacks(t_data *data, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(data);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(data);
		cost_a++;
		cost_b++;
	}
	move_stack_a(data, cost_a);
	move_stack_b(data, cost_b);
}
