/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:14:07 by romoreir          #+#    #+#             */
/*   Updated: 2020/01/24 19:55:13 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buffer_str;
	char	*last_c;

	buffer_str = (char *)s;
	last_c = NULL;
	while (*buffer_str)
	{
		if (*buffer_str == c)
			last_c = buffer_str;
		buffer_str++;
	}
	if (c == '\0')
		return (buffer_str);
	if (last_c)
		return (last_c);
	return (NULL);
}
