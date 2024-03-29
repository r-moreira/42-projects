/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_null_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/13 22:14:13 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

long	split_count(char *s, char c)
{
	long	i;
	long	count;
	char	quote;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (is_closed_quotes(s[i], s + i))
		{
			quote = s[i];
			i++;
			while (s[i] != quote)
				i++;
		}
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	get_str_end(char *s, char c, int end)
{
	char	quote;

	while (s[end])
	{
		if (is_closed_quotes(s[end], s + end))
		{
			quote = s[end];
			end++;
			while (s[end] != quote)
				end++;
		}
		else if (s[end] == c)
			break ;
		end++;
	}
	return (end);
}

char	**split_null_end(char *s, char c)
{
	char	**strs;
	long	start;
	long	end;
	long	i;

	strs = (char **)malloc(sizeof(char *) * (split_count(s, c) + 2));
	start = 0;
	i = -1;
	while (++i != split_count(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		end = get_str_end(s, c, end);
		strs[i] = ft_substr(s, start, (end - start));
		if (!strs[i])
			return (NULL);
		start = end;
	}
	strs[i++] = NULL;
	return (strs);
}
