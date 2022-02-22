/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:55:25 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/22 16:35:15 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	set_flags(t_shell *sh, char *token, int num, t_flag flag)
{
	if (flag == HERE_DOCUMENT)
		sh->cmds[num].exec.heredoc = TRUE;
	else if (flag == REDIRECT_IN)
	{
		ft_strlcpy(sh->cmds[num].redin.arg[sh->cmds[num].redin.len],
			token, ft_strlen(token) + 1);
		sh->cmds[num].redin.len++;
		sh->cmds[num].exec.redin = TRUE;
	}
	else if (flag == REDIRECT_OUT_APPEND)
	{
		ft_strlcpy(sh->cmds[num].redout_apd.arg[sh->cmds[num].redout_apd.len],
			token, ft_strlen(token) + 1);
		sh->cmds[num].redout_apd.len++;
		sh->cmds[num].exec.redout_apd = TRUE;
		sh->cmds[num].exec.last_redout = REDIRECT_OUT_APPEND;
	}
	else if (flag == REDIRECT_OUT)
	{
		ft_strlcpy(sh->cmds[num].redout.arg[sh->cmds[num].redout.len],
			token, ft_strlen(token) + 1);
		sh->cmds[num].redout.len++;
		sh->cmds[num].exec.redout = TRUE;
		sh->cmds[num].exec.last_redout = REDIRECT_OUT;
	}
}

static int	get_flag_token(t_shell *sh, char *token, int num, t_flag flag)
{
	char			*arg_token;
	char			*no_quotes_token;
	unsigned int	start;
	size_t			end;

	start = 1;
	if (flag == HERE_DOCUMENT || flag == REDIRECT_OUT_APPEND)
		start++;
	while (token[start] && ft_isspace(token[start]))
		start++;
	end = start;
	while (token[end] && !ft_isspace(token[end]) && !is_flag(token[end]))
		end++;
	arg_token = ft_substr(token, start, end - start);
	no_quotes_token = str_remove_quotes(arg_token);
	set_flags(sh, no_quotes_token, num, flag);
	free(arg_token);
	free(no_quotes_token);
	if (token[end - 1] && is_flag(token[end]))
		end--;
	return (end);
}

static void	get_cmd_flags(t_shell *sh, char *token, int num, int *i)
{
	int	j;

	j = *i;
	if (token[j] == '|')
		sh->cmds[num].exec.pipe = TRUE;
	else if (token[j] == '<')
	{
		if (token[j + 1] && token[j + 1] == '<')
			(*i) += get_flag_token(sh, token + j, num, HERE_DOCUMENT);
		else
			(*i) += get_flag_token(sh, token + j, num, REDIRECT_IN);
	}
	else if (token[j] == '>')
	{
		if (token[j + 1] && token[j + 1] == '>')
			(*i) += get_flag_token(sh, token + j, num, REDIRECT_OUT_APPEND);
		else
			(*i) += get_flag_token(sh, token + j, num, REDIRECT_OUT);
	}
}

t_status	parse_flags(t_shell *sh, int num)
{
	int		i;
	char	*token;

	setup_flag_info(sh, num);
	token = sh->cmd_tokens[num];
	i = 0;
	while (token[i] && !is_flag(token[i]))
		i++;
	i--;
	while (token[i])
	{
		if (is_flag(token[i]))
			get_cmd_flags(sh, token, num, &i);
		if (!token[i])
			break ;
		else
			i++;
	}
	return (SUCCESS);
}
