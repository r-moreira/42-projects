/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:40:40 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/02 13:29:41 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	handle_quotes(t_bool *has_open_quotes, char c, char *i, char quote)
{
	if (!has_open_quotes && is_closed_quotes(c, i))
	{
		quote = c;
		*has_open_quotes = TRUE;
	}
	else if (has_open_quotes && c == quote)
		*has_open_quotes = FALSE;
	return (quote);
}

static char	*handle_2char_flags(char *input, char *token, int i)
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

static char	*cmd_tokenizer(char *input)
{
	int		i;
	char	*token;
	t_bool	has_open_quotes;
	char	quote;

	has_open_quotes = FALSE;
	token = (char *)malloc(sizeof(char) * (ft_strlen((char *)input) + 1));
	i = -1;
	quote = '\0';
	while (input[++i])
	{
		quote = handle_quotes(&has_open_quotes, input[i], input + i, quote);
		if (!has_open_quotes)
		{
			if (input[i] != '|' && input[i] != '>' && input[i] != '<')
				token[i] = input[i];
			else
				return (handle_2char_flags(input, token, i));
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
	size_t	ptr_pos;
	int		i;

	if (DEBUGGER)
		printf("INPUT = [%s]\n", sh->input_string);
	i = -1;
	ptr_pos = 0;
	while (ptr_pos < ft_strlen(sh->input_string))
	{
		sh->cmd_tokens[++i] = cmd_tokenizer(sh->input_string + ptr_pos);
		if (ft_strncmp(sh->cmd_tokens[i], "", ft_strlen(sh->cmd_tokens[i])))
			ptr_pos += ft_strlen(sh->cmd_tokens[i]);
	}
	sh->cmds_count = i + 1;
	if (sh->cmds_count <= 0)
		return (ERROR);
	return (SUCCESS);
}
