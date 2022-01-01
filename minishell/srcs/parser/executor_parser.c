/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:53:08 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/31 21:05:28 by romoreir         ###   ########.fr       */
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
		if (parse_flag(sh, i) == ERROR)
			return (ERROR);
		if (parse_cmd(sh, i) == ERROR)
			return (ERROR);
		//parse_cmd_args
	}
	i = -1;
	while (++i < sh->cmds_count)
		printf("CMD[%d] - FLAG[%d]\n", i, sh->cmds[i].flag);
	i = -1;
	while (++i < sh->cmds_count)
		free(sh->cmd_tokens[i]);
	return (SUCCESS);
}
