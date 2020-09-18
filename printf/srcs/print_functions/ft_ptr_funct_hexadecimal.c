#include "../../includes/ft_printf.h"

int				ft_ptr_funct_hexadecimal(va_list *args, t_conversion tools)
{
	t_arg_types	type;
	char		*arg_str;
	int			len;

	type._uint = va_arg(*args, unsigned int);
	if (tools.conv == 'x')
		arg_str = ft_nbr_to_str(LOWER_HEXA, type, tools);
	else
		arg_str = ft_nbr_to_str(UPPER_HEXA, type, tools);
	len = ft_get_output_len(arg_str, tools);
	if (PAD_LEFT(len))
		ft_print_width(tools, len);
	ft_print_precision(tools, len);
	len ? ft_putstr_fd(arg_str, 1) : len;
	free(arg_str);
	if (PAD_RIGTH(len))
		ft_print_width(tools, len);
	if (tools.opts.width > tools.opts.precision && tools.opts.width > len)
		return (tools.opts.width);
	else if (tools.opts.precision > len)
		return (tools.opts.precision);
	return (len);
}
