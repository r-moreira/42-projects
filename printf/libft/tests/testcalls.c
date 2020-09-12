/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcalls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:34:46 by romoreir          #+#    #+#             */
/*   Updated: 2020/03/11 19:24:50 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testheader.h"

int		call_libc_functs(int index)
{
	int		ret;

	switch (index)
	{
		case 1:
		libc_functs_info(index);
		ret = ft_memset_test();
		break;
		case 2:
		libc_functs_info(index);
		ret = ft_bzero_test();
		break;
		case 3:
		libc_functs_info(index);
		ret = ft_memcpy_test();
	}
	return (ret);
}

int		call_additional_functs(int index) //create file additionaltests.c
{
	(void)index;
	return (1);
}

int		call_bonus_functs(int index) //create file bonustests.c
{
	(void)index;
	return (1);
}
