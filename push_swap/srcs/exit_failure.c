#include "../includes/push_swap.h"

void	exit_failure(char *info)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(info, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
