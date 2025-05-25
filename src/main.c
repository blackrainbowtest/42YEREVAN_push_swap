/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:07:30 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/25 01:21:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_stack(t_stack *stack, char name)
{
	t_stack	*current = stack;

	printf("Stack %c:\n", name);
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

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
	else if (data->size_a <= 50)
		middle_sort(data);
	else if (data->size_a <= 500)
		chunk_sort(data);
	else
		radix_sorting(data);
	// print_stack(data->a, 'A');
	// print_stack(data->b, 'B');
	ft_exit_success(data, NULL);
	return (EXIT_SUCCESS);
}
