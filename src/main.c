/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:07:30 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/11 14:54:42 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>


int main(int argc, char **argv)
{
	t_data	*data;
	if (argc < 2)
		ft_error();
	data = malloc(sizeof(t_data));
	if (!data)
		ft_error();
	init_data(data);
	parse_and_fill(data, argc, argv);
	// print stack	a
	while (data->a)
	{
		printf("Value: %d, Index: %d\n", data->a->value, data->a->index);
		data->a = data->a->next;
	}
	ft_exit_success(data, NULL);
	return (EXIT_SUCCESS);
}

