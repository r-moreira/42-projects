#include "../../includes/ft_printf.h"

int				ft_ptr_funct_percent(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	ft_putchar_fd('%', 1);
	return (1);
}
