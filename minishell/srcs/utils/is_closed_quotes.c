/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:54:38 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/31 15:41:35 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_closed_quotes(char c, char *input)
{
	int	i;

	i = 0;
	if (c == '\'' || c == '"')
	{
		while (input[++i])
		{
			if (input[i] == c)
				return (TRUE);
		}
		return (FALSE);
	}
	else
		return (FALSE);
}
