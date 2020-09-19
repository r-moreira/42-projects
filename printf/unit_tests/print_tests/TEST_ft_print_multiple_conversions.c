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

/* TO DO:
	print two or more conversions -
	print two or more conversions with width and precision -
	print two or more conversions with width, precision, minus and zero flags -
*/
int			main(void)
{
	return (0);
}
