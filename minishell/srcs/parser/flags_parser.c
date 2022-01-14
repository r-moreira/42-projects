/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:55:25 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/14 00:08:20 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


/*static t_status	get_cmd_flags(t_shell *sh, char *cmd_token, int num, int index)
{
	initialize_cmd_flags(sh, num);
	if (cmd_token[index] == '|')
		sh->cmds[num].pipe = TRUE;
	else if (cmd_token[index] == '<')
	{
		if (cmd_token[index + 1])
		{
			if (cmd_token[index + 1] == '<')
				sh->cmds[num].here_doc++;;
		}
		else
			sh->cmds[num].rd_in++;
	}
	else if (cmd_token[index] == '>')
	{
		if (cmd_token[index + 1])
		{
			if (cmd_token[index + 1] == '>')
				sh->cmds[num].rd_out_apnd++;
		}
		else
			sh->cmds[num].rd_out++;
	}
	return (SUCCESS);
}*/

//TO-DO Adicionar flags na struct de flags dos cmds
t_status	parse_flag(t_shell *sh, int num)
{
	int		i;
	char	c;
	char	*cmd_token;

	i = -1;
	cmd_token = sh->cmd_tokens[num];
	while (cmd_token[++i])
	{
		c = cmd_token[i];
		if (is_flag(c) && c != '\'' && c != '"')
			return (ERROR);//return (get_cmd_flags(sh, cmd_token, num, i));
		else if (is_flag(c) && !is_closed_quotes(c, cmd_token + i))
			return (ERROR);//return (get_cmd_flags(sh, cmd_token, num, i));
		else if (is_closed_quotes(c, cmd_token + i))
		{
			i++;
			while (cmd_token[i] != c)
				i++;
		}
	}
	return (SUCCESS);
}
