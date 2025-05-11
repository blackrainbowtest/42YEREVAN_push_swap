/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:07:30 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/11 19:25:05 by root             ###   ########.fr       */
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
	t_stack *tmp = data->a;
	while (tmp)
	{
		printf("Value: %d, Index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	printf("Stack a is empty\n");
	ft_exit_success(data, NULL);
	return (EXIT_SUCCESS);
}

