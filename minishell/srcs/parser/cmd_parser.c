/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 21:05:06 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/31 21:08:39 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//TO-DO
//Remover flags do INPUT
t_status	parse_cmd(t_shell *sh, int cmd_num)
{
	int		i;

	if (sh->cmd_tokens[cmd_num] == NULL)
		return (ERROR);
	sh->cmds[cmd_num].args = split_null_end(sh->cmd_tokens[cmd_num], ' ');
	ft_strlcpy(sh->cmds[cmd_num].name, sh->cmds[cmd_num].args[0],
		ft_strlen(sh->cmds[cmd_num].args[0]));
	i = -1;
	while (sh->cmds[cmd_num].args[++i])
	{
		printf("CMD[%d] - ARGC[%d] - |%s|\n", cmd_num, i, sh->cmds[cmd_num].args[i]); //TMP
	}
	return (SUCCESS);
}
