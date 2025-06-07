/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:03:19 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/07 20:45:39 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_only_digits(char **values, t_data *data, int ind)
{
	int	i;

	i = 0;
	if (values[ind][i] == '-' || values[ind][i] == '+')
		i++;
	if (!values[ind][i])
	{
		ft_free(values);
		exit_error(data, NULL);
	}
	while (values[ind][i])
	{
		if (values[ind][i] < '0' || values[ind][i] > '9')
		{
			ft_free(values);
			exit_error(data, NULL);
		}
		i++;
	}
}

static int	atoi_safe(const char *str, int *value)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || ((*str >= 9) && (*str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	if (!*str)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (-result) < INT_MIN))
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
	*value = (int)(result * sign);
	return (1);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	*ft_check_values(char **unchecked_values, t_data *data)
{
	int	*int_values;
	int	i;
	int	len;

	len = ft_arrlen(unchecked_values);
	int_values = malloc(sizeof(int) * (len));
	if (!int_values)
		exit_error(data, unchecked_values);
	i = 0;
	while (i < len)
	{
		ft_only_digits(unchecked_values, data, i);
		if (!atoi_safe(unchecked_values[i], &int_values[i])
			|| !is_valint(int_values[i]))
		{
			free(int_values);
			exit_error(data, unchecked_values);
		}
		i++;
	}
	data->max_size = len;
	data->size_a = len;
	return (int_values);
}

int	ft_arrlen(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}
