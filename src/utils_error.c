/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:08:06 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/18 16:42:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * @brief Prints an error message and exits the program with failure.
 *
 * Writes "Error" to the standard error output and terminates the program
 * with an EXIT_FAILURE status. Intended for generic fatal error handling.
 *
 * @return This function does not return; it terminates the program.
 */
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/**
 * @brief Exits the program with failure, freeing all allocated memory.
 *
 * This function frees the memory associated with the stack `a`, stack `b`,
 * and the optional pointer `ptr` if they exist. It then frees the `data`
 * structure itself and exits the program with a failure status.
 *
 * @param data Pointer to the `t_data` structure containing stack information.
 * @param ptr Optional pointer to be freed before exiting (can be NULL).
 *
 * @return This function does not return; it terminates the program.
 */
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

/**
 * @brief Exits the program successfully, freeing all allocated memory.
 *
 * This function frees the memory associated with the stack `a`, stack `b`,
 * and the optional pointer `ptr` if they exist. It then frees the `data`
 * structure itself and exits the program with a success status.
 *
 * @param data Pointer to the `t_data` structure containing stack information.
 * @param ptr Optional pointer to be freed before exiting (can be NULL).
 *
 * @return This function does not return; it terminates the program.
 */
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

/**
 * @brief Frees all nodes in a linked list stack.
 *
 * Iterates through the linked list pointed to by `stack`,
 * freeing each node and setting the pointer to NULL.
 *
 * @param stack Double pointer to the head of the stack to be freed.
 */
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

/**
 * @brief Frees a dynamically allocated array of strings.
 *
 * Iterates through a NULL-terminated array of strings, freeing each string,
 * then frees the array itself. Returns NULL for convenience.
 *
 * @param split The array of strings to be freed.
 * @return NULL (can be used to reset the pointer after freeing).
 */
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
