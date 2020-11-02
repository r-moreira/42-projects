/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:08:35 by romoreir          #+#    #+#             */
/*   Updated: 2020/02/02 13:35:48 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*buffer_src;
	unsigned char		*buffer_dest;

	if (dst == NULL && src == NULL)
		return (NULL);
	buffer_src = (unsigned char *)src;
	buffer_dest = (unsigned char *)dst;
	while (n--)
		*buffer_dest++ = *buffer_src++;
	return (dst);
}
