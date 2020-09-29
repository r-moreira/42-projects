#include "../includes/ft_printf.h"
#include <stdio.h>

static void	set_tools(t_conversion *tools)
{
	tools->flags.minus = false;
	tools->flags.zero = false;
	tools->opts.width = 0;
	tools->opts.precision = -1;
}

static int	TEST_ft_define_flags()
{
	t_conversion	tools;
	char			minus_str[] = "-c";
	char			zero_str[] = "0d";
	char			sharp_str[] = "#X";
	char			space_str[] = " d";
	char			plus_str[] = "+d";
	const char		*p_minus_str;
	const char		*p_zero_str;
	const char		*p_sharp_str;
	const char		*p_space_str;
	const char		*p_plus_str;
	char			test_result_minus;
	char			test_result_minus2;
	char			test_result_sharp;
	char			test_result_space;
	char			test_result_plus;
	char			test_result_zero;
	char			test_result_zero2;

	test_result_minus = false;
	test_result_zero = false;
	test_result_sharp = false;
	test_result_space = false;
	test_result_plus = false;
	test_result_minus2 = false;
	test_result_zero2 = false;
	p_minus_str = minus_str;
	p_zero_str = zero_str;
	p_sharp_str = sharp_str;
	p_space_str = space_str;
	p_plus_str = plus_str;

	set_tools(&tools); //here tools.flags.minus is = false
	ft_define_flags(&p_minus_str, &tools); //now tools.flags.minus must be true
	test_result_minus = tools.flags.minus;

	set_tools(&tools); //here tools.flags.zero is = false
	ft_define_flags(&p_zero_str, &tools); //now tools.flags.zero must be true
	test_result_zero = tools.flags.zero;

	set_tools(&tools); //here tools.flags.sharp is = false
	ft_define_flags(&p_sharp_str, &tools); //now tools.flags.sharp must be true
	test_result_sharp = tools.flags.sharp;

	set_tools(&tools); //here tools.flags.space is = false
	ft_define_flags(&p_space_str, &tools); //now tools.flags.space must be true
	test_result_space = tools.flags.space;

	set_tools(&tools); //here tools.flags.plus is = false
	ft_define_flags(&p_plus_str, &tools); //now tools.flags.plus must be true
	test_result_plus = tools.flags.plus;

	set_tools(&tools);
	tools.opts.precision = 42; //this is not -1, tools.flags.minus must continue false
	ft_define_flags(&p_minus_str, &tools);
	if (tools.flags.minus == false)
		test_result_minus2 = true;

	set_tools(&tools);
	tools.opts.width = 42; //this is not zero, tools.flags.zero must continue false
	ft_define_flags(&p_minus_str, &tools);
	if (tools.flags.zero == false)
		test_result_zero2 = true;

	return (test_result_zero * test_result_minus * test_result_sharp * test_result_space *
			test_result_plus * test_result_minus2 * test_result_zero2);
}

static int	TEST_ft_define_width(const char *format, ...)
{
	t_conversion	tools;
	va_list			args;
	char			digit_str[] = "4267c";
	char			star_str[] = "*";
	const char		*p_digit_str;
	const char		*p_star_str;
	char			test_result_digit_str;
	char			test_result_star_str;
	char			test_result_negative_star_str;


	va_start(args, format);
	test_result_digit_str = false;
	test_result_star_str = false;
	test_result_negative_star_str = false;
	p_digit_str = digit_str;
	p_star_str = star_str;

	set_tools(&tools); //here tools.ops.width is = 0
	ft_define_width(&p_digit_str, &args, &tools); //now tool.opts.width must be the numeric value of str (4267)
	if (tools.opts.width == 4267 && *p_digit_str == '7') //the pointer needs to be at the last numeric value of the format str. That number will be incremented in ft_conversion_handler and the pointer will move to the next non-numeric character
		test_result_digit_str = true;

	set_tools(&tools); //here tools.ops.width is = 0
	ft_define_width(&p_star_str, &args, &tools); //now tools.opts.width must be the next value in the variadic args linked list (6742)
	if (tools.opts.width == 6742)
		test_result_star_str = true;

	set_tools(&tools); //here tools.ops.width is = 0 and tools.flags.minus = false
	ft_define_width(&p_star_str, &args, &tools); //now tool.opts.width must be the POSITIVE numeric value of negative linked str (-8267) and tools.flags.minus must be true
	if (tools.opts.width == 8542 && tools.flags.minus)
		test_result_negative_star_str = true;

	va_end(args);
	return (test_result_digit_str * test_result_star_str * test_result_negative_star_str);
}

static int	TEST_ft_define_precision(const char *format, ...)
{
	t_conversion	tools;
	va_list			args;
	char			digit_str[] = ".4267c";
	char			star_str[] = ".*";
	char			only_prec_str[] = ".c";
	const char		*p_digit_str;
	const char		*p_star_str;
	const char		*p_only_prec_str;
	char			test_result_digit_str;
	char			test_result_star_str;
	char			test_result_negative_star_str;
	char			test_result_only_prec_str;

	va_start(args, format);
	test_result_digit_str = false;
	test_result_star_str = false;
	test_result_negative_star_str = false;
	test_result_only_prec_str = false;
	p_digit_str = digit_str;
	p_star_str = star_str;
	p_only_prec_str = only_prec_str;

	set_tools(&tools); //here tools.ops.precision is = 0
	ft_define_precision(&p_digit_str, &args, &tools); //now tools.opts.precision must be the numeric value of str (4267)
	if (tools.opts.precision == 4267 && *p_digit_str == '7') //the pointer needs to be at the last numeric value of the format str. That number will be incremented in ft_conversion_handler and the pointer will move to the next non-numeric character
		test_result_digit_str = true;

	set_tools(&tools);//here tools.ops.precision is = 0
	ft_define_precision(&p_star_str, &args, &tools); //now tools.opts.precision must be the next value in the variadic args linked list (6742)
	if (tools.opts.precision == 6742)
		test_result_star_str = true;

	set_tools(&tools); //here tools.ops.precision is = 0
	ft_define_precision(&p_star_str, &args, &tools); //now tools.opts.precision must be = 0 because the argument value is negative (-8542)
	if (tools.opts.precision == 0)
		test_result_negative_star_str = true;

	set_tools(&tools); //here tools.ops.precision is = 0
	ft_define_precision(&p_only_prec_str, &args, &tools); //now tools.opts.precision must be = 0 because there is a conversion "c" after precision "."
	if (tools.opts.precision == 0)
		test_result_only_prec_str = true;

	va_end(args);
	return (test_result_digit_str * test_result_star_str * test_result_negative_star_str * test_result_only_prec_str);
}

int			main(void)
{
	if (TEST_ft_define_flags())
		printf("ft_define_flags --> OK\n");
	else
		printf("ft_define_flags --> FAILED\n");

	if (TEST_ft_define_width("test", 6742, -8542))
		printf("ft_define_width --> OK\n");
	else
		printf("ft_define_width --> FAILED\n");

	if (TEST_ft_define_precision("test", 6742, -8542))
		printf("ft_define_precision --> OK\n");
	else
		printf("ft_define_precision --> FAILED\n");

	return (0);
}
