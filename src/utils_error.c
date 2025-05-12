/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:08:06 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/12 18:54:22 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_exit_error(t_data *data, void *ptr)
{
	if (ptr)
		free(ptr);
	if (data)
	{
		if (data->a)
			ft_free_stack(&data->a);
		if (data->b)
			ft_free_stack(&data->b);
		free(data);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_exit_success(t_data *data, void *ptr)
{
	if (ptr)
		free(ptr);
	if (data)
	{
		if (data->a)
			ft_free_stack(&data->a);
		if (data->b)
			ft_free_stack(&data->b);
		free(data);
	}
	exit(EXIT_SUCCESS);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

char	**ft_free(char **split)
{
	size_t	i;

	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}
