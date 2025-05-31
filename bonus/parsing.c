/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:03:14 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/31 15:03:15 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_valid_int_range(int n)
{
	return (n >= INT_MIN && n <= INT_MAX);
}

/**
* @brief Get all values from command line arguments.
*
* This function checks if the program is called with a single argument
* containing space-separated values or multiple arguments.
*
* @param argc The number of command line arguments.
* @param argv The array of command line arguments.
*
* @return A dynamically allocated array of strings containing all values,
*         or NULL if memory allocation fails.
*/
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

/**
* @brief Check if the array has duplicate values.
*
* This function iterates through the array and checks if any value appears
* more than once. If a duplicate is found, it returns 1; otherwise, it returns 0.
*
* @param arr The array of integers to check for duplicates.
* @param size The size of the array.
*
* @return 1 if duplicates are found, 0 otherwise.
*/
int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
* @brief Parse command line arguments and fill the data structure.
*
* This function retrieves all values from the command line arguments,
* checks them for validity, sorts them, and fills the stack 'a' in the
* provided data structure. It handles memory allocation and error checking.
*
* @param data The data structure to fill with parsed values.
* @param argc The number of command line arguments.
* @param argv The array of command line arguments.
*
* @return void
*/
void	parse_and_fill(t_data *data, int argc, char **argv)
{
	char	**unchecked_values;
	int		*values;
	int		*sorted_values;

	unchecked_values = ft_get_all_values(argc, argv);
	if (!unchecked_values)
		exit_error(data, NULL);
	values = ft_check_values(unchecked_values, data);
	ft_free(unchecked_values);
	if (!values)
		exit_ko(data, NULL);
	sorted_values = copy_and_sort(values, data->max_size);
	if (!sorted_values)
		exit_error(data, values);
	if (has_duplicates(values, data->max_size))
	{
		free(sorted_values);
		exit_error(data, values);
	}
	fill_stack_a(data, values, sorted_values);
	free(sorted_values);
	free(values);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}
