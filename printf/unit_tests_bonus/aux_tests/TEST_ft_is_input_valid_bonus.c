#include "../includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char	test_result;
	char	test_result2;

	test_result = false;
	test_result2 = false;
	if
	(	//conversions
		ft_is_input_valid("d") &&
		ft_is_input_valid("s") &&
		ft_is_input_valid("p") &&
		ft_is_input_valid("d") &&
		ft_is_input_valid("i") &&
		ft_is_input_valid("u") &&
		ft_is_input_valid("x") &&
		ft_is_input_valid("X") &&
		ft_is_input_valid("%") &&

		//conversion with width - digits
		ft_is_input_valid("42c") &&
		ft_is_input_valid("2c") &&
		ft_is_input_valid("42424224242424242c") &&
		//conversion with width - star
		ft_is_input_valid("*c") &&

		//conversion with precision - digits
		ft_is_input_valid(".42c") &&
		ft_is_input_valid(".2c") &&
		ft_is_input_valid(".c") &&
		ft_is_input_valid(".4224242424242424c") &&
		//conversion with precision - star
		ft_is_input_valid(".*c") &&

		//conversion with flags
		ft_is_input_valid("-c") &&
		ft_is_input_valid("0c") &&
		ft_is_input_valid("+d") &&
		ft_is_input_valid("#x") &&
		ft_is_input_valid(" u") &&

		//conversion with width and precision
		ft_is_input_valid("42.42c") &&
		ft_is_input_valid("2.2c") &&
		ft_is_input_valid("42424242.42424242c") &&
		ft_is_input_valid("*.42c") &&
		ft_is_input_valid("2.*c") &&
		ft_is_input_valid("*.*c") &&

		//conversion with flags, width and precision
		ft_is_input_valid("-42.42c") &&
		ft_is_input_valid("---------2.2c") &&
		ft_is_input_valid("042424242.42424242c") &&
		ft_is_input_valid("000*.42c") &&
		ft_is_input_valid("-02.*c") &&
		ft_is_input_valid("0-*.*c") &&
		ft_is_input_valid(" +*.*u") &&
		ft_is_input_valid("###*.*d")
		)
		test_result = true;

	if
	(!(
		//no conversion
		ft_is_input_valid("42a") &&
		ft_is_input_valid("123") &&
		ft_is_input_valid(".*") &&
		ft_is_input_valid("-*") &&
		ft_is_input_valid("0") &&
		ft_is_input_valid("z") &&

		//flag in wrong order
		ft_is_input_valid("42-.c") &&

		//conversion before
		ft_is_input_valid("c42.*") &&

		//double precision
		ft_is_input_valid(".4.2c") &&

		//double star
		ft_is_input_valid("**c") &&
		ft_is_input_valid("42.**c") &&

		//digit and star in width
		ft_is_input_valid("10*c") &&
		ft_is_input_valid("*10c") &&

		//digit and star in precision
		ft_is_input_valid(".10*c") &&
		ft_is_input_valid(".*10c")
	))
		test_result2 = true;


	if (test_result && test_result2)
		printf("ft_is_input_valid --> OK\n");
	else
		printf("ft_is_input_valid --> FAILED\n");
	return (0);
}
