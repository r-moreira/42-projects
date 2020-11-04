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

	ret1 =    printf("|%5%|");
	ret2 = ft_printf("|%5%|");
	check_return(ret1, ret2);

	ret1 =    printf("|%-5%|");
	ret2 = ft_printf("|%-5%|\n");
	check_return(ret1, ret2);

	ret1 =    printf("|%05%|");
	ret2 = ft_printf("|%05%|\n");
	check_return(ret1, ret2);

	ret1 =    printf("|%-05%|\n");
	ret2 = ft_printf("|%-05%|\n");
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

static void	test_null_pointer()
{
	int		ret1, ret2;

	ret1 =    printf("|%p|\n", NULL);
	ret2 = ft_printf("|%p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%15p|\n", NULL);
	ret2 = ft_printf("|%15p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%-15p|\n", NULL);
	ret2 = ft_printf("|%-15p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.p|\n", NULL);
	ret2 = ft_printf("|%.p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.0p|\n", NULL);
	ret2 = ft_printf("|%.0p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.1p|\n", NULL);
	ret2 = ft_printf("|%.1p|\n", NULL);
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

	ret1 =    printf("|%.5p|\n", NULL);
	ret2 = ft_printf("|%.5p|\n", NULL);
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


int			main() {

	int	ret1, ret2;

	printf("\n----RUNNING TESTS----\n\n");

	//ft_test_percent();
	//ft_test_null_pointer();
	//ft_test_null_str();

	return (0);
}
