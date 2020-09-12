/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functsinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:34:26 by romoreir          #+#    #+#             */
/*   Updated: 2020/03/11 20:20:06 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testheader.h"

void	libc_functs_info(int index)
{
	printf("\n\n---- FUNCTION DETAILS ----\n");
	switch (index)
	{
	case 1: //MEMSET
		printf(
			"Description: memset is used to fill a block of memory with a particular value starting"
			"at the location pointed by \"b\".\n\n"
			"Prototype: void *ft_memset(void *b, int c, size_t n);\n\n"
			"*b ==> Starting address of memory to be filled.\n"
			"c ==> Value to be filled.\n"
			"n ==> Number of bytes to be filled starting from *b.\n"
			"Return value: The initial address of \"*b\" used in the function call.\n"
		);
		break;
	case 2: //BZERO
		printf(
			"Description: bzero erases the data in \"n\" bytes of the memory starting at the location"
			"pointed to by \"s\", by writing zeros.\n\n"
			"Ṕrototype: void ft_bzero(void *s, size_t n);\n\n"
			"*s ==> Starting address of memory to be erased.\n"
			"n ==> Number of bytes to be erased starting from *s.\n"
			"Return value: None.\n"
		);
		break;
	case 3: //memcpy
		printf(
		"Description: memcpy is used to copy a \"n\" block of memory from a location to another.\n\n"
		"Prototype: *ft_memcpy(void *dst, const void *src, size_t n);\n\n"
		"*dst ==>  This is pointer to the destination array where the content is to be copied, "
		"type-casted to a pointer of type void*.\n"
		"src ==> This is pointer to the source of data to be copied, type-casted to a pointer of type void*.\n"
		"n ==> This is the number of bytes to be copied.\n"
		"Return value: This function returns a pointer to destination.\n"
		);
	}
}

void	additional_functs_info(int index)
{
	(void)index;
}

void	bonus_functs_info(int index)
{
	(void)index;
}
