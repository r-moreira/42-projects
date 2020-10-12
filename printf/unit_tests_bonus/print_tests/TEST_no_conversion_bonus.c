#include <stdio.h>
#include "../../includes/ft_printf_bonus.h"

int			ft_printf(const char *format, ...);

static void check_return(int ret, int ret42)
{
	if (ret == ret42)
		printf("---- Return OK ----\n");
	else
		printf("---- Return error. libc ret = %d, libft ret = %d ----\n", ret, ret42);
}

int		main(void)
{
	int		ret1;
	int		ret2;

	printf("---- Line = %d -> Print str without conversions test ----\n", __LINE__);
	ret1 =    printf("This is a test!!\n");
	ret2 = ft_printf("This is a test!!\n");
	check_return(ret1, ret2);
	return (0);
}
