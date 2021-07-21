/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 22:20:25 by romoreir          #+#    #+#             */
/*   Updated: 2021/07/19 17:50:48 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*buffer_src;
	unsigned char		*buffer_dest;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (NULL);
	buffer_dest = (unsigned char *)dst;
	buffer_src = (unsigned char *)src;
	i = 0;
	if (buffer_src < buffer_dest)
		while (++i <= len)
			buffer_dest[len - i] = buffer_src[len - i];
	else
		while (len--)
			*buffer_dest++ = *buffer_src++;
	return (dst);
}
