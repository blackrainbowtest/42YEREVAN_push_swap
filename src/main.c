/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:07:30 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/16 19:20:30 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	*data;
	t_stack	*tmp;

	if (argc < 2)
		ft_error();
	data = malloc(sizeof(t_data));
	if (!data)
		ft_error();
	init_data(data);
	parse_and_fill(data, argc, argv);
	if (is_sorted(data->a))
		ft_exit_success(data, NULL);

	tmp = data->a;
	while (tmp)
	{
		printf("Value: %d, Index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	printf("Stack a is empty\n");
	ft_exit_success(data, NULL);
	return (EXIT_SUCCESS);
}
