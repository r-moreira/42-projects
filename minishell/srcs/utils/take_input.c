/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:10:24 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/05 17:00:43 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//TO-DO: Lidar com aspas, se tiver aspas abertas, ler linhas no terminal até fechar aspas,
//depois concatenar com o que veio antes das aspas

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
