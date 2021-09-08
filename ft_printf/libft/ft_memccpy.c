/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*buffer_src;
	unsigned char		*buffer_dest;
	size_t				i;

	buffer_src = (unsigned char *)src;
	buffer_dest = (unsigned char *)dst;
	i = -1;
	while (++i < n)
	{
		buffer_dest[i] = buffer_src[i];
		if (buffer_src[i] == (unsigned char)c)
			return ((void *)buffer_dest + i + 1);
	}
	return (NULL);
}
