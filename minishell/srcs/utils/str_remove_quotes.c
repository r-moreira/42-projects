/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_remove_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:20:42 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/14 17:51:57 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdlib.h>

char	*str_remove_quotes(char *str)
{
	char	*no_quotes_str;
	int		i;
	int		j;

	no_quotes_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = -1;
	j = -1;
	while (str[++i])
		if (str[i] != '\'' && str[i] != '"')
			no_quotes_str[++j] = str[i];
	no_quotes_str[++j] = '\0';
	return (no_quotes_str);
}
