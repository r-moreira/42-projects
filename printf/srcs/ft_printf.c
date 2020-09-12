#include "../includes/ft_printf.h"

int			ft_putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

static void	ft_free_and_null(const char **address, t_ptr_functs **ptr)
{
	free((char *)*address);
	address = NULL;
	free(*ptr);
	ptr = NULL;
}

static void	ft_conversion_handler(va_list *args, const char **str,
t_ptr_functs *ptr, t_conversion *tools)
{
	int				index;

	ft_set_parse_tools(tools);
	while((!(IS_CONV(**str))) && ((ft_isdigit(**str)) || (IS_OPTN(**str))))
	{
		if (IS_FLAG(**str))
			ft_define_flags(str, tools);
		if ((IS_STAR(**str)) || ((ft_isdigit(**str) && **str != '0')))
			ft_define_width(str, args, tools);
		if (IS_PREC(**str))
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

int			ft_printf(const char *format, ...)
{
	t_ptr_functs	*ptr;
	t_conversion	tools;
	va_list			args;
	const char		*address;
	const char		*str;

	if ((!(address = ft_strdup(format))) || (!(ft_set_ptr_functs(&ptr))))
		return (0);
	str = address;
	tools.count = 0;
	va_start(args, format);
	while (*str)
	{
		if ((*str == '%' && ft_is_input_valid(str)) && ++str)
			ft_conversion_handler(&args, &str, ptr, &tools);
		else
			tools.count += ft_putchar_count(*str);
		str++;
	}
	va_end(args);
	ft_free_and_null(&address, &ptr);
	return (tools.count);
}
