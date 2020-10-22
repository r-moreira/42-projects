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


// =========== Signed integer tests ==============

static void	signed_int_only_conversion_test()
{
	int		ret1;
	int		ret2;

	printf("---- Line = %d -> Print only zero signed integer conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%d| signed integer test!!\n", 0);
	ret2 = ft_printf("This is a |%d| signed integer test!!\n", 0);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print only positive signed integer conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%d| signed integer test!!\n", 4);
	ret2 = ft_printf("This is a |%d| signed integer test!!\n", 4);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print only negative signed integer conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%d| signed integer test!!\n", -42424242);
	ret2 = ft_printf("This is a |%d| signed integer test!!\n", -42424242);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print MAX signed integer value test ----\n", __LINE__);
	ret1 =    printf("This is a |%d| signed integer test!!\n", 2147483647);
	ret2 = ft_printf("This is a |%d| signed integer test!!\n", 2147483647);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print MIN signed integer value test ----\n", __LINE__);
	ret1 =    printf("This is a |%d| signed integer test!!\n", -2147483648);
	ret2 = ft_printf("This is a |%d| signed integer test!!\n", -2147483648);
	check_return(ret1, ret2);
}

static void	signed_int_width_options_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print signed integer with width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%9d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%9d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with width = 1 test ----\n", __LINE__);
	ret1 =    printf("This is a |%1d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%1d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with negative width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-9i| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%-9i| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*d| signed integer test!!\n", 9, 42);
	ret2 = ft_printf("This is a |%*d| signed integer test!!\n", 9, 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*i| signed integer test!!\n", -9, 42);
	ret2 = ft_printf("This is a |%*i| signed integer test!!\n", -9, 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with minus flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-9d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%-9d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with minus flag and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-*d| signed integer test!!\n", 9, 42);
	ret2 = ft_printf("This is a |%-*d| signed integer test!!\n", 9, 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with minus flag and negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-*i| signed integer test!!\n", -9, 42);
	ret2 = ft_printf("This is a |%-*i| signed integer test!!\n", -9, 42);
	check_return(ret1, ret2);


	printf("\n---- Line = %d -> Print negative signed integer with width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%9d| signed integer test!!\n", -42);
	ret2 = ft_printf("This is a |%9d| signed integer test!!\n", -42);
	check_return(ret1, ret2);
}

static void	signed_int_precision_options_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print signed integer with precision < len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.1d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%.1d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with precision > len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.5i| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%.5i| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with precision = len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.2d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%.2d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.*d| signed integer test!!\n", 7, 42);
	ret2 = ft_printf("This is a |%.*d| signed integer test!!\n", 7, 42);
	check_return(ret1, ret2);


	printf("\n---- Line = %d -> Print negative signed integer with precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.5d| signed integer test!!\n", -42);
	ret2 = ft_printf("This is a |%.5d| signed integer test!!\n", -42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print negative signed integer with precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.*d| signed integer test!!\n", 7, -42);
	ret2 = ft_printf("This is a |%.*d| signed integer test!!\n", 7, -42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with negative precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.*i| signed integer test!!\n", -7, 42);
	ret2 = ft_printf("This is a |%.*i| signed integer test!!\n", -7, 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with only dot precision test ----\n", __LINE__);
	ret1 =    printf("This is a |%.d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%.d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer '0' with only dot precision test ----\n", __LINE__);
	ret1 =    printf("This is a |%.i| signed integer test!!\n", 0);
	ret2 = ft_printf("This is a |%.i| signed integer test!!\n", 0);
	check_return(ret1, ret2);
}

static void	signed_int_width_precision_options_test()
{
	int		ret1;
	int		ret2;


	printf("\n---- Line = %d -> Print signed integer with width (digits option) = precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%7.7d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%7.7d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with width (star option) < precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*.7d| signed integer test!!\n", 5, 42);
	ret2 = ft_printf("This is a |%*.7d| signed integer test!!\n", 5, 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with width (digits option) > precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%7.*i| signed integer test!!\n", 5, 42);
	ret2 = ft_printf("This is a |%7.*i| signed integer test!!\n", 5, 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with width (star option) > precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*.*d| signed integer test!!\n", 12, 7, 42);
	ret2 = ft_printf("This is a |%*.*d| signed integer test!!\n", 12, 7, 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with only dot precision and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%6.d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%6.d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer '0' with only dot precision and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%5.i| signed integer test!!\n", 0);
	ret2 = ft_printf("This is a |%5.i| signed integer test!!\n", 0);
	check_return(ret1, ret2);
}

static void signed_int_zero_flag_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print signed integer with only zero flag and conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%0d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%0d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with zero flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%010d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%010d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with zero flag and width = len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%02i| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%02i| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with zero flag, minus flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0-7d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%0-7d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with minus flag, zero flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-05d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%-05d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with zero flag and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*d| signed integer test!!\n", 7, 42);
	ret2 = ft_printf("This is a |%0*d| signed integer test!!\n", 7, 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with zero flag and negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*d| signed integer test!!\n", -7, 42);
	ret2 = ft_printf("This is a |%0*d| signed integer test!!\n", -7, 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with zero flag, width (digits option) and precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%010.6d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%010.6d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with zero flag, negative width (star option) and precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*.7d| signed integer test!!\n", -9, 42);
	ret2 = ft_printf("This is a |%0*.7d| signed integer test!!\n", -9, 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with zero flag, width (digits option) and negative precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%05.*d| signed integer test!!\n", -8, 42);
	ret2 = ft_printf("This is a |%05.*d| signed integer test!!\n", -8, 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with zero flag, negative width (star option) and negative precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*.*d| signed integer test!!\n", -12, -9, 42);
	ret2 = ft_printf("This is a |%0*.*d| signed integer test!!\n", -12, -9, 42);
	check_return(ret1, ret2);
}


// =========== Unsgined integer tests ==============

static void	unsigned_int_only_conversion_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print only zero unsigned integer conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%u| signed integer test!!\n", 0);
	ret2 = ft_printf("This is a |%u| signed integer test!!\n", 0);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print only unsigned integer conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%u| unsigned integer test!!\n", 7);
	ret2 = ft_printf("This is a |%u| unsigned integer test!!\n", 7);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print MAX unsigned integer value test ----\n", __LINE__);
	ret1 =    printf("This is a |%u| unsigned integer test!!\n", 4294967295);
	ret2 = ft_printf("This is a |%u| unsigned integer test!!\n", 4294967295);
	check_return(ret1, ret2);
}

static void unsigned_int_width_options_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print unsigned integer with width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%9u| unsigned integer test!!\n", 97);
	ret2 = ft_printf("This is a |%9u| unsigned integer test!!\n", 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with width = 1 test ----\n", __LINE__);
	ret1 =    printf("This is a |%1u| unsigned integer test!!\n", 97);
	ret2 = ft_printf("This is a |%1u| unsigned integer test!!\n", 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with negative width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-9u| unsigned integer test!!\n", 97);
	ret2 = ft_printf("This is a |%-9u| unsigned integer test!!\n", 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*u| unsigned integer test!!\n", 9, 97);
	ret2 = ft_printf("This is a |%*u| unsigned integer test!!\n", 9, 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*u| unsigned integer test!!\n", -9, 97);
	ret2 = ft_printf("This is a |%*u| unsigned integer test!!\n", -9, 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with minus flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-9u| unsigned integer test!!\n", 97);
	ret2 = ft_printf("This is a |%-9u| unsigned integer test!!\n", 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with minus flag and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-*u| unsigned integer test!!\n", 9, 97);
	ret2 = ft_printf("This is a |%-*u| unsigned integer test!!\n", 9, 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with minus flag and negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-*u| unsigned integer test!!\n", -9, 97);
	ret2 = ft_printf("This is a |%-*u| unsigned integer test!!\n", -9, 97);
	check_return(ret1, ret2);
}

static void	unsigned_int_precision_options_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print unsigned integer with precision < len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.1u| unsigned integer test!!\n", 97);
	ret2 = ft_printf("This is a |%.1u| unsigned integer test!!\n", 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with precision > len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.5u| unsigned integer test!!\n", 97);
	ret2 = ft_printf("This is a |%.5u| unsigned integer test!!\n", 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with precision = len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.2u| unsigned integer test!!\n", 97);
	ret2 = ft_printf("This is a |%.2u| unsigned integer test!!\n", 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.*u| unsigned integer test!!\n", 7, 97);
	ret2 = ft_printf("This is a |%.*u| unsigned integer test!!\n", 7, 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with negative precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.*u| unsigned integer test!!\n", -7, 97);
	ret2 = ft_printf("This is a |%.*u| unsigned integer test!!\n", -7, 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with only dot precision test ----\n", __LINE__);
	ret1 =    printf("This is a |%.u| unsigned integer test!!\n", 42);
	ret2 = ft_printf("This is a |%.u| unsigned integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer '0' with only dot precision test ----\n", __LINE__);
	ret1 =    printf("This is a |%.u| unsigned integer test!!\n", 0);
	ret2 = ft_printf("This is a |%.u| unsigned integer test!!\n", 0);
	check_return(ret1, ret2);
}

static void	unsigned_int_width_precision_options_test()
{
	int		ret1;
	int		ret2;


	printf("\n---- Line = %d -> Print unsigned integer with width (digits option) = precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%7.7u| unsigned integer test!!\n", 97);
	ret2 = ft_printf("This is a |%7.7u| unsigned integer test!!\n", 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with width (star option) < precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*.7u| unsigned integer test!!\n", 5, 97);
	ret2 = ft_printf("This is a |%*.7u| unsigned integer test!!\n", 5, 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with width (digits option) > precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%7.*u| unsigned integer test!!\n", 5, 97);
	ret2 = ft_printf("This is a |%7.*u| unsigned integer test!!\n", 5, 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with width (star option) > precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*.*u| unsigned integer test!!\n", 12, 7, 97);
	ret2 = ft_printf("This is a |%*.*u| unsigned integer test!!\n", 12, 7, 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with only dot precision and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%6.u| unsigned integer test!!\n", 42);
	ret2 = ft_printf("This is a |%6.u| unsigned integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer '0' with only dot precision and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%5.u| unsigned integer test!!\n", 0);
	ret2 = ft_printf("This is a |%5.u| unsigned integer test!!\n", 0);
	check_return(ret1, ret2);
}

static void unsigned_int_zero_flag_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print unsigned integer with only zero flag and conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%0u| unsigned integer test!!\n", 97);
	ret2 = ft_printf("This is a |%0u| unsigned integer test!!\n", 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with zero flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%010u| unsigned integer test!!\n", 97);
	ret2 = ft_printf("This is a |%010u| unsigned integer test!!\n", 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with zero flag and width = len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%02u| unsigned integer test!!\n", 97);
	ret2 = ft_printf("This is a |%02u| unsigned integer test!!\n", 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with zero flag, minus flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0-7u| unsigned integer test!!\n", 97);
	ret2 = ft_printf("This is a |%0-7u| unsigned integer test!!\n", 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with minus flag, zero flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-05u| unsigned integer test!!\n", 97);
	ret2 = ft_printf("This is a |%-05u| unsigned integer test!!\n", 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with zero flag and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*u| unsigned integer test!!\n", 7, 97);
	ret2 = ft_printf("This is a |%0*u| unsigned integer test!!\n", 7, 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with zero flag and negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*u| unsigned integer test!!\n", -7, 97);
	ret2 = ft_printf("This is a |%0*u| unsigned integer test!!\n", -7, 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with zero flag, width (digits option) and precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%010.6u| unsigned integer test!!\n", 97);
	ret2 = ft_printf("This is a |%010.6u| unsigned integer test!!\n", 97);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with zero flag, negative width (star option) and precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*.7u| unsigned integer test!!\n", -9, 42);
	ret2 = ft_printf("This is a |%0*.7u| unsigned integer test!!\n", -9, 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with zero flag, width (digits option) and negative precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%05.*u| unsigned integer test!!\n", -8, 42);
	ret2 = ft_printf("This is a |%05.*u| unsigned integer test!!\n", -8, 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print unsigned integer with zero flag, negative width (star option) and negative precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*.*u| unsigned integer test!!\n", -12, -9, 42);
	ret2 = ft_printf("This is a |%0*.*u| unsigned integer test!!\n", -12, -9, 42);
	check_return(ret1, ret2);
}


static void signed_int_plus_space_flags_test()
{

	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print signed integer with space flag test ----\n", __LINE__);
	ret1 =    printf("This is a |% d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |% d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with plus flag test ----\n", __LINE__);
	ret1 =    printf("This is a |%+d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |%+d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with space and plus flags test ----\n", __LINE__);
	ret1 =    printf("This is a |% +d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |% +d| signed integer test!!\n", 42);
	check_return(ret1, ret2);
}

static void	signed_int_plus_space_zero_flags_width_precision_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print signed integer with space flag and width (digits options) test ----\n", __LINE__);
	ret1 =    printf("This is a |% 7d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |% 7d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with plus flag and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%+*i| signed integer test!!\n", 10, 42);
	ret2 = ft_printf("This is a |%+*i| signed integer test!!\n", 10, 42);
	check_return(ret1, ret2);

		printf("\n---- Line = %d -> Print negative signed integer with plus flag and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%+*i| signed integer test!!\n", 10, -42);
	ret2 = ft_printf("This is a |%+*i| signed integer test!!\n", 10, -42);
	check_return(ret1, ret2);


	printf("\n---- Line = %d -> Print signed integer with space, plus flags and width (digits options) test ----\n", __LINE__);
	ret1 =    printf("This is a |% +7d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |% +7d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with space flag and precision (digits options) test ----\n", __LINE__);
	ret1 =    printf("This is a |% .7i| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |% .7i| signed integer test!!\n", 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with plus flag and precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%+.*d| signed integer test!!\n", 10, 42);
	ret2 = ft_printf("This is a |%+.*d| signed integer test!!\n", 10, 42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print negative signed integer with plus flag and precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%+.*d| signed integer test!!\n", 10, -42);
	ret2 = ft_printf("This is a |%+.*d| signed integer test!!\n", 10, -42);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print signed integer with space, plus flags and precision (digits options) test ----\n", __LINE__);
	ret1 =    printf("This is a |% +.7d| signed integer test!!\n", 42);
	ret2 = ft_printf("This is a |% +.7d| signed integer test!!\n", 42);
	check_return(ret1, ret2);

}


int		main(void)
{
	signed_int_only_conversion_test();
	signed_int_width_options_test();
	signed_int_precision_options_test();
	signed_int_width_precision_options_test();
	signed_int_zero_flag_test();
	unsigned_int_only_conversion_test();
	unsigned_int_width_options_test();
	unsigned_int_precision_options_test();
	unsigned_int_width_precision_options_test();
	unsigned_int_zero_flag_test();
	signed_int_plus_space_flags_test();
	signed_int_plus_space_zero_flags_width_precision_test();
	return (0);
}
