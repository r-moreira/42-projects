#include "../includes/ft_printf.h"
#include <stdio.h>

static int	TEST_ft_nbr_to_str()
{
	t_arg_types		arg;
	t_conversion	tools;
	char			*expected_str;
	int				test_result;

	test_result = 0;

	tools.conv = 'd';
	arg._int = -2147483648;
	expected_str = "-2147483648";
	if (!ft_strncmp(ft_nbr_to_str(DECIMAL, arg, tools), expected_str, ft_strlen(expected_str)))
		test_result += 1;

	tools.conv = 'i';
	arg._int = 2147483647;
	expected_str = "2147483647";
	if (!ft_strncmp(ft_nbr_to_str(DECIMAL, arg, tools), expected_str, ft_strlen(expected_str)))
		test_result += 1;

	tools.conv = 'u';
	arg._uint = 4294967295;
	expected_str = "4294967295";
	if (!ft_strncmp(ft_nbr_to_str(DECIMAL, arg, tools), expected_str, ft_strlen(expected_str)))
		test_result += 1;

	tools.conv = 'x';
	arg._uint = 429496;
	expected_str = "68db8";
	if (!ft_strncmp(ft_nbr_to_str(LOWER_HEXA, arg, tools), expected_str, ft_strlen(expected_str)))
		test_result += 1;

	tools.conv = 'X';
	arg._uint = 4294967295;
	expected_str = "FFFFFFFF";
	if (!ft_strncmp(ft_nbr_to_str(UPPER_HEXA, arg, tools), expected_str, ft_strlen(expected_str)))
		test_result += 1;

	tools.conv = 'p';
	arg._luint = 18446744073709551615ul;
	expected_str = "ffffffffffffffff";
	if (!ft_strncmp(ft_nbr_to_str(LOWER_HEXA, arg, tools), expected_str, ft_strlen(expected_str)))
		test_result += 1;

	return (test_result == 6);
}

int			main(void)
{
	if (TEST_ft_nbr_to_str())
		printf("ft_nbr_to_str --> OK\n");
	else
		printf("ft_nbr_to_str --> FAILED\n");
	return (0);
}
