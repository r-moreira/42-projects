/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:40:40 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/13 22:55:19 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*cmd_tokenizer(char *input)
{
	int		i;
	int		j;
	char	c;
	char	*token;

	token = (char *)malloc(sizeof(char) * (ft_strlen((char *)input) + 1));
	i = -1;
	j = -1;
	while (input[++i])
	{
		c = input[i];
		if (c == '|')
		{
			token[++j] = c;
			break ;
		}
		else if ((c == '\'' || c == '"') && is_closed_quotes(c, input + i))
			str_close_quotes(token, input, &i, &j);
		else
			token[++j] = c;
	}
	token[++j] = '\0';
	input = NULL;
	return (token);
}

t_status	analyzer(t_shell *sh)
{
	size_t	ptr_pos;
	int		i;

	i = -1;
	ptr_pos = 0;
	while (ptr_pos < ft_strlen(sh->input_string))
	{
		sh->cmd_tokens[++i] = cmd_tokenizer(sh->input_string + ptr_pos);
		printf("CT = [%s]\n", sh->cmd_tokens[i]); //TMP
		if (ft_strncmp(sh->cmd_tokens[i], "", ft_strlen(sh->cmd_tokens[i])))
			ptr_pos += ft_strlen(sh->cmd_tokens[i]);
	}
	sh->count.cmds = i + 1;
	if (sh->count.cmds <= 0)
		return (ERROR);
	return (SUCCESS);
}
