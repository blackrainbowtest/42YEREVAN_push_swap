/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:50:19 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/31 15:58:17 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void	data_processing(t_data *data, char *cmd)
{
	if (!ft_strcmp(cmd, "sa\n"))
		sa(data, 0);
	else if (!ft_strcmp(cmd, "sb\n"))
		sb(data, 0);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(data, 0);
	else if (!ft_strcmp(cmd, "ra\n"))
		ra(data, 0);
	else if (!ft_strcmp(cmd, "rb\n"))
		rb(data, 0);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(data, 0);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra(data, 0);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rrb(data, 0);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(data, 0);
	else if (!ft_strcmp(cmd, "pa\n"))
		pa(data, 0);
	else if (!ft_strcmp(cmd, "pb\n"))
		pb(data, 0);
	else
		exit_error(data, cmd);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*line;

	if (argc < 2)
		exit_error(NULL, NULL);
	data = malloc(sizeof(t_data));
	if (!data)
		exit_error(NULL, NULL);
	init_data(data);
	parse_and_fill(data, argc, argv);
	line = get_next_line(0);
	while (line)
	{
		data_processing(data, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(data->a) && data->size_b == 0)
		exit_ok(data, NULL);
	else
		exit_ko(data, NULL);
	return (0);
}
