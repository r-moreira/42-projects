#include "../includes/ft_printf_bonus.h"
#include <stdio.h>

static int	TEST_ft_get_output_len()
{
	t_conversion tools;
	char		*str = "this is a test";
	int			len;
	int			test_result;
	int			test_result2;

	test_result = 0;
	test_result2 = 0;

	len = ft_strlen(str);
	tools.opts.precision = 5;
	if (len == ft_get_output_len(str, tools)) //In this case, the function needs to return the string length
		test_result = 1;

	tools.opts.precision = 0;
	if (!ft_get_output_len("0", tools)) //Special case where precision = 0 and the str is "0", the function needs to return 0
		test_result2 = 1;

	return (test_result * test_result2);
}

int			main(void)
{
	if (TEST_ft_get_output_len())
		printf("ft_get_output_len --> OK\n");
	else
		printf("ft_get_output_len --> FAILED\n");
	return (0);
}
