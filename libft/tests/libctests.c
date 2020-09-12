/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libctests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:34:33 by romoreir          #+#    #+#             */
/*   Updated: 2020/03/11 20:36:59 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testheader.h"

static int	test_options(void)
{
	int		opt;

	do
	{
		printf("\n\nSelect the desired option according to the corresponding number.\n");
		printf("(1) - To test another function.\n");
		printf("(0) - To exit the program.\n");
		printf("Option = ");
		scanf("%d", &opt);
		if (opt < 0 || opt > 1)
			printf("\nInvalid option, try again.\n");
	}
	while (opt < 0 || opt > 1);
	return (opt);
}

int			ft_memset_test(void)
{
	char	b[] = "I'm not your father.";
	char 	c = '.';
	size_t	n = 3 * sizeof(char);

	printf(
		"\n---- TEST VARIABLES ----\n"
		"char	b[] = \"I'm not your father.\";\n"
		"char	c = '.';\n"
		"size_t	n = 3 * sizeof(char);\n"
		"\n---- FUNCTION CALL ----\n"
		"ft_memset(b + 4, c, n);"
		"        \\\\It's important to see that we add 4 to the b address.\n"
	);
	printf(
		"\n---- RETURN / RESULT ----\n"
		"return value = %s\n",
		(char *)ft_memset(b + 4, c, n)
	);
	printf(
		"\n---- NOTES ----\n"
		"The \"*b\" is a void pointer, so that we can pass any type"
		" of pointer to this function,\nin this test the \"*b\" was char pointer.\n"
	);
	return (test_options());
}

int		ft_bzero_test(void)
{
	char	s[] = "This is SPARTA!!";
	size_t	n = 13 * sizeof(char);

	printf(
		"\n---- TEST VARIABLES ----\n"
		"s[] = \"This is SPARTA!!\";\n"
		"size_t n = 8 * sizeof(char);\n"
		"\n---- FUNCTION CALL ----\n"
		"ft_bzero(s + 7, n);"
		"        \\\\It's important to see that we add 7 to the b address.\n"
	);
	ft_bzero(s + 7, n);
	printf(
		"\n---- RESULT ----\n"
		"Our \"s[]\" is now = %s\n"
		"\n---- NOTES ----\n"
		"The \"*s\" is a void pointer, so that we can pass any type"
		" of pointer to this function,\nin this test the \"*s\" was char pointer.\n",
		s
	);
	return (test_options());
}

int		ft_memcpy_test(void)
{
	char	dest[50];
	char	src[] = "Copied!!, not copied";
	size_t	n = 8;

	printf(
		"\n---- TEST VARIABLES ----\n"
		"char dest[50];\n"
		"char src[] = \"Copied!!, not copied\";\n"
		"size_t n = 8;\n"
		"\n---- FUNCTION CALL ----\n"
		"ft_memcpy(dest, src, n);\n"
	);
	ft_memcpy(dest, src, n);
	*(dest + n) = '\0';
	printf(
		"We need to add \"\\0\" on the end of our dest to print the string.\n"
		"*(dest + n) = '\\0';  ==> Now we can print the dest!\n"
		"\n---- RETURN / RESULT ----\n"
		"dest is now: %s\n", dest
	);
	printf(
		"\n---- NOTES ----\n"
		"memcpy() doesn’t check for overflow or \"\\0\"\n"
		"memcpy() leads to problems when source and destination addresses overlap.\n"
	);
	return (test_options());
}
