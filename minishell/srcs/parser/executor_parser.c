/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:53:08 by romoreir          #+#    #+#             */
/*   Updated: 2022/03/02 02:37:09 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_status	error_invalid_flags(t_shell *sh)
{
	int	i;

	i = -1;
	while (++i < sh->count.cmds)
		free(sh->cmd_tokens[i]);
	return (syntax_error(ERROR_INVLD_FLAG));
}

static t_status	error_no_alphanum(t_shell *sh)
{
	int	i;

	i = -1;
	while (++i < sh->count.cmds)
		free(sh->cmd_tokens[i]);
	return (syntax_error(ERROR_NO_ALPNUM));
}

static t_status	is_token_valid(char *token)
{
	int	i;
	int	alpha_count;

	alpha_count = 0;
	i = -1;
	while (token[++i])
		if (ft_isalnum(token[i]))
			alpha_count++;
	if (alpha_count >= 1)
		return (SUCCESS);
	return (NOT_TOKEN);
}

static t_status	is_flags_valid(char *token)
{
	int		i;
	int		j;
	int		count;
	char	c;

	i = 0;
	while (token[i])
	{
		if (token[i] == '<' || token[i] == '>')
		{
			count = 0;
			c = token[i];
			j = i;
			while (token[++j] && !ft_isalnum(token[j]))
				if (token[j] == c)
					count++;
			if ((count == 1 && token[i + 1] != c) || (count >= 2))
				return (NOT_TOKEN);
		}
		i++;
	}
	return (SUCCESS);
}

t_status	parser(t_shell *sh)
{
	int	i;

	i = -1;
	while (++i < sh->count.cmds)
	{
		if (is_token_valid(sh->cmd_tokens[i]) == SUCCESS)
		{
			if (parse_cmd(sh, i) == ERROR)
				return (ERROR);
			if (is_flags_valid(sh->cmd_tokens[i]) == SUCCESS)
			{
				if (parse_flags(sh, i) == ERROR)
					return (ERROR);
			}
			else
				return (error_invalid_flags(sh));
		}
		else
			return (error_no_alphanum(sh));
	}
	i = -1;
	while (++i < sh->count.cmds)
		free(sh->cmd_tokens[i]);
	return (SUCCESS);
}
