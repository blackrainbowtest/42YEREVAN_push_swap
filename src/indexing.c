/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:54:00 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/19 21:05:49 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * @brief Copies the source array and sorts it in ascending order.
 * 
 * This function allocates memory for a new array, copies the elements from
 * the source array, and then sorts the new array using the bubble sort
 * algorithm.
 * 
 * @param src The source array to be copied and sorted.
 * @param len The length of the source array.
 * 
 * @return A pointer to the sorted array, or NULL if memory allocation fails.
 */
int	*copy_and_sort(int *src, int len)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * len);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sorted[i] = src[i];
		i++;
	}
	bubble_sort(sorted, len);
	return (sorted);
}

/**
 * @brief Sorts an array of integers using the bubble sort algorithm.
 * 
 * This function sorts the input array in ascending order using the bubble
 * sort algorithm.
 * 
 * @param arr The array to be sorted.
 * @param len The length of the array.
 */
void	bubble_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	is_sorted;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		is_sorted = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				is_sorted = 1;
			}
			j++;
		}
		if (!is_sorted)
			break ;
		i++;
	}
}

/**
 * @brief Finds the index of a value in a sorted array.
 * 
 * This function searches for the specified value in the sorted array
 * and returns its index. If the value is not found, it returns -1.
 * 
 * @param arr The sorted array to search in.
 * @param len The length of the sorted array.
 * @param value The value to search for.
 * 
 * @return The index of the value in the sorted array, or -1 if not found.
 */
int	find_index(int *arr, int len, int value)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Finds the next direction for neighbor the given index in the sorted array.
 * 
 * This function counts the number of elements in the original array that are
 * greater than the value at the specified index in the sorted array.
 * 
 * @param arr The list of original array of values.
 * @param i The index of the current element in the original array.
 * @param index The index of the current element in the sorted array.
 * 
 * @note I need to find sorted[index + 1] in values array and if values index
 * is less than i i need return -1 else 1 and 0 if dont find.
 */
int	find_next_direction(t_arrays *arr, int i, int index)
{
	int	next_value_index;

	if (index + 1 >= arr->size)
		return (0);
	next_value_index = find_index(arr->values, arr->size, arr->sorted[index + 1]);
	if (next_value_index == -1)
		return (0);
	if (next_value_index > i)
		return (1);
	else
		return (-1);
}