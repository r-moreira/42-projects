#include <stdio.h>
#include "../../includes/ft_printf_bonus.h"

int ft_printf(const char *format, ...);

static void check_return(int ret, int ret42)
{
	if (ret == ret42)
		printf("---- Return OK ----\n");
	else
		printf("---- Return error. libc ret = %d, libft ret = %d ----\n", ret, ret42);
}

int main(void)
{
	int ret1;
	int ret2;

	printf("---- Line = %d -> Print multiple conversions test ----\n", __LINE__);
	ret1 = printf("This is |%c| multiple |%s| test for |%d| printf project! |%p|\n", 'a', "conversion", 42, &ret1);
	ret2 = ft_printf("This is |%c| multiple |%s| test for |%d| printf project! |%p|\n", 'a', "conversion", 42, &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print multiple conversions with width and precision test ----\n", __LINE__);
	ret1 =    printf("This is |%5.2c| multiple |%9.*s| test for |%*.5d| printf project! |%5.7p|\n", 'a', 7, "conversion", 9, 42, &ret1);
	ret2 = ft_printf("This is |%5.2c| multiple |%9.*s| test for |%*.5d| printf project! |%5.7p|\n", 'a', 7, "conversion", 9, 42, &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print multiple conversions with width, precision, zero and minus flag test ----\n", __LINE__);
	ret1 =    printf("This is |%-5.2c| multiple |%-9.*s| test for |%0*d| printf project! |%-05.7p|\n", 'a', 7, "conversion", 9, 42, &ret1);
	ret2 = ft_printf("This is |%-5.2c| multiple |%-9.*s| test for |%0*d| printf project! |%-05.7p|\n", 'a', 7, "conversion", 9, 42, &ret1);
	check_return(ret1, ret2);

	return (0);
}
