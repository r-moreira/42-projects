/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:40:40 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/30 14:25:33 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_bool	is_closed_quotes(char c, char *input)
{
	int	i;

	i = 0;
	if (c == '\'' || c == '"')
	{
		while (input[++i]) {
			if (input[i] == c)
				return (TRUE);
		}
		return (FALSE);
	}
	else
		return (FALSE);
}

//TO-DO
//Add function to 42 NORM
static char	*cmd_tokenizer(char *input)
{
	int		i;
	char	*token;
	t_bool	has_open_quotes;
	char	quote;

	has_open_quotes = FALSE;
	token = (char *)malloc(sizeof(char) * (ft_strlen((char *)input) + 1));
	i = -1;
	while (input[++i])
	{
		if (!has_open_quotes && is_closed_quotes(input[i], input + i))
		{
			quote = input[i];
			has_open_quotes = TRUE;
		}
		else if (has_open_quotes && input[i] == quote)
			has_open_quotes = FALSE;
		if (!has_open_quotes)
		{
			if (input[i] != '|' && input[i] != '>' && input[i] != '<')
				token[i] = input[i];
			else
			{
				token[i] = input[i];
				if (input[i + 1] == '>' || input[i + 1] == '<')
				{
					i++;
					token[i] = input[i];
				}
				token[++i] = '\0';
				return (token);
			}
		}
		else
			token[i] = input[i];
	}
	token[i] = '\0';
	input = NULL;
	return (token);
}

t_status	analyzer(t_shell *sh)
{
	int		pointer_position;
	int		i;

	printf("INPUT = [%s]\n", sh->input_string); //TMP

	i = -1;
	pointer_position = 0;
	while (pointer_position < ft_strlen(sh->input_string))
	{
		sh->cmd_tokens[++i] = cmd_tokenizer(sh->input_string + pointer_position);
		if (ft_strncmp(sh->cmd_tokens[i], "", ft_strlen(sh->cmd_tokens[i])))
			pointer_position += ft_strlen(sh->cmd_tokens[i]);
	}
	sh->cmds_count = i + 1;
	if (sh->cmds_count <= 0)
		return (ERROR);
	return (SUCCESS);
}
