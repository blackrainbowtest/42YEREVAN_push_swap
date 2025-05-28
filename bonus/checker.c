/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:50:19 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/28 12:29:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_stack(t_stack *stack)
{
    t_stack *tmp = stack;
    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

int main(int argc, char **argv)
{
    t_data	*data;

    if (argc < 2)
		  exit_error(NULL, NULL);
    data = malloc(sizeof(t_data));
    if (!data)
		  exit_error(NULL, NULL);
    init_data(data);
	  parse_and_fill(data, argc, argv);
    print_stack(data->a);
// geet data and check actions
    if (is_sorted(data->a) && data->size_b == 0)
        exit_ok(data, NULL);
    else
        exit_ko(data, NULL);
    return (0);
}