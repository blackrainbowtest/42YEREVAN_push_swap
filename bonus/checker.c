/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:50:19 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/30 00:17:02 by root             ###   ########.fr       */
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

static void	print_stack(t_stack *stack)
{
    t_stack *tmp = stack;
    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

static void	data_processing(t_data *data, char *cmd)
{
	if (!ft_strcmp(cmd, "sa\n"))
		sa(data, 0);
	else if (!ft_strcmp(cmd, "sb\n"))
		sa(data, 0);
	else
		exit_error(data, cmd);
}

int main(int argc, char **argv)
{
	t_data  *data;
	char	*line;

	if (argc < 2)
		  exit_error(NULL, NULL);
	data = malloc(sizeof(t_data));
	if (!data)
		  exit_error(NULL, NULL);
	init_data(data);
	  parse_and_fill(data, argc, argv);
	print_stack(data->a);
	while ((line = get_next_line(0)))
	{
		data_processing(data, line);
		free(line);
	}
	if (is_sorted(data->a) && data->size_b == 0)
		exit_ok(data, NULL);
	else
		exit_ko(data, NULL);
	return (0);
}
