/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:55:53 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/07 18:55:12 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * @brief Counts the number of elements in a null-terminated array of strings.
 * 
 * @param arr The array of strings to count.
 * 
 * @return The number of strings in the array.
 */
int	ft_arrlen(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

void	ft_only_digits(char **values, t_data *data, int ind, int *int_values)
{
	int	i;

	i = 0;
	if (values[ind][i] == '-' || values[ind][i] == '+')
		i++;
	if (!values[ind][i])
	{
		ft_free_any((void **)&values, 1);
		ft_exit_error(data, int_values);
	}
	while (values[ind][i])
	{
		if (values[ind][i] < '0' || values[ind][i] > '9')
		{
			ft_free_any((void **)&values, 1);
			ft_exit_error(data, int_values);
		}
		i++;
	}
}

static int	ft_atoi_safe(const char *str, int *value)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (ft_strlen(str) > 11)
		return (0);
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
		ft_only_digits(unchecked_values, data, i, int_values);
		if (!ft_atoi_safe(unchecked_values[i], &int_values[i])
			|| !is_valid_int_range(int_values[i]))
		{
			ft_free_any((void **)&int_values, 1);
			ft_exit_error(data, unchecked_values);
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
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
