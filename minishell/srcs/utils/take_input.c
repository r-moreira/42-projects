/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:10:24 by romoreir          #+#    #+#             */
/*   Updated: 2021/11/23 22:53:06 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	take_input(t_shell *sh)
{
	char	*line_read;

	line_read = readline(" $> ");
	if (strlen(line_read) != 0)
	{
		if (line_read && *line_read) //Quando tiver "<<" não adicionar ao histórico
			add_history(line_read);
		ft_strlcpy(sh->input_string, line_read, ft_strlen(line_read) + 1);
		return (FALSE);
	}
	else
		return (TRUE);
}
