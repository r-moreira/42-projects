/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_here_document.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:16:19 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/27 23:34:14 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_here_document(char *parsed_line)
{
	int	i;

	if (!parsed_line || ft_strlen(parsed_line) == 0)
		return (FALSE);
	i = 0;
	while (parsed_line[++i])
		if (parsed_line[i - 1] == '<' && parsed_line[i] == '<')
			return (TRUE);
	return (FALSE);
}
