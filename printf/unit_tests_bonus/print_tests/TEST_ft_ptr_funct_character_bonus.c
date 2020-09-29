#include <stdio.h>
#include "../../includes/ft_printf.h"

int			ft_printf(const char *format, ...);

static void	check_return(int ret, int ret42)
{
	if (ret == ret42)
		printf("---- Return OK ----\n");
	else
		printf("---- Return error. libc ret = %d, libft ret = %d ----\n", ret, ret42);
}

static void char_only_conversion_test()
{
	int		ret1;
	int		ret2;

	printf("---- Line = %d -> Print only char conversion test ----\n", __LINE__);
	ret1 =    printf("This is %c char test!!\n", 'a');
	ret2 = ft_printf("This is %c char test!!\n", 'a');
	check_return(ret1, ret2);
}

static void	char_width_options_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print char with width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is |%5c| char test!!\n", 'a');
	ret2 = ft_printf("This is |%5c| char test!!\n", 'a');
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print char with width = 1 test ----\n", __LINE__);
	ret1 =    printf("This is |%1c| char test!!\n", 'a');
	ret2 = ft_printf("This is |%1c| char test!!\n", 'a');
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print char with negative width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is |%-5c| char test!!\n", 'a');
	ret2 = ft_printf("This is |%-5c| char test!!\n", 'a');
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print char with width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is |%*c| char test!!\n", 5, 'a');
	ret2 = ft_printf("This is |%*c| char test!!\n", 5, 'a');
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print char with negative width(star option) test ----\n", __LINE__);
	ret1 =    printf("This is |%*c| char test!!\n", -5, 'a');
	ret2 = ft_printf("This is |%*c| char test!!\n", -5, 'a');
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print char with flag minus and width (digits option) ----\n", __LINE__);
	ret1 =    printf("This is |%5c| char test!!\n", 'a');
	ret2 = ft_printf("This is |%5c| char test!!\n", 'a');
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print char with flag minus and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is |%-------*c| char test!!\n", 5, 'a');
	ret2 = ft_printf("This is |%-------*c| char test!!\n", 5, 'a');
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print char with minus flag and negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is |%-*c| char test!!\n", -5, 'a');
	ret2 = ft_printf("This is |%-*c| char test!!\n", -5, 'a');
	check_return(ret1, ret2);
}

int		main(void)
{
	char_only_conversion_test();
	char_width_options_test();

	return (0);
}
