#include "../includes/ft_printf.h"
#include <stdio.h>

static void	ft_conversion_handler(va_list *args, const char **str,
t_ptr_functs *ptr, t_conversion *tools);

int			ft_putchar_count(char c)
{
	(void)c;
	return (0);
}

static int	TEST_ft_conversion_handler(const char *str, ...)
{
	t_ptr_functs	*ptr;
	t_conversion	tools;
	va_list			args;

	va_start(args, str);
	ft_set_ptr_functs(&ptr);
	tools.count = 0;
	ft_conversion_handler(&args, &str, ptr, &tools);
	return (tools.count);
}

int			main(void)
{
	if	//Passing conversion specifiers as parameter need to call the correct pointer function
	(
		TEST_ft_conversion_handler("c") == 99 && //Calling character conversion pointer function. Returns 99 ('c') in ASCII table.
		TEST_ft_conversion_handler("s") == 115 && //Calling string conversion pointer function. Returns 115 ('s') in ASCII table.
		TEST_ft_conversion_handler("p") == 112 && //Calling pointer conversion pointer function. Returns 112 ('p') in ASCII table.
		TEST_ft_conversion_handler("d") == 100 && //Calling integer conversion pointer function. Returns 100 ('d') in ASCII table.
		TEST_ft_conversion_handler("i") == 100 && //Calling integer conversion pointer function. Returns 100 ('d') in ASCII table.
		TEST_ft_conversion_handler("u") == 100 && //Calling integer conversion pointer function. Returns 100 ('d') in ASCII table.
		TEST_ft_conversion_handler("x") == 120 && //Calling hexadecimal conversion pointer function. Returns 120 ('x') in ASCII table.
		TEST_ft_conversion_handler("X") == 120 && //Calling hexadecimal conversion pointer function. Returns 120 ('x') in ASCII table.
		TEST_ft_conversion_handler("%") == 37 && //Calling percent conversion pointer function. Returns 37 ('%') in ASCII table.
		TEST_ft_conversion_handler("z") == 0 //Calling with a invalid argument, need to return 0
	)
		printf("ft_conversion_handler --> OK\n");
	else
		printf("ft_conversion_handler --> FAILED\n");
	return (0);
}

int			ft_ptr_funct_character(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	return (99);
}

int			ft_ptr_funct_string(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	return (115);
}

int			ft_ptr_funct_pointer(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	return (112);
}

int			ft_ptr_funct_integer(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	return (100);
}

int			ft_ptr_funct_hexadecimal(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	return (120);
}

int			ft_ptr_funct_percent(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	return (37);
}

//The ft_printf.c file has the same function. Need to copy this because it's a static function
static void	ft_conversion_handler(va_list *args, const char **str,
t_ptr_functs *ptr, t_conversion *tools)
{
	int				index;

	ft_set_parse_tools(tools);
	while ((!ft_is_conversion(**str)) && ft_is_option(**str))
	{
		if (ft_is_option(**str) == E_FLAG)
			ft_define_flags(str, tools);
		if (ft_is_option(**str) == E_STAR || ft_is_option(**str) == E_DIGIT)
			ft_define_width(str, args, tools);
		if (ft_is_option(**str) == E_PREC)
			ft_define_precision(str, args, tools);
		*str += 1;
	}
	if (ft_is_conversion(**str))
	{
		tools->conv = **str;
		index = -1;
		while (ptr->conversions[++index])
			if (ptr->conversions[index] == **str)
				tools->count += (ptr->functs[index])(args, *tools);
	}
	else
		tools->count += ft_putchar_count(**str);
}

