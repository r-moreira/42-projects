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

static void	string_only_conversion_test()
{
	int		ret1;
	int		ret2;

	printf("---- Print only string conversion test ----\n");
	ret1 =    printf("This is a %s test!!\n", "string");
	ret2 = ft_printf("This is a %s test!!\n", "string");
	check_return(ret1, ret2);
}


static void	string_width_options_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print string with width > arg length (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%10s| test!!\n", "string");
	ret2 = ft_printf("This is a |%10s| test!!\n", "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with width = arg length (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%6s| test!!\n", "string");
	ret2 = ft_printf("This is a |%6s| test!!\n", "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with width < string len (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%3s| test!!\n", "string");
	ret2 = ft_printf("This is a |%3s| test!!\n", "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with negative width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-12s| test!!\n", "string");
	ret2 = ft_printf("This is a |%-12s| test!!\n", "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*s| test!!\n", 9, "string");
	ret2 = ft_printf("This is a |%*s| test!!\n", 9, "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%*s| test!!\n", -9, "string");
	ret2 = ft_printf("This is a |%*s| test!!\n", -9, "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with minus flag and width (digits option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-15s| test!!\n", "string");
	ret2 = ft_printf("This is a |%-15s| test!!\n", "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with minus flag and negative width (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%-*s| test!!\n", -15, "string");
	ret2 = ft_printf("This is a |%-*s| test!!\n", -15, "string");
	check_return(ret1, ret2);
}

static void	string_precision_option_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print string with precision (digits) = string length test ----\n", __LINE__);
	ret1 =    printf("This is a |%.6s| test!!\n", "string");
	ret2 = ft_printf("This is a |%.6s| test!!\n", "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with precision (digits) < string length test ----\n", __LINE__);
	ret1 =    printf("This is a |%.3s| test!!\n", "string");
	ret2 = ft_printf("This is a |%.3s| test!!\n", "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with precision (digits) > string length test ----\n", __LINE__);
	ret1 =    printf("This is a |%.12s| test!!\n", "string");
	ret2 = ft_printf("This is a |%.12s| test!!\n", "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with precision (digits) = only '.' test ----\n", __LINE__);
	ret1 =    printf("This is a |%.s| test!!\n", "string");
	ret2 = ft_printf("This is a |%.s| test!!\n", "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.*s| test!!\n", 4, "string");
	ret2 = ft_printf("This is a |%.*s| test!!\n", 4, "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with negative precision (star option) test ----\n", __LINE__);
	ret1 =    printf("This is a |%.*s| test!!\n", -12, "string");
	ret2 = ft_printf("This is a |%.*s| test!!\n", -12, "string");
	check_return(ret1, ret2);
}

static void	string_width_precision_options_test()
{
	int		ret1;
	int		ret2;

	printf("\n---- Line = %d -> Print string with width (digits) and precision (digits) > strlen test ----\n", __LINE__);
	ret1 =    printf("This is a |%10.10s| test!!\n", "string");
	ret2 = ft_printf("This is a |%10.10s| test!!\n", "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with width (digits) > strlen and precision (digits) < strlen tests ----\n", __LINE__);
	ret1 =    printf("This is |%10.3s| test!!\n", "string");
	ret2 = ft_printf("This is |%10.3s| test!!\n", "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with width (digits) > strlen and precision (digits) = 0 ----\n", __LINE__);
	ret1 =    printf("This is |%8.0s| test!!\n", "string");
	ret2 = ft_printf("This is |%8.0s| test!!\n", "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with width (digits) > strlen and precision (digits) = '.' ----\n", __LINE__);
	ret1 =    printf("This is |%8.s| test!!\n", "string");
	ret2 = ft_printf("This is |%8.s| test!!\n", "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with width (digits) < strlen and precision (digits) = strlen ----\n", __LINE__);
	ret1 =    printf("This is |%2.6s| test!!\n", "string");
	ret2 = ft_printf("This is |%2.6s| test!!\n", "string");
	check_return(ret1, ret2);

	printf("\n---- Line = %d -> Print string with width (star option and minus flag) < strlen and precision (star option) ----\n", __LINE__);
	ret1 =    printf("This is |%-*.*s| test!!\n", 9, 5, "string");
	ret2 = ft_printf("This is |%-*.*s| test!!\n", 9, 5, "string");
	check_return(ret1, ret2);
}

int		main(void)
{

	string_only_conversion_test();
	string_width_options_test();
	string_precision_option_test();
	string_width_precision_options_test();
	return (0);
}
