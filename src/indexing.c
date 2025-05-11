#include "pushswap.h"

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
			break;
		i++;
	}
}

int	find_index(int *sorted, int len, int value)
{
	int	i = 0;
	while (i < len)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}