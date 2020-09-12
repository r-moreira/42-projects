#include "../../includes/ft_printf.h"

void	ft_define_flags(const char **str, t_conversion *tools)
{
	if (tools->opts.precision == -1 && tools->opts.width == 0)
	{
		if (**str == '-')
			tools->flags.minus = true;
		else if (**str == '0')
			tools->flags.zero = true;
	}
}

void	ft_define_width(const char **str, va_list *args, t_conversion *tools)
{
	int		digits;

	if (IS_STAR(**str))
	{
		tools->opts.width = va_arg(*args, int);
		if (tools->opts.width < 0)
		{
			tools->opts.width *= -1;
			tools->flags.minus = true;
		}
	}
	else
	{
		tools->opts.width = ft_atoi(*str);
		digits = tools->opts.width;
		while (digits > 10)
		{
			digits /= 10;
			*str += 1;
		}
	}
}

void	ft_define_precision(const char **str, va_list *args, t_conversion *tools)
{
	int		digits;

	if (!ft_isdigit(*(*str + 1)) && !IS_STAR(*(*str + 1)))
	{
		tools->opts.precision = 0;
		return ;
	}
	*str += 1;
	if (IS_STAR(**str))
	{
		tools->opts.precision = va_arg(*args, int);
		if (tools->opts.precision < 0)
			tools->opts.precision = -1;
	}
	else if (ft_isdigit(**str))
	{
		tools->opts.precision = ft_atoi(*str);
		if (tools->opts.precision >= 0)
		{
			digits = tools->opts.precision;
			while ((digits /= 10) > 0)
				*str += 1;
		}
	}
}
