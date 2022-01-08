/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:55:25 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/07 22:22:11 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	debugger_aux(t_shell *sh, int cmd_num)
{
	char	*flag_descrpt;

	if (DEBUGGER)
	{
		if (sh->cmds[cmd_num].flag == 1)
			flag_descrpt = "PIPE";
		else if (sh->cmds[cmd_num].flag == 2)
			flag_descrpt = "REDIRECT OUT";
		else if (sh->cmds[cmd_num].flag == 3)
			flag_descrpt = "REDIRECT OUT APPEND";
		else if (sh->cmds[cmd_num].flag == 4)
			flag_descrpt = "REDIRECT IN";
		else if (sh->cmds[cmd_num].flag == 5)
			flag_descrpt = "HERE DOCUMENT";
		else
			flag_descrpt = "NONE";
		printf("CMD[%d] - FLAG[%s]\n", cmd_num, flag_descrpt);
	}
}

static t_status	get_cmd_flag(t_shell *sh, char *cmd_token, int cmd_num,
int flag_index)
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

t_status	parse_flag(t_shell *sh, int cmd_num)
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
	debugger_aux(sh, cmd_num);
	return (SUCCESS);
}
