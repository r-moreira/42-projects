#include "../includes/ft_printf_bonus.h"
#include <stdio.h>

int		main(void)
{
	va_list			args;
	t_conversion	tools;
	t_ptr_functs	*ptr;
	char			convs_OK;
	char			functs_OK;
	char			ret;
	int				i;

	i = 0;
	convs_OK = 0;
	functs_OK = 0;
	ret = 0;

	ft_set_ptr_functs(&ptr);

	//checking if struct s_ptr_functs is initialized
	if (!(ft_strncmp(ptr->conversions, "cspdiuxX%", 9)))
		convs_OK = 1;

	for (i = 0; i < 9; i++)
		ret += ptr->functs[i](&args, tools);
	if (ret == 9)
		functs_OK = 1;

	if (convs_OK && functs_OK)
		printf("ft_set_ptr_funct --> OK\n");
	else
		printf("ft_set_ptr_funct --> FAILED\n");

	ft_set_parse_tools(&tools);
	//checking if structs s_flags and s_options ins initiliazed
	if (tools.flags.minus == false && tools.flags.minus == false && tools.flags.sharp == false &&
		tools.flags.space == false && tools.flags.plus == false && tools.opts.width == 0 && tools.opts.precision == -1)
			printf("ft_set_parse_tools --> OK\n");
	else
		printf("ft_set_parse_tools --> FAILED\n");
	return (0);
}

int		ft_ptr_funct_character(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	return (1);
}

int		ft_ptr_funct_string(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	return (1);
}

int		ft_ptr_funct_pointer(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	return (1);
}

int		ft_ptr_funct_integer(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	return (1);
}

int		ft_ptr_funct_hexadecimal(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	return (1);
}

int		ft_ptr_funct_percent(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	return (1);
}
