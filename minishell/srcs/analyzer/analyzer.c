/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:40:40 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/26 21:02:19 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//TO-DO: Salvar as flags do comando na struct
/*static void	parse_cmd_flag(t_shell *sh, char *cmd_token)
{
	char	c;
	int		i;
	int		flag_count;

	flag_count = 0;
	i = -1;

	while (++i < sh->cmds_count)
	{
		//skip quotes: " or '
		c = cmd_token[i];
		if (c == '|')
			sh->cmds[0].flag = PIPE;
		else if
	}
}*/

/*static void	*handle_flags(char c, char c2, int i, char *token)
{
	if (c != '|' && c != '>' && c != '<')
		token[i] = c;
	else
	{
		token[i] = c;
		if (c2 == '>' || c2 == '<')
			token[++i] = c2;
		token[++i] = '\0';
	}
}*/

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

static void	parse_cmds(t_shell *sh, char **cmd_tokens)
{
	int	i;

	i = -1;
	while (++i < sh->cmds_count)
	{
		printf("cmd_token[%d] = %s\n", i, cmd_tokens[i]); //TEMP
		//parse_cmd_flag(sh, cmd_tokens[i]);
		//parse_cmd_bin
		//parse_cmd_args
	}
}

void	analyzer(t_shell *sh)
{
	char	*cmd_tokens[MAX_COMMANDS_NUM];
	int		pointer_position;
	int		i;

	printf("INPUT = [%s]\n", sh->input_string); //TMP

	i = -1;
	pointer_position = 0;
	while (pointer_position < ft_strlen(sh->input_string))
	{
		cmd_tokens[++i] = cmd_tokenizer(sh->input_string + pointer_position);
		if (ft_strncmp(cmd_tokens[i], "", ft_strlen(cmd_tokens[i])))
			pointer_position += ft_strlen(cmd_tokens[i]);
	}
	sh->cmds_count = i + 1;
	parse_cmds(sh, cmd_tokens);
	while (i-- > 0)
		free(cmd_tokens[i]);
}
