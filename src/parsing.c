/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:07:51 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/10 14:07:54 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

int	ft_arrlen(char **arr)
{
	int	len = 0;

	while (arr[len])
		len++;
	return (len);
}

int	*ft_check_values(char **values, t_data *data)
{
	int	*int_values;
	int	i;
	int len;

	len = ft_arrlen(values);
	int_values = malloc(sizeof(int) * (len + 1));
	printf("len = %d\n", len);
	if (!int_values)
		return (NULL);
	i = 0;
	while (i < data->max_size)
	{
		int_values[i] = ft_atoi(values[i]);
		if (int_values[i] == INT_MAX || int_values[i] == INT_MIN)
		{
			free(int_values);
			return (NULL);
		}
		i++;
	}
	int_values[i] = -1;
	return (int_values);
}

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

	unchecked_values = ft_get_all_values(argc, argv);
	if (!unchecked_values)
		ft_exit_error(data, NULL);
	values = ft_check_values(unchecked_values, data);
	if (!values)
		ft_exit_error(data, unchecked_values);
	for (int i = 0; i < data->max_size; i++)
	{
		printf("%d ", values[i]);
	}
	data->max_size = argc - 1;
	ft_free(unchecked_values);
	free(values);
}