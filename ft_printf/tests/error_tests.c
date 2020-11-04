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

//	ft_printf("|%5%|\n");
//	ft_printf("|%-5%|\n");
//	ft_printf("|%05%|\n");
//	ft_printf("|%-05%|\n");
//	ret1 =    printf("%5%");
//	ret2 = ft_printf("%5%");
//	check_return(ret1, ret2);

	ft_printf("|%p|\n", NULL);
	ft_printf("|%15p|\n", NULL);
	ft_printf("|%-15p|\n", NULL);
	ft_printf("|%.p|\n", NULL);
	ft_printf("|%.0p|\n", NULL);
	ft_printf("|%.5p|\n", NULL);
	ft_printf("|%.10p|\n", NULL);
	ft_printf("|%5.p|\n", NULL);
	ft_printf("|%12.5p|\n", NULL);



	return (0);
}
