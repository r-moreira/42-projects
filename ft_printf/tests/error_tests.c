#include <stdio.h>
#include "ft_printf.h"

static int	ft_printf(const char *format, ...);

static int	check_return(int ret1, int ret2)
{
	if (ret1 == ret2)
		printf("---Return OK---\n\n");
	else
		printf("---Return ERROR--- Libc -> %d | 42 = %d\n\n", ret1, ret2);
}

static void	ft_test_percent()
{
	int		ret1, ret2;

	ret1 =    printf("|%5%|\n");
	ret2 = ft_printf("|%5%|\n");
	check_return(ret1, ret2);

	ret1 =    printf("|%-5%|\n");
	ret2 = ft_printf("|%-5%|\n");
	check_return(ret1, ret2);

	ret1 =    printf("|%05%|\n");
	ret2 = ft_printf("|%05%|\n");
	check_return(ret1, ret2);

	ret1 =    printf("|%-05%|\n");
	ret2 = ft_printf("|%-05%|\n");
	check_return(ret1, ret2);

	ret1 =    printf("|%.5%|\n");
	ret2 = ft_printf("|%.5%|\n");
	check_return(ret1, ret2);

	ret1 =    printf("|%-042.*%|\n", 42);
	ret2 = ft_printf("|%-042.*%|\n", 42);
	check_return(ret1, ret2);

	ret1 =    printf("|%-042.*%|\n", 24);
	ret2 = ft_printf("|%-042.*%|\n", 24);
	check_return(ret1, ret2);

	ret1 =    printf("|%024.*%|\n", 42);
	ret2 = ft_printf("|%024.*%|\n", 42);
	check_return(ret1, ret2);
}

static void	ft_test_null_pointer()
{
	int		ret1, ret2;

	ret1 =    printf("|%p|\n", NULL);
	ret2 = ft_printf("|%p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%3p|\n", NULL);
	ret2 = ft_printf("|%3p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%10p|\n", NULL);
	ret2 = ft_printf("|%10p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%-15p|\n", NULL);
	ret2 = ft_printf("|%-15p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.p|\n", NULL);
	ret2 = ft_printf("|%.p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.9p|\n", NULL);
	ret2 = ft_printf("|%.9p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.1p|\n", NULL);
	ret2 = ft_printf("|%.1p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.0p|\n", NULL);
	ret2 = ft_printf("|%.0p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.2p|\n", NULL);
	ret2 = ft_printf("|%.2p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.3p|\n", NULL);
	ret2 = ft_printf("|%.3p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.4p|\n", NULL);
	ret2 = ft_printf("|%.4p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%8.5p|\n", NULL);
	ret2 = ft_printf("|%8.5p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.6p|\n", NULL);
	ret2 = ft_printf("|%.6p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.7p|\n", NULL);
	ret2 = ft_printf("|%.7p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%5.p|\n", NULL);
	ret2 = ft_printf("|%5.p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%12.5p|\n", NULL);
	ret2 = ft_printf("|%12.5p|\n", NULL);
	check_return(ret1, ret2);
}

static void	ft_test_null_str_width()
{
	int		ret1, ret2;

	ret1 =    printf("|%s|\n", NULL);
	ret2 = ft_printf("|%s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%0s|\n", NULL);
	ret2 = ft_printf("|%0s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%1s|\n", NULL);
	ret2 = ft_printf("|%1s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%-3s|\n", NULL);
	ret2 = ft_printf("|%-3s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%-04s|\n", NULL);
	ret2 = ft_printf("|%-04s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%05s|\n", NULL);
	ret2 = ft_printf("|%05s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%6s|\n", NULL);
	ret2 = ft_printf("|%6s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%7s|\n", NULL);
	ret2 = ft_printf("|%7s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%09s|\n", NULL);
	ret2 = ft_printf("|%09s|\n", NULL);
	check_return(ret1, ret2);


	ret1 =    printf("|%-10s|\n", NULL);
	ret2 = ft_printf("|%-10s|\n", NULL);
	check_return(ret1, ret2);
}

static void	ft_test_null_str_precision()
{
	int		ret1, ret2;

	ret1 =    printf("|%.s|\n", NULL);
	ret2 = ft_printf("|%.s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.0s|\n", NULL);
	ret2 = ft_printf("|%.0s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.1s|\n", NULL);
	ret2 = ft_printf("|%.1s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%-.2s|\n", NULL);
	ret2 = ft_printf("|%-.2s|\n", NULL);
	check_return(ret1, ret2);


	ret1 =    printf("|%.3s|\n", NULL);
	ret2 = ft_printf("|%.3s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%0.4s|\n", NULL);
	ret2 = ft_printf("|%0.4s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.05s|\n", NULL);
	ret2 = ft_printf("|%.05s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.6s|\n", NULL);
	ret2 = ft_printf("|%.6s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.7s|\n", NULL);
	ret2 = ft_printf("|%.7s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%0.9s|\n", NULL);
	ret2 = ft_printf("|%0.9s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%-.10s|\n", NULL);
	ret2 = ft_printf("|%-.10s|\n", NULL);
	check_return(ret1, ret2);
}

static void	ft_test_null_str_width_precision()
{
	int		ret1, ret2;

	ret1 =    printf("|%3.s|\n", NULL);
	ret2 = ft_printf("|%3.s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%1.0s|\n", NULL);
	ret2 = ft_printf("|%1.0s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%0.1s|\n", NULL);
	ret2 = ft_printf("|%0.1s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%-4.2s|\n", NULL);
	ret2 = ft_printf("|%-4.2s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%3.3s|\n", NULL);
	ret2 = ft_printf("|%3.3s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%06.4s|\n", NULL);
	ret2 = ft_printf("|%06.4s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%-3.05s|\n", NULL);
	ret2 = ft_printf("|%-3.05s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%2.6s|\n", NULL);
	ret2 = ft_printf("|%2.6s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%14.7s|\n", NULL);
	ret2 = ft_printf("|%14.7s|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%09.9s|\n", NULL);
	ret2 = ft_printf("|%09.9s|\n", NULL);
	check_return(ret1, ret2);


	ret1 =    printf("|%-3.10s|\n", NULL);
	ret2 = ft_printf("|%-3.10s|\n", NULL);
	check_return(ret1, ret2);
}


int			main() {

	int	ret1, ret2;

	printf("\n----RUNNING TESTS----\n\n");

	//ft_test_percent();
	//ft_test_null_pointer();jkkk
	ft_test_null_str_width();
	//ft_test_null_str_precision();
	//ft_test_null_str_width_precision();

	return (0);
}
