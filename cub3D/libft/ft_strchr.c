/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:15:23 by romoreir          #+#    #+#             */
/*   Updated: 2020/01/24 19:11:43 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*buffer_str;

	buffer_str = (char *)s;
	while (*buffer_str != c)
	{
		if (!*buffer_str)
			return (NULL);
		buffer_str++;
	}
	return (buffer_str);
}
