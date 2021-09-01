/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:04:46 by romoreir          #+#    #+#             */
/*   Updated: 2021/07/19 17:44:06 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		sub_str[i] = (char)s[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
