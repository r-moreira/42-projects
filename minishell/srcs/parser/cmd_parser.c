/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:53:08 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/30 14:27:25 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//TO-DO:
// Salvar as flags do comando na struct
// Desconsiderar flags caso estejam dentro de aspas "" ''
// Retornar erro em caso de mais de uma flag por comando
static void	parse_cmd_flag(t_shell *sh, int token_index)
{
	(void)sh;
	(void)token_index;
}

t_status	parser(t_shell *sh)
{
	int	i;

	i = -1;
	while (++i < sh->cmds_count)
	{
		printf("cmd_token[%d] = %s\n", i, sh->cmd_tokens[i]); //TEMP
		parse_cmd_flag(sh, i);
		//parse_cmd_bin
		//parse_cmd_args
	}
	i = -1;
	while (++i < sh->cmds_count)
		free(sh->cmd_tokens[i]);

	return (SUCCESS);
}
