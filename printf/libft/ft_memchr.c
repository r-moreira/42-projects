/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:15:37 by romoreir          #+#    #+#             */
/*   Updated: 2020/01/24 15:15:39 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buffer_src;
	size_t			i;

	buffer_src = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (buffer_src[i] == (unsigned char)c)
			return ((void *)buffer_src + i);
	return (NULL);
}
