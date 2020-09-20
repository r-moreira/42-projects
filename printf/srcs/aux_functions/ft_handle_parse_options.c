#include "../../includes/ft_printf.h"

int		ft_is_option(char c)
{
	if (c == '*')
		return (E_STAR);
	if (c == '.')
		return (E_PREC);
	if (c == '0' || c == '-')
		return (E_FLAG);
	if (ft_isdigit(c))
		return (E_DIGIT);
	return (E_FALSE);
}

int		ft_is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%')
		return (E_CONV);
	return (E_FALSE);
}
/*

typedef enum	e_conversion_params
{
	E_FALSE,
	E_DIGIT,
	E_STAR,
	E_PREC,
	E_FLAG,
	E_CONV
}				t_conversion_params;


static void	ft_conversion_handler(va_list *args, const char **str,
t_ptr_functs *ptr, t_conversion *tools)
{
	int				index;

	ft_set_parse_tools(tools);
//	while((!(IS_CONV(**str))) && ((ft_isdigit(**str)) || (IS_OPTN(**str))))
	while((!ft_is_conversion(**str)) && ft_is_option(**str))
	{
		if (ft_is_option(**str) == E_FLAG)
			ft_define_flags(str, tools);
		if (ft_is_option(**str) == E_STAR || ft_is_option(**str) == E_DIGIT && **str != '0')
			ft_define_width(str, args, tools);
		if (ft_is_option(**str) == E_PREC)
			ft_define_precision(str, args, tools);
		*str += 1;
	}
	if (IS_CONV(tools->conv = **str))
	{
		index = -1;
		while (ptr->conversions[++index])
			if (ptr->conversions[index] == **str)
				tools->count += (ptr->functs[index])(args, *tools);
	}
	else
		tools->count += ft_putchar_count(**str);
}
*/
