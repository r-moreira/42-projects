/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:10:24 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/05 21:03:27 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


//TO-DO:
static t_bool	is_here_document(char *line_read)
{
	(void)line_read;
	return FALSE;
}

//TO-DO:
//não adicionar ao histórico
static char *take_here_document_input(char *line_read)
{
	return (line_read);
}

//TO-DO:
//substituir "$VAR" pelo valor correspondente
static void	handle_variables(char *line_read)
{
	(void)line_read;
}

//TO-DO:
//3) Free line read?
int	take_input(t_shell *sh)
{
	char	*line_read;
	char	quote;

	line_read = readline(" $> ");
	if (strlen(line_read) != 0)
	{
		if (line_read && *line_read)
		{
			handle_variables(line_read);
			if (is_here_document(line_read))
				take_here_document_input(line_read);
			else
			{
				add_history(line_read);
				ft_strlcpy(sh->input_string, line_read, ft_strlen(line_read) + 1);
			}
		}
		return (FALSE);
	}
	else
		return (TRUE);
}
