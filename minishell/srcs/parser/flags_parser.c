/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:55:25 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/30 19:55:52 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


static t_bool is_flag(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (TRUE);
	return (FALSE);
}

static t_status get_cmd_flag(t_shell *sh, char *cmd_token, int cmd_num, int flag_index)
{
	if (cmd_token[flag_index] == '|')
		sh->cmds[cmd_num].flag = PIPE;
	else if (cmd_token[flag_index] == '<')
	{
		if (cmd_token[flag_index + 1])
		{
			if (cmd_token[flag_index + 1] == '<')
				sh->cmds[cmd_num].flag = HERE_DOCUMENT;
		}
		else
			sh->cmds[cmd_num].flag = REDIRECT_IN;
	}
	else if (cmd_token[flag_index] == '>')
	{
		if (cmd_token[flag_index + 1])
		{
			if (cmd_token[flag_index + 1] == '>')
				sh->cmds[cmd_num].flag = REDIRECT_OUT_APPEND;
		}
		else
			sh->cmds[cmd_num].flag = REDIRECT_OUT;
	}
	return (SUCCESS);
}

t_status	parse_cmd_flag(t_shell *sh, int cmd_num)
{
	int		i;
	char	c;
	char	*cmd_token;

	i = -1;
	cmd_token = sh->cmd_tokens[cmd_num];
	while (cmd_token[++i])
	{
		c = cmd_token[i];
		if (is_flag(c) && c != '\'' && c != '"')
			return (get_cmd_flag(sh, cmd_token, cmd_num, i));
		else if (is_flag(c) && !is_closed_quotes(c, cmd_token + i))
			return (get_cmd_flag(sh, cmd_token, cmd_num, i));
		else if (is_closed_quotes(c, cmd_token + i))
		{
			i++;
			while (cmd_token[i] != c)
				i++;
		}
	}
	return (SUCCESS);
}
