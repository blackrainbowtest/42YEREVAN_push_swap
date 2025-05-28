#include "checker.h"

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