#include "../../includes/ft_printf.h"

void		ft_print_precision(t_conversion tools, int len)
{
	if (tools.opts.precision <= len)
		return ;
	while (tools.opts.precision-- > len)
		ft_putchar_fd('0', 1);
}
