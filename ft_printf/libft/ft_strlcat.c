/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:48:36 by romoreir          #+#    #+#             */
/*   Updated: 2020/02/14 19:10:31 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		len_dest;
	size_t		len_src;
	size_t		i;
	size_t		j;

	len_dest = 0;
	while (dst[len_dest] != '\0' && len_dest < dstsize)
		len_dest++;
	len_src = 0;
	while (src[len_src])
		len_src++;
	if (dstsize <= len_dest)
		return (len_src + len_dest);
	i = -1;
	j = len_dest;
	while ((src[++i]) && (j < (dstsize - 1)))
		dst[j++] = src[i];
	dst[j] = '\0';
	return (len_src + len_dest);
}
