/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:59:46 by romoreir          #+#    #+#             */
/*   Updated: 2021/07/19 17:51:49 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_split_count(const char *s, char c)
{
	long	i;
	long	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	long	start;
	long	end;
	long	i;

	if (s == NULL)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (ft_split_count(s, c) + 1));
	start = 0;
	i = -1;
	end = 0;
	while (++i != ft_split_count(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		strs[i] = ft_substr(s, start, (end - start));
		if (!strs[i])
			return (NULL);
		start = end;
	}
	strs[i] = 0;
	return (strs);
}
