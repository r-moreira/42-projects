#include "../../includes/ft_printf_bonus.h"
#include <stdio.h>

static void	TEST_ft_print_width()
{
	int				strlen;
	t_conversion	tools;

	tools.flags.space = 0;
	tools.flags.plus = 0;
	tools.flags.sharp = 0;
	
	tools.conv = 'c';
	tools.opts.width = 5;
	strlen = 1;
	printf("---- Line = %d -> Print string width test ----\n", __LINE__);
	printf("    |\n");
	ft_print_width(tools, strlen);
	printf("|\n");

	tools.conv = 's';
	tools.opts.width = 12;
	strlen = 5;
	printf("\n---- Line = %d -> Print string width test ----\n", __LINE__);
	printf("       |\n");
	ft_print_width(tools, strlen);
	printf("|\n");

	tools.conv = 'd';
	tools.opts.width = 7;
	strlen = 12;
	printf("\n---- Line = %d -> Print number width test (len > width > precision) ----\n", __LINE__);
	printf("|\n");
	ft_print_width(tools, strlen);
	printf("|\n");

	tools.conv = 'i';
	tools.opts.width = 7;
	tools.opts.precision = 10;
	strlen = 4;
	printf("\n---- Line = %d -> Print number width test (precision > width > len) ----\n", __LINE__);
	printf("|\n");
	ft_print_width(tools, strlen);
	printf("|\n");

	tools.conv = 'u';
	tools.opts.width = 13;
	tools.opts.precision = 7;
	strlen = 4;
	printf("\n---- Line = %d -> Print number width test (width > precision > len) ----\n", __LINE__);
	printf("      |\n");
	ft_print_width(tools, strlen);
	printf("|\n");

	tools.conv = 'p';
	tools.opts.width = 13;
	tools.opts.precision = 7;
	strlen = 4;
	printf("\n---- Line = %d -> Print number width test (width > precision > len and conversion = '%%p') ----\n", __LINE__);
	printf("    |\n");
	ft_print_width(tools, strlen);
	printf("|\n");

	tools.conv = 'x';
	tools.opts.width = 10;
	tools.opts.precision = 2;
	strlen = 7;
	printf("\n---- Line = %d -> Print number width test (width > len > precision) ----\n", __LINE__);
	printf("   |\n");
	ft_print_width(tools, strlen);
	printf("|\n");

	tools.conv = 'X';
	tools.opts.width = 12;
	tools.opts.precision = -1;
	tools.flags.zero = 1;
	tools.flags.minus = 0;
	strlen = 4;
	printf("\n---- Line = %d -> Print number width test (width > len, no precision and zero flag) ----\n", __LINE__);
	printf("00000000|\n");
	ft_print_width(tools, strlen);
	printf("|\n");

	tools.conv = 'd';
	tools.opts.width = 12;
	tools.opts.precision = 4;
	tools.flags.zero = 1;
	tools.flags.minus = 0;
	strlen = 4;
	printf("\n---- Line = %d -> Print number width test (width > len = precision and zero flag) ----\n", __LINE__);
	printf("        |\n");
	ft_print_width(tools, strlen);
	printf("|\n");

	tools.conv = 'd';
	tools.opts.width = 12;
	tools.opts.precision = -1;
	tools.flags.zero = 1;
	tools.flags.minus = 1;
	strlen = 7;
	printf("\n---- Line = %d -> Print number width test (width > len, no precision, minus and zero flag) ----\n", __LINE__);
	printf("     |\n");
	ft_print_width(tools, strlen);
	printf("|\n");

	printf("\n");
}

static void	TEST_ft_print_precision()
{
	t_conversion	tools;
	int				strlen;

	tools.opts.precision = -1;
	strlen = 7;
	printf("\n---- Line = %d -> Print number precision test (len > precision) ----\n", __LINE__);
	printf("|\n");
	ft_print_precision(tools, strlen);
	printf("|\n");

	tools.opts.precision = 12;
	strlen = 7;
	printf("\n---- Line = %d -> Print number precision test (precision > len) ----\n", __LINE__);
	printf("00000|\n");
	ft_print_precision(tools, strlen);
	printf("|\n");
}

int			main(void)
{
	TEST_ft_print_width();
	TEST_ft_print_precision();
	return (0);
}
