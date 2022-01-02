/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 21:05:06 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/02 12:00:33 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_bool	is_cmd_valid(char *token)
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

static void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

static char*	remove_flags(char *token)
{
	int		i;
	int		j;
	char	c;
	char	*new;

	new = malloc(sizeof(char) * ft_strlen(token) + 1);
	i = -1;
	j = -1;
	while (token[++i])
	{
		c = token[i];
		if (!is_flag(c) && c != '\'' && c != '"')
			new[++j] = c;
		else if ((c == '\'' || c == '"') && is_closed_quotes(c, token + i))
		{
			new[++j] = token[i];
			while (token[++i] != c)
				new[++j] = token[i];
			new[++j] = token[i];
		}
	}
	new[++j] = '\0';
	printf("NFLAG_TKN = [%s]\n", new);
	return (new);
}

t_status	parse_cmd(t_shell *sh, int cmd_num)
{
	int		i;
	char	**split;
	char	*token;

	if (!sh->cmd_tokens[cmd_num] || !is_cmd_valid(sh->cmd_tokens[cmd_num]))
		return (ERROR);
	token = remove_flags(sh->cmd_tokens[cmd_num]);
	split = split_null_end(token, ' '); //TO-DO: se tiver espaço no meio das aspas, não dar split
	i = -1;
	while (split[++i])
	{
		ft_strlcpy(sh->cmds[cmd_num].args[i], split[i], ft_strlen(split[i]));
		printf("CMD[%d] - ARGC[%d] - [%s]\n", cmd_num, i, split[i]); //TMP
	}
	printf("CMD[%d] - ARGC[%d] - [%s]\n", cmd_num, i, split[i]); //TMP
	ft_strlcpy(sh->cmds[cmd_num].name, split[0], ft_strlen(split[0]));
	free(token);
	free_split(split);
	return (SUCCESS);
}
