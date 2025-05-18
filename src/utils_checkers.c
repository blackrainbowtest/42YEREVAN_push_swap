/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:55:53 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/18 17:18:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_arrlen(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

void	ft_only_digits(char **values, t_data *data, int ind)
{
	int	i;

	i = 0;
	if (values[ind][i] == '-' || values[ind][i] == '+')
		i++;
	if (!values[ind][i])
	{
		ft_free(values);
		ft_exit_error(data, NULL);
	}
	while (values[ind][i])
	{
		if (values[ind][i] < '0' || values[ind][i] > '9')
		{
			ft_free(values);
			ft_exit_error(data, NULL);
		}
		i++;
	}
}

int	*ft_check_values(char **unchecked_values, t_data *data)
{
	int	*int_values;
	int	i;
	int	len;

	len = ft_arrlen(unchecked_values);
	int_values = malloc(sizeof(int) * (len));
	if (!int_values)
		ft_exit_error(data, unchecked_values);
	i = 0;
	while (i < len)
	{
		ft_only_digits(unchecked_values, data, i);
		int_values[i] = ft_atoi(unchecked_values[i]);
		if (int_values[i] >= INT_MAX || int_values[i] <= INT_MIN)
		{
			free(int_values);
			return (NULL);
		}
		i++;
	}
	data->max_size = len;
	data->size_a = len;
	return (int_values);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		printf("stack->value = %d\n", stack->value);
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}