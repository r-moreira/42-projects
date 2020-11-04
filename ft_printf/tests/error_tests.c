#include <stdio.h>
#include "ft_printf.h"

int			ft_printf(const char *format, ...);

static int	check_return(int ret1, int ret2)
{
	if (ret1 == ret2)
		printf("---Return OK---\n\n");
	else
		printf("---Return ERROR--- Libc -> %d | 42 = %d\n\n", ret1, ret2);
}

int			main() {

	int	ret1, ret2;

	printf("\n----RUNNING TESTS----\n\n");

	ret1 =    printf("|%5%|");
	ret2 = ft_printf("|%5%|");
	check_return(ret1, ret2);

	ret1 =    printf("|%-5%|");
	ret2 = ft_printf("|%-5%|\n");
	check_return(ret1, ret2);
	
	ret1 =    printf("|%05%|");
	ret2 = ft_printf("|%05%|\n");
	check_return(ret1, ret2);
	
	ret1 =    printf("|%-05%|");
	ret2 = ft_printf("|%-05%|\n");
	check_return(ret1, ret2);
	
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

	ret1 =    printf("|%.5p|\n", NULL);
	ret2 = ft_printf("|%.5p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%.10p|\n", NULL);
	ret2 = ft_printf("|%.10p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%5.p|\n", NULL);
	ret2 = ft_printf("|%5.p|\n", NULL);
	check_return(ret1, ret2);

	ret1 =    printf("|%12.5p|\n", NULL);
	ret2 = ft_printf("|%12.5p|\n", NULL);
	check_return(ret1, ret2);

	return (0);
}
