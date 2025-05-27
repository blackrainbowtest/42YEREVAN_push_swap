/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:50:19 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/28 00:16:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main()
{
    t_data	*data;

    if (argc < 2)
		exit_error(NULL, NULL);
    data = malloc(sizeof(t_data));
    if (!data)
		exit_error(NULL, NULL);
// geet data and check actions
    if (is_sorted(data->a) && data->size_b == 0)
        exit_ok(data, NULL);
    else
        exit_ko(data, NULL);
    return (0);
}