#include <stdio.h>
#include "../../includes/ft_printf_bonus.h"

int			ft_printf(const char *format, ...);

static void	check_return(int ret, int ret42)
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

	printf("---- Line = %d -> Print only double percent conversion test ----\n", __LINE__);
	ret1 =    printf("This is |%%| char test!!\n", 'a');
	ret2 = ft_printf("This is |%%| char test!!\n", 'a');
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print double percent conversion and char conversion with one argument test ----\n", __LINE__);
	ret1 =    printf("This is |%%| |%c| char test!!\n", 'a');
	ret2 = ft_printf("This is |%%| |%c| char test!!\n", 'a');
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print double percent conversion and char conversion with two arguments test ----\n", __LINE__);
	ret1 =    printf("This is |%%| |%d| char test!!\n", 42, 'a');
	ret2 = ft_printf("This is |%%| |%d| char test!!\n", 42, 'a');
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print only double percent conversion test ----\n", __LINE__);
	ret1 =    printf("This is |%%| char test!!\n", 'a');
	ret2 = ft_printf("This is |%%| char test!!\n", 'a');
	check_return(ret1, ret2);

	//Fazer com width , precision, width + precision, flag - e 0
	printf("\n---- Line = %d -> Print double percent conversion with width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is |%42%| char test!!\n");
	ret2 = ft_printf("This is |%42%| char test!!\n");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print double percent conversion with precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is |%.42%| char test!!\n");
	ret2 = ft_printf("This is |%.42%| char test!!\n");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print double percent conversion zero flag, minus flag, width (digits option) and precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is |%-042.*%| char test!!\n", 42);
	ret2 = ft_printf("This is |%-042.*%| char test!!\n", 42);
	check_return(ret1, ret2);
	return (0);
}
