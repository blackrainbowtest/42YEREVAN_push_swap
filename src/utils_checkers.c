/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:55:53 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/07 23:22:34 by aramarak         ###   ########.fr       */
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
		ft_free_char(values);
		ft_exit_error(data, int_values);
	}
	while (values[ind][i])
	{
		if (values[ind][i] < '0' || values[ind][i] > '9')
		{
			ft_free_char(values);
			ft_exit_error(data, int_values);
		}
		i++;
	}
}

static int	atoi_safe(const char *str, int *value)
{
	long	res;
	int		si;

	res = 0;
	si = 1;
	if (ft_strlen(str) > 11)
		return (0);
	while (*str == ' ' || ((*str >= 9) && (*str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			si *= -1;
	if (!*str)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		if ((si == 1 && res > INT_MAX) || (si == -1 && (-res) < INT_MIN))
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
	*value = (int)(res * si);
	return (1);
}

int	*ft_check_values(char **u_v, t_data *data)
{
	int	*int_values;
	int	i;
	int	len;

	len = ft_arrlen(u_v);
	int_values = malloc(sizeof(int) * (len));
	if (!int_values)
		ft_exit_error(data, u_v);
	i = 0;
	while (i < len)
	{
		ft_only_digits(u_v, data, i, int_values);
		if (!atoi_safe(u_v[i], &int_values[i]) || !is_valint(int_values[i]))
		{
			ft_free_char(u_v);
			ft_exit_error(data, int_values);
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
