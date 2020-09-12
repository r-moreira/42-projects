#include "../../includes/ft_printf.h"

int		ft_get_output_len(char *arg_str, t_conversion tools)
{
	int len;

	len = ft_strlen(arg_str);
	if (len == 1 && arg_str[0] == '0' && tools.opts.precision == 0)
		return (0);
	return (len);
}
