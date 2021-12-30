/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:53:08 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/30 19:55:43 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_status	parser(t_shell *sh)
{
	int	i;

	i = -1;
	while (++i < sh->cmds_count)
	{
		printf("cmd_token[%d] = %s\n", i, sh->cmd_tokens[i]); //TEMP
		if (parse_cmd_flag(sh, i) == ERROR)
			return (ERROR);
		//parse_cmd_bin
		//parse_cmd_args
	}
	i = -1;
	while(++i < sh->cmds_count)
		printf("CMD[%d] - FLAG[%d]\n", i, sh->cmds[i].flag);
	i = -1;
	while (++i < sh->cmds_count)
		free(sh->cmd_tokens[i]);
	return (SUCCESS);
}

