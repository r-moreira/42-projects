/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_substr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:55:15 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/31 15:18:05 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_new_str(char *str, char *str_end, size_t sublen, int start)
{
	char	*new;
	int		i;
	int		total_len;

	total_len = ft_strlen(str) - sublen;
	str_end += sublen;
	new = (char *)malloc(sizeof(char) * total_len + 1);
	i = -1;
	while (++i < total_len)
	{
		if (i < start)
			new[i] = str[i];
		else
			new[i] = *str_end++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_remove_substr(char *str, char *sub, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	tmp = (char *)str;
	if (sub[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (tmp[i + j] == sub[j] && (i + j) < len)
		{
			if (sub[j + 1] == '\0')
				return (get_new_str(str, &tmp[i], ft_strlen(sub), i));
			j++;
		}
		i++;
	}
	return (NULL);
}
