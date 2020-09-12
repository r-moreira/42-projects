/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:15:53 by romoreir          #+#    #+#             */
/*   Updated: 2020/01/24 15:15:54 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*buffer_s1;
	const unsigned char *buffer_s2;
	size_t				i;

	if (n == 0)
		return (0);
	buffer_s1 = (unsigned char *)s1;
	buffer_s2 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
		if ((unsigned char)buffer_s1[i] != (unsigned char)buffer_s2[i])
			return ((unsigned char)buffer_s1[i] - (unsigned char)buffer_s2[i]);
	return (0);
}
