/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:55:25 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/10 21:49:56 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_status	get_cmd_flag(t_shell *sh, char *cmd_token, int num,
int flag_index)
{
	if (cmd_token[flag_index] == '|')
		sh->cmds[num].flag = PIPE;
	else if (cmd_token[flag_index] == '<')
	{
		if (cmd_token[flag_index + 1])
		{
			if (cmd_token[flag_index + 1] == '<')
				sh->cmds[num].flag = HERE_DOCUMENT;
		}
		else
			sh->cmds[num].flag = REDIRECT_IN;
	}
	else if (cmd_token[flag_index] == '>')
	{
		if (cmd_token[flag_index + 1])
		{
			if (cmd_token[flag_index + 1] == '>')
				sh->cmds[num].flag = REDIRECT_OUT_APPEND;
		}
		else
			sh->cmds[num].flag = REDIRECT_OUT;
	}
	return (SUCCESS);
}

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
			return (get_cmd_flag(sh, cmd_token, num, i));
		else if (is_flag(c) && !is_closed_quotes(c, cmd_token + i))
			return (get_cmd_flag(sh, cmd_token, num, i));
		else if (is_closed_quotes(c, cmd_token + i))
		{
			i++;
			while (cmd_token[i] != c)
				i++;
		}
	}
	return (SUCCESS);
}
