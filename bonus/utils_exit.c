/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:03:22 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/31 15:03:45 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_ok(t_data *data, void *ptr)
{
	multiply_clear(data, ptr);
	write(1, "OK\n", 3);
	exit(EXIT_SUCCESS);
}

void	exit_ko(t_data *data, void *ptr)
{
	multiply_clear(data, ptr);
	write(1, "KO\n", 3);
	exit(EXIT_SUCCESS);
}

void	exit_error(t_data *data, void *ptr)
{
	multiply_clear(data, ptr);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
