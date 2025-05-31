/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:03:25 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/31 15:03:41 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	multiply_clear(t_data *data, void *ptr)
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
