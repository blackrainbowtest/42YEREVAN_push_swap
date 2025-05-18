/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:21:19 by root              #+#    #+#             */
/*   Updated: 2025/05/18 11:33:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	radix_sorting(t_data *data)
{
	int	max_bits;
	int	max_index;
	int	i;

	max_bits = 0;
	max_index = data->max_size - 1;
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
				ra(data);
			j++;
		}
		while (data->size_b > 0)
			pa(data);
		i++;
	}
}