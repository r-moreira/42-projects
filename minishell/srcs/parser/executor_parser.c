/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:53:08 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/09 00:07:09 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_status	is_token_valid(char *token)
{
	int	i;
	int	alpha_count;
	int	flag_count;

	alpha_count = 0;
	flag_count = 0;
	i = -1;
	while (token[++i])
	{
		if (ft_isalpha(token[i]))
			alpha_count++;
		else if (is_flag(token[i]))
			flag_count++;
	}
	if (alpha_count >= 2 || flag_count >= 1)
		return (SUCCESS);
	return (NOT_TOKEN);
}

t_status	parser(t_shell *sh)
{
	int	i;

	i = -1;
	while (++i < sh->count.cmds)
	{
		if (is_token_valid(sh->cmd_tokens[i]) == SUCCESS)
		{
			if (parse_flag(sh, i) == ERROR)
				return (ERROR);
			if (parse_cmd(sh, i) == ERROR)
				return (ERROR);
		}
	}
	i = -1;
	while (++i < sh->count.cmds)
		free(sh->cmd_tokens[i]);
	return (SUCCESS);
}
