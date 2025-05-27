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
}