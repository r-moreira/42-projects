/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:58:56 by romoreir          #+#    #+#             */
/*   Updated: 2020/01/31 20:58:58 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_c_in_set(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	unsigned int	trim_len;
	char			*trim_start;
	char			*trim_end;
	char			*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_c_in_set(s1[i], set))
		i++;
	trim_start = (char *)&s1[i];
	if ((i = (int)ft_strlen((char *)s1) - 1) > 0)
		while (i >= 0 && ft_c_in_set(s1[i], set))
			i--;
	trim_end = (char *)&s1[i];
	if (!*s1 || trim_start == trim_end)
		trim_len = 2;
	else
		trim_len = trim_end - trim_start + 1;
	if (!(trimmed_str = (char *)malloc(sizeof(char) * (trim_len + 1))))
		return (NULL);
	ft_strlcpy(trimmed_str, trim_start, trim_len + 1);
	return (trimmed_str);
}
