/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 21:05:06 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/01 01:47:20 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_cmd_valid(char *token)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (token[++i])
		if (ft_isalpha(token[i]))
			count++;
	if (count >= 1)
		return (TRUE);
	return (FALSE);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		printf("free arg: %d\n", i);
		free(split[i]);
	}
	free(split);
}

//TO-DO
//Remover flags do INPUT
t_status	parse_cmd(t_shell *sh, int cmd_num)
{
	int		i;
	char	**split;

	if (!sh->cmd_tokens[cmd_num] || !is_cmd_valid(sh->cmd_tokens[cmd_num]))
		return (ERROR);
	split = split_null_end(sh->cmd_tokens[cmd_num], ' ');
	i = -1;
	while (split[++i])
	{
		ft_strlcpy(sh->cmds[cmd_num].args[i], split[i], ft_strlen(split[i]));
		printf("CMD[%d] - ARGC[%d] - |%s|\n", cmd_num, i, split[i]); //TMP
	}
	ft_strlcpy(sh->cmds[cmd_num].name, split[0], ft_strlen(split[0]));
	free_split(split);
	return (SUCCESS);
}
