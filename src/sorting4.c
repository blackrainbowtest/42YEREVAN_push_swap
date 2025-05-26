/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:49:51 by root              #+#    #+#             */
/*   Updated: 2025/05/26 22:49:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	while (cost_a > 0)
	{
		ra(data, 1);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(data, 1); cost_a++;
	}
	while (cost_b > 0)
		{rb(data, 1); cost_b--;}
	while (cost_b < 0)
		{rrb(data, 1); cost_b++;}
}
