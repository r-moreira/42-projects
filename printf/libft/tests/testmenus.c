/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmenus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:34:59 by romoreir          #+#    #+#             */
/*   Updated: 2020/03/03 20:35:01 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testheader.h"

int		main_menu(void)
{
	int		opt;

	do
	{
		printf(
			"\n\n----------------------------- MAIN MENU ------------------------------------\n"
			"Enter the indicated number related to which function group you want to test.\n"
			"(1) - To test the recoding of libc functions.\n"
			"(2) - To test the additional libft functions.\n"
			"(3) - To test the bonus libft functions.\n"
			"(0) - To exit the program.\n");
		printf("Option = ");
		scanf("%d", &opt);
		if (opt < 0 || opt > 3)
			printf("\n---- Invalid option, try again. ----\n\n");
	}while (opt < 0 || opt > 3);
	return (opt);
}

int		libc_menu(void)
{
	int		opt;

	printf("\n\n------------------- Here you can test the recoding of some libc functions ------------------------\n");
	do
	{
		printf(
			"Enter the indicated number related to the function you want to test or '0' to return to main menu.\n"
			"(1)  - memset            | (9)  - strlcpy          | (17) - isdigit\n"
			"(2)  - bzero             | (10) - strlcat          | (18) - isalnum\n"
			"(3)  - memcpy            | (11) - strchr           | (19) - isascii\n"
			"(4)  - memccpy           | (12) - strrchr          | (20) - isprint\n"
			"(5)  - memmove           | (13) - strnstr          | (21) - toupper\n"
			"(6)  - memchr            | (14) - strncmp          | (22) - tolower\n"
			"(7)  - memcmp            | (15) - atoi             | (23) - calloc\n"
			"(8)  - strlen            | (16) - isalpha          | (24) - strdup\n"
			"(0)  - Return to main menu.\n");
		printf("Option = ");
		scanf("%d", &opt);
		if (opt < 0 || opt > 24)
			printf("\nInvalid option, try again.");
	} while (opt < 0 || opt > 24);
	return (opt);
}

int			additional_functs_menu(void)
{
	int		opt;

	printf("\n\n---------------------- Here you can test the libft additional functions --------------------------\n");
	do
	{
		printf(
			"Enter the indicated number related to the function you want to test or '0' to return to main menu.\n"
			"(1)  - ft_substr         | (6)  - ft_strmapi\n"
			"(2)  - ft_strjoin        | (7)  - ft_putchar_fd\n"
			"(3)  - ft_strtrim        | (8)  - ft_putstr_fd\n"
			"(4)  - ft_split          | (9)  - ft_putendl_fd\n"
			"(5)  - ft_itoa           | (10) - ft_putnbr_fd\n"
			"(0)  - Return to main menu.\n");
		printf("Option = ");
		scanf("%d", &opt);

		if (opt < 0 || opt > 13)
			printf("\nInvalid option, try again.\n");
	}
	while (opt < 0 || opt > 13);
	return (opt);
}

int			bonus_functs_menu(void)
{
	int		opt;

	printf("\n\n------------------------ Here you can test the libft bonus functions -----------------------------\n");
	do
	{
		printf(
			"Enter the indicated number related to the function you want to test or '0' to return to main menu.\n"
			"(1)  - ft_lstnew         | (6)  - ft_lstdelone\n"
			"(2)  - ft_lstadd_front   | (7)  - ft_lstclear\n"
			"(3)  - ft_lstsize        | (8)  - ft_lstiter\n"
			"(4)  - ft_lstlast        | (9)  - ft_lstmap\n"
			"(5)  - ft_lstadd_back    | (0)  - Return to main menu.\n");
		printf("Option = ");
		scanf("%d", &opt);
		if (opt < 0 || opt > 10)
			printf("\nInvalid option, try again.\n");
	}
	while (opt < 0 || opt > 10);
	return (opt);
}
