/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:07:51 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/11 14:54:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	**ft_get_all_values(int argc, char **argv)
{
	char	**all_values;
	int		i;

	if (argc == 2)
	{
		all_values = ft_split(argv[1], ' ');
		if (!all_values)
			return (NULL);
	}
	else
	{
		all_values = malloc(sizeof(char *) * (argc));
		if (!all_values)
			return (NULL);
		i = 1;
		while (i < argc)
		{
			all_values[i - 1] = ft_strdup(argv[i]);
			i++;
		}
		all_values[argc - 1] = NULL;
	}
	return (all_values);
}

/*
** some info here soon
*/
void	parse_and_fill(t_data *data, int argc, char **argv)
{
	char	**unchecked_values;
	int		*values;
	int		*sorted_values;

	unchecked_values = ft_get_all_values(argc, argv);
	if (!unchecked_values)
		ft_exit_error(data, NULL);
	values = ft_check_values(unchecked_values, data);
	ft_free(unchecked_values);	
	sorted_values = copy_and_sort(values, data->max_size);
	if (!sorted_values)
		ft_exit_error(data, values);
	fill_stack_a(data, values, sorted_values);
	free(sorted_values);
	free(values);
}