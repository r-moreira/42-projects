/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:17:16 by romoreir          #+#    #+#             */
/*   Updated: 2020/03/03 20:16:08 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** All these auxiliary functions were taken from libft project.
*/

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(new_str = (char *)malloc(sizeof(char) * total_size + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		new_str[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		new_str[i] = s2[j];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	available_len;
	char	*sub_str;

	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) < start)
		return (ft_strdup(""));
	available_len = ft_strlen((char *)s + start);
	if (available_len < len)
		len = available_len;
	if (!(sub_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_str[i] = (char)s[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

char		*ft_strchr(char const *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char		*ft_strdup(char const *s1)
{
	char	*dest;
	size_t	i;

	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t		ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
