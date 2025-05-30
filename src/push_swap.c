/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:07:30 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/27 18:12:30 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		ft_error();
	data = malloc(sizeof(t_data));
	if (!data)
		ft_error();
	init_data(data);
	parse_and_fill(data, argc, argv);
	if (is_sorted(data->a))
		ft_exit_success(data, NULL);
	if (data->size_a == 2)
		fast_sort(data);
	else if (data->size_a == 3)
		quick_sort(data);
	else if (data->size_a < 6)
		sort_small_stack(data);
	else if (data->size_a < 50)
		middle_sort(data);
	else if (data->size_a <= 500)
		chunk_sort(data);
	else
		radix_sorting(data);
	ft_exit_success(data, NULL);
	return (EXIT_SUCCESS);
}
