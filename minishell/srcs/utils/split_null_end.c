/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_null_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/31 21:03:20 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

long	split_count(const char *s, char c)
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

char	**split_null_end(char const *s, char c)
{
	char	**strs;
	long	start;
	long	end;
	long	i;

	strs = (char **)malloc(sizeof(char *) * (split_count(s, c) + 2));
	start = 0;
	i = -1;
	end = 0;
	while (++i != split_count(s, c))
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
	strs[i++] = NULL;
	strs[i] = 0;
	return (strs);
}
