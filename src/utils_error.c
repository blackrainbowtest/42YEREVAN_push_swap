/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:08:06 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/07 18:55:19 by aramarak         ###   ########.fr       */
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
void	ft_exit_error_str(t_data *data, void *ptr)
{
	if (ptr)
		ft_free_any(ptr, 0);
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
		ft_free_any(ptr, 1);
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
		ft_free_any(ptr, 1);
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
 * @brief Frees memory allocated for a pointer or an array of pointers.
 * 
 * This function checks the type of the pointer:
 * 
 * @param ptr Pointer to the memory to be freed.
 * @param type Type of the pointer: 1 for a single pointer, 2 for an array of pointers.
 * 
 * @return Returns NULL after freeing the memory.
 * 
 * @note If `ptr` is NULL or points to NULL, it does nothing and returns NULL.
 */
void	*ft_free_any(void **ptr, int type)
{
	size_t	i;

	if (!ptr || !*ptr)
		return (NULL);
	if (type == 1)
	{
		free(*ptr);
	}
	else
	{
		i = 0;
		while (((char **)*ptr)[i])
		{
			free(((char **)*ptr)[i]);
			i++;
		}
		free(*ptr);
	}
	return (NULL);
}
