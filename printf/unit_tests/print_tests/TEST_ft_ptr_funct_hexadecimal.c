#include <stdio.h>
#include "../../includes/ft_printf.h"

int		ft_printf(const char *format, ...);

void	check_return(int ret, int ret42)
{
	if (ret == ret42)
		printf("---- Return OK ----\n");
	else
		printf("---- Return error. libc ret = %d, libft ret = %d ----\n", ret, ret42);
}

static void	hexadecimal_only_conversion_test()
{
	int		ret1;
	int		ret2;

	printf("---- Line = %d -> Print only zero lower hexadecimal conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%x| lower hexa test!!\n", 0);
	ret2 = ft_printf("This is a |%x| lower hexa test!!\n", 0);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%x| lower hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%x| lower hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print MAX lower hexadecimal value test ----\n", __LINE__);
	ret1 =    printf("This is a |%x| lower hexa test!!\n", 4294967295);
	ret2 = ft_printf("This is a |%x| lower hexa test!!\n", 4294967295);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print only zero upper hexadecimal conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%X| upper hexa test!!\n", 0);
	ret2 = ft_printf("This is a |%X| upper hexa test!!\n", 0);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexadecimal conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%X| upper hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%X| upper hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print MAX upper hexadecimal value test ----\n", __LINE__);
	ret1 =    printf("This is a |%X| upper hexa test!!\n", 4294967295);
	ret2 = ft_printf("This is a |%X| upper hexa test!!\n", 4294967295);
	check_return(ret1, ret2);
}

static void	hexadecimal_width_options_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print lower hexadecimal with width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%9x| lower hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%9x| lower hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexadecimal with width = 1 test ----\n", __LINE__);
	ret1 =    printf("This is a |%1X| upper hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%1X| upper hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexadecimal with negative width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-9X| upper hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%-9X| upper hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal with width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*x| lower hexa test!!\n", 9, 999999);
	ret2 = ft_printf("This is a |%*x| lower hexa test!!\n", 9, 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal with negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*x| lower hexa test!!\n", -9, 999999);
	ret2 = ft_printf("This is a |%*x| lower hexa test!!\n", -9, 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal with minus flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-9x| lower hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%-9x| lower hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexadecimal with minus flag and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-*X| upper hexa test!!\n", 9, 999999);
	ret2 = ft_printf("This is a |%-*X| upper hexa test!!\n", 9, 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal with minus flag and negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-*x| lower hexa test!!\n", -9, 999999);
	ret2 = ft_printf("This is a |%-*x| lower hexa test!!\n", -9, 999999);
	check_return(ret1, ret2);
}

static void	hexadecimal_precision_options_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print upper hexadecimal with precision < len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.1X| upper hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%.1X| upper hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal with precision > len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.9x| lower hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%.9x| lower hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexadecimal with precision = len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.5X| upper hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%.5X| upper hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal with precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.*x| lower hexa test!!\n", 7, 999999);
	ret2 = ft_printf("This is a |%.*x| lower hexa test!!\n", 7, 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexadecimal with negative precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.*X| upper hexa test!!\n", -7, 999999);
	ret2 = ft_printf("This is a |%.*X| upper hexa test!!\n", -7, 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal with only dot precision test ----\n", __LINE__);
	ret1 =    printf("This is a |%.x| lower hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%.x| lower hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexadecimal '0' with only dot precision test ----\n", __LINE__);
	ret1 =    printf("This is a |%.X| upper hexa test!!\n", 0);
	ret2 = ft_printf("This is a |%.X| upper hexa test!!\n", 0);
	check_return(ret1, ret2);
}

static void	hexadecimal_width_precision_options_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print lower hexadecimal with width (digits option) = precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%8.8x| lower hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%8.8x| lower hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexadecimal with width (star option) < precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*.9X| upper hexa test!!\n", 7, 999999);
	ret2 = ft_printf("This is a |%*.9X| upper hexa test!!\n", 7, 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal with width (digits option) > precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%9.*x| lower hexa test!!\n", 7, 999999);
	ret2 = ft_printf("This is a |%9.*x| lower hexa test!!\n", 7, 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexadecimal with width (star option) > precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*.*X| upper hexa test!!\n", 12, 7, 999999);
	ret2 = ft_printf("This is a |%*.*X| upper hexa test!!\n", 12, 7, 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal with only dot precision and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%8.x| lower hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%8.x| lower hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexa '0' with only dot precision and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%7.X| upper hexa test!!\n", 0);
	ret2 = ft_printf("This is a |%7.X| upper hexa test!!\n", 0);
	check_return(ret1, ret2);
}

static void hexadecimal_zero_flag_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print upper hexadecimal with only zero flag and conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%0X| upper hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%0X| upper hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal with zero flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%012x| lower hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%012x| lower hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexadecimal with zero flag and width = len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%05X| upper hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%05X| upper hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal with zero flag, minus flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0-9x| lower hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%0-9x| lower hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal with minus flag, zero flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-08x| lower hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%-08x| lower hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal with zero flag and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*x| lower hexa test!!\n", 9, 999999);
	ret2 = ft_printf("This is a |%0*x| lower hexa test!!\n", 9, 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexadecimal with zero flag and negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*X| upper hexa test!!\n", -8, 999999);
	ret2 = ft_printf("This is a |%0*X| upper hexa test!!\n", -8, 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexadecimal with zero flag, width (digits option) and precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%012.7X| upper hexa test!!\n", 999999);
	ret2 = ft_printf("This is a |%012.7X| upper hexa test!!\n", 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexadecimal with zero flag, negative width (star option) and precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*.8X| upper hexa test!!\n", -10, 999999);
	ret2 = ft_printf("This is a |%0*.8X| upper hexa test!!\n", -10, 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print lower hexadecimal with zero flag, width (digits option) and negative precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%012.*x| lower hexa test!!\n", -8, 999999);
	ret2 = ft_printf("This is a |%012.*x| lower hexa test!!\n", -8, 999999);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print upper hexadecimal with zero flag, negative width (star option) and negative precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*.*X| upper hexa test!!\n", -12, -9, 999999);
	ret2 = ft_printf("This is a |%0*.*X| upper hexa test!!\n", -12, -9, 999999);
	check_return(ret1, ret2);
}

int		main(void)
{
	hexadecimal_only_conversion_test();
	hexadecimal_width_options_test();
	hexadecimal_precision_options_test();
	hexadecimal_width_precision_options_test();
	hexadecimal_zero_flag_test();
	return (0);
}
