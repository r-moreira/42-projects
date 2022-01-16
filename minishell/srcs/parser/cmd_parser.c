/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 21:05:06 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/15 21:35:25 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_bool	has_alphanum(char *split)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (split[++i])
		if (ft_isalnum(split[i]))
			count++;
	if (count >= 1)
		return (TRUE);
	return (FALSE);
}

static void	skip_flags(char *token, int *i)
{
	int	j;

	j = *i + 1;
	if (is_flag(token[j]))
		j++;
	while (token[j] && ft_isspace(token[j]))
		j++;
	while (token[j] && !ft_isspace(token[j]))
		j++;
	(*i) = j - 1;
}

static char	*remove_flags(char *token)
{
	int		i;
	int		j;
	char	c;
	char	*new;

	new = malloc(sizeof(char) * ft_strlen(token) + 1);
	i = 0;
	j = -1;
	while (token[i])
	{
		c = token[i];
		if (is_flag(c))
			skip_flags(token, &i);
		if (!is_flag(c) && c != '\'' && c != '"')
			new[++j] = c;
		else if ((c == '\'' || c == '"') && is_closed_quotes(c, token + i))
			str_close_quotes(new, token, &i, &j);
		i++;
	}
	new[++j] = '\0';
	return (new);
}

static void	get_args(t_shell *sh, int num, char *split, int *j)
{
	int		len;
	char	*no_quotes_arg;

	no_quotes_arg = str_remove_quotes(split);
	if (no_quotes_arg && has_alphanum(no_quotes_arg))
	{
		len = ft_strlen(no_quotes_arg);
		sh->cmds[num].args[++(*j)] = (char *)malloc(sizeof(char) * len + 1);
		ft_strlcpy(sh->cmds[num].args[*j], no_quotes_arg, len + 1);
	}
	free(no_quotes_arg);
}

t_status	parse_cmd(t_shell *sh, int num)
{
	int		i;
	int		j;
	char	**split;
	char	*token;

	if (!sh->cmd_tokens[num] || ft_strlen(sh->cmd_tokens[num]) < 1)
		return (ERROR);
	token = remove_flags(sh->cmd_tokens[num]);
	split = split_null_end(token, ' ');
	i = -1;
	j = -1;
	while (split[++i])
		get_args(sh, num, split[i], &j);
	sh->cmds[num].args_count = ++j;
	sh->cmds[num].args[j] = NULL;
	ft_strlcpy(sh->cmds[num].name, split[0], ft_strlen(split[0]) + 1);
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	free(token);
	return (SUCCESS);
}
