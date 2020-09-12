/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:34:39 by romoreir          #+#    #+#             */
/*   Updated: 2020/03/11 21:26:52 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testheader.h"

static int	menu_and_functs_calls(void)
{
	int		opt;
	int		menu_ret;
	int		funct_ret;

	funct_ret = 0;
	opt = main_menu();
	if (!opt)
		return (0);
	else
	{
		switch (opt)
		{
			case 1:
				menu_ret = libc_menu();
				if (menu_ret)
					funct_ret = call_libc_functs(menu_ret);
			break;
			case 2:
				menu_ret = additional_functs_menu();
				if (menu_ret)
					funct_ret = call_additional_functs(menu_ret);
			break;
			case 3:
				menu_ret = bonus_functs_menu();
				if (menu_ret)
					funct_ret = call_bonus_functs(menu_ret);
		}
	}
	if (!menu_ret || funct_ret)
		menu_and_functs_calls();
	return (0);
}

int			main(void)
{
	printf(
		"\n---- This is the test for libft functions! ----\n\n"
		"This program will do one or more simple test to each function in the libft project.\n"
		"Most functions are protected against outputs that can cause undertermined behavior, \n"
		"but this test is not intended to explore each of these details, but rather to show the \n"
		"behavior of the functions through a description and a simple test.\n\n"
		"The libft project can be divided in to three parts:\n"
		" * Recoding of some libc functions\n"
		" * Coding additional functions\n"
		" * Coding bonus functions, if you want more knowledge and of course SCORE.\n\n"
		"Read the libf_subject in the subject folder for more details about the project and functions.\n");
	menu_and_functs_calls();
	return (0);
}
