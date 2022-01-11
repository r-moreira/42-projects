/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 21:05:06 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/10 21:58:00 by romoreir         ###   ########.fr       */
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

static void	free_parser(char **splt, char *token)
{
	int	i;

	i = -1;
	while (splt[++i])
		free(splt[i]);
	free(splt);
	free(token);
}

char	*remove_flags(char *token)
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
	return (new);
}

t_status	parse_cmd(t_shell *sh, int num)
{
	int		i;
	int		len;
	char	**splt;
	char	*token;

	if (!sh->cmd_tokens[num] || !is_cmd_valid(sh->cmd_tokens[num]))
		return (ERROR);
	token = remove_flags(sh->cmd_tokens[num]);
	splt = split_null_end(token, ' ');
	i = -1;
	while (splt[++i])
	{
		len = ft_strlen(splt[i]);
		sh->cmds[num].args[i] = (char *)malloc(sizeof(char) * len + 1);
		ft_strlcpy(sh->cmds[num].args[i], splt[i], len + 1);
	}
	sh->cmds[num].args_count = i;
	sh->cmds[num].args[i] = NULL;
	ft_strlcpy(sh->cmds[num].name, splt[0], ft_strlen(splt[0]) + 1);
	free_parser(splt, token);
	return (SUCCESS);
}
