/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:42:16 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/26 22:41:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	chunk_sort(t_data *data)
{
	int	chunk_size;
	int	chunk_count;
	int	i;

	chunk_count = (int)(data->max_size * 0.01);
	if (chunk_count < 1)
		chunk_count = 1;
	chunk_size = data->max_size / chunk_count;
	i = 0;
	while (i < chunk_count)
	{
		split_chunk(data, i, chunk_size, chunk_count);
		i++;
	}
	return_sorted_to_a(data);
	rotate_a_to_min(data);
}

void	split_chunk(t_data *data, int i, int chunk_size, int chunk_count)
{
	int	start_index;
	int	end_index;

	start_index = i * chunk_size;
	end_index = start_index + chunk_size - 1;
	if (i == chunk_count - 1)
		end_index = data->max_size - 1;
	while (still_has_elements(data->a, start_index, end_index))
	{
		if (data->a->index >= start_index && data->a->index <= end_index)
		{
			pb(data);
			if (data->b && data->b->index < (start_index + end_index) / 2)
				rb(data, 1);
		}
		else
		{
			ra(data, 1);
		}
	}
}

void	return_sorted_to_a(t_data *data)
{
	t_stack	*cheapest;
	int		cost_a;
	int		cost_b;

	while (data->size_b > 0)
	{
		calculate_costs(data);
		cheapest = find_cheapest_node(data->b);
		if (!cheapest)
			return ;
		cost_a = cheapest->cost_a;
		cost_b = cheapest->cost_b;
		move_stacks(data, cost_a, cost_b);
		pa(data);
	}
}

int	get_target_position(t_stack *a, int index_b)
{
	t_stack *current = a;
	t_stack *best = NULL;
	int best_index = __INT_MAX__;

	while (current)
	{
		if (current->index > index_b && current->index < best_index)
		{
			best_index = current->index;
			best = current;
		}
		current = current->next;
	}
	if (best)
		return get_node_position(a, best);
	return get_node_position(a, find_min_node(a));
}

void	calculate_costs(t_data *data)
{
	t_stack *b = data->b;
	int pos_b = 0;

	while (b)
	{
		b->cost_b = pos_b <= data->size_b / 2 ? pos_b : pos_b - data->size_b;
		int target_pos = get_target_position(data->a, b->index);
		b->cost_a = target_pos <= data->size_a / 2 ? target_pos : target_pos - data->size_a;
		b = b->next;
		pos_b++;
	}
}

void	move_stacks(t_data *data, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(data);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(data);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0)
	{
		ra(data, 1);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(data, 1); cost_a++;
	}
	while (cost_b > 0)
		{rb(data, 1); cost_b--;}
	while (cost_b < 0)
		{rrb(data, 1); cost_b++;}
}
