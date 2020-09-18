#include "../includes/ft_printf.h"
#include <stdio.h>

//This function return the padding number instead of printing the padding on the screen
static int	ft_print_string_width(t_conversion tools, int len)
{
	int		pad_len;
	int		padding_count = 0; //The value of this variable must be equal to the expected padding valuet.

	pad_len = tools.opts.width - len;
	while (pad_len--)
		padding_count++; //ft_putchar_fd(' ', 1); --> original function line.
	return (padding_count); //Only for tests
}
static int	TEST_ft_print_string_width()
{
	t_conversion	tools;

	tools.opts.width = 12;
	if
	(
		ft_print_string_width(tools, 4) == 8 &&
		ft_print_string_width(tools, 1) == 11 &&
		ft_print_string_width(tools, 11) == 1
	)
		return (1);
	return (0);
}

int			main(void)
{

	if (TEST_ft_print_string_width() /*&& TEST_ft_print_number_width()*/)
		printf("ft_print_width --> OK\n");
	else
		printf("ft_print_width --> FAILED\n");

	return (0);
}
