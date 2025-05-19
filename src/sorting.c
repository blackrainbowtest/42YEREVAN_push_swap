/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:21:19 by root              #+#    #+#             */
/*   Updated: 2025/05/18 14:20:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
		int j = 0;
		int size = data->size_a;
		while (j < size)
		{
			if (((data->a->index >> i) & 1) == 0)
				pb(data);
			else
				ra(data, 1);
			j++;
			printf("first num in stack b is %d\n", data->b->value);
		}
		while (data->size_b > 0)
			pa(data);
		i++;
	}
}

void	fast_sort(t_data *data)
{
	int	a;
	int	b;

	a = data->a->value;
	b = data->a->next->value;
	if (b > a)
		sa(data, 1);
}

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
