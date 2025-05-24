/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:42:16 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/24 16:07:42 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	chunk_sort(t_data *data)
{
	int	chunk_size;
	int	chunk_count;

	chunk_count = (int)(data->max_size * 0.05);
	if (chunk_count < 1)
		chunk_count = 1;
	chunk_size = data->max_size / chunk_count;
}
