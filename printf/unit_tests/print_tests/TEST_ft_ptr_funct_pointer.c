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


static void	pointer_only_conversion_test()
{
	int		ret1;
	int		ret2;

	printf("---- Line = %d -> Print void pointer conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print only arg = zero void pointer conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%p| void pointer test!!\n", 0);
	ret2 = ft_printf("This is a |%p| void pointer test!!\n", 0);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print MAX value void pointer test ----\n", __LINE__);
	ret1 =    printf("This is a |%p| void pointer test!!\n", 18446744073709551615ul);
	ret2 = ft_printf("This is a |%p| void pointer test!!\n", 18446744073709551615ul);
	check_return(ret1, ret2);
}

static void	pointer_width_options_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print void pointer with width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%20p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%20p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with width = 1 test ----\n", __LINE__);
	ret1 =    printf("This is a |%1p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%1p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*p| void pointer test!!\n", 20, &ret1);
	ret2 = ft_printf("This is a |%*p| void pointer test!!\n", 20, &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*p| void pointer test!!\n", -20, &ret1);
	ret2 = ft_printf("This is a |%*p| void pointer test!!\n", -20, &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with minus flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-20p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%-20p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with minus flag and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-*p| void pointer test!!\n", 20, &ret1);
	ret2 = ft_printf("This is a |%-*p| void pointer test!!\n", 20, &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with minus flag and negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-*p| void pointer test!!\n", -20, &ret1);
	ret2 = ft_printf("This is a |%-*p| void pointer test!!\n", -20, &ret1);
	check_return(ret1, ret2);
}

static void	pointer_precision_options_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print void pointer with precision < len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.5p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%.5p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with precision > len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.17p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%.17p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with precision = len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.12p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%.12p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.*p| void pointer test!!\n", 18, &ret1);
	ret2 = ft_printf("This is a |%.*p| void pointer test!!\n", 18, &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with negative precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.*p| void pointer test!!\n", -21, &ret1);
	ret2 = ft_printf("This is a |%.*p| void pointer test!!\n", -21, &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with only dot precision test ----\n", __LINE__);
	ret1 =    printf("This is a |%.p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%.p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer '0' with only dot precision test ----\n", __LINE__);
	ret1 =    printf("This is a |%.p| void pointer test!!\n", 0);
	ret2 = ft_printf("This is a |%.p| void pointer test!!\n", 0);
	check_return(ret1, ret2);
}

static void	pointer_width_precision_options_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print void pointer with width (digits option) = precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%19.19p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%19.19p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with width (star option) < precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*.19p| void pointer test!!\n", 17, &ret1);
	ret2 = ft_printf("This is a |%*.19p| void pointer test!!\n", 17, &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with width (digits option) > precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%25.*p| void pointer test!!\n", 19, &ret1);
	ret2 = ft_printf("This is a |%25.*p| void pointer test!!\n", 19, &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with width (star option) > precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*.*p| void pointer test!!\n", 25, 19, &ret1);
	ret2 = ft_printf("This is a |%*.*p| void pointer test!!\n", 25, 19, &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with only dot precision and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%23.p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%23.p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer '0' with and precision and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%15.7p| void pointer test!!\n", 0);
	ret2 = ft_printf("This is a |%15.7p| void pointer test!!\n", 0);
	check_return(ret1, ret2);
}

static void pointer_zero_flag_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print void pointer with only zero flag and conversion test ----\n", __LINE__);
	ret1 =    printf("This is a |%0p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%0p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with zero flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%019p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%019p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with zero flag and width = len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%012p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%012p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with zero flag, minus flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0-19p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%0-19p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with minus flag, zero flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-015p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%-015p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with zero flag and width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*p| void pointer test!!\n", 19, &ret1);
	ret2 = ft_printf("This is a |%0*p| void pointer test!!\n", 19, &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with zero flag and negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*p| void pointer test!!\n", -17, &ret1);
	ret2 = ft_printf("This is a |%0*p| void pointer test!!\n", -17, &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with zero flag, width (digits option) and precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%021.16p| void pointer test!!\n", &ret1);
	ret2 = ft_printf("This is a |%021.16p| void pointer test!!\n", &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with zero flag, negative width (star option) and precision (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*.16p| void pointer test!!\n", -21, &ret1);
	ret2 = ft_printf("This is a |%0*.16p| void pointer test!!\n", -21, &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with zero flag, width (digits option) and negative precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%020.*p| void pointer test!!\n", -15, &ret1);
	ret2 = ft_printf("This is a |%020.*p| void pointer test!!\n", -15, &ret1);
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print void pointer with zero flag, negative width (star option) and negative precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%0*.*p| void pointer test!!\n", -19, -17, &ret1);
	ret2 = ft_printf("This is a |%0*.*p| void pointer test!!\n", -19, -17, &ret1);
	check_return(ret1, ret2);
}

int		main(void)
{
	pointer_only_conversion_test();
	pointer_width_options_test();
	pointer_precision_options_test();
	pointer_width_precision_options_test();
	pointer_zero_flag_test();
	return (0);
}
