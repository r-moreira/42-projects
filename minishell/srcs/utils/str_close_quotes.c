/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_close_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:54:25 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/13 22:54:52 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	str_close_quotes(char *dest, char *src, int *i, int *j)
{
	char	c;

	c = src[*i];
	dest[++(*j)] = src[*i];
	while (src[++(*i)] != c)
		dest[++(*j)] = src[*i];
	dest[++(*j)] = src[*i];
}
