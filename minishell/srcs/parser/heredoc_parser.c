/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:19:59 by romoreir          #+#    #+#             */
/*   Updated: 2022/03/03 00:06:00 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_heredoc_input_end(char *token)
{
	int		i;
	int		j;
	int		len;
	char	*input_end;

	i = 0;
	while (ft_isspace(token[i]))
		i++;
	len = ft_strlen(token);
	input_end = (char *)malloc(sizeof(char) * (len - i) + 1);
	j = -1;
	while (i < len && !is_flag(token[i]) && !ft_isspace(token[i]))
		input_end[++j] = token[i++];
	input_end[++j] = '\0';
	return (input_end);
}

t_status	parse_heredoc_input_end(t_shell *sh, int num, char *token)
{
	char	*input_end;

	input_end = get_heredoc_input_end(token);
	if (input_end[0] == '\0')
	{
		free(token);
		free(input_end);
		return (syntax_error(ERROR_HEREDOC));
	}
	ft_strlcpy(sh->cmds[num].heredoc.input_end[sh->cmds[num].heredoc.len],
		input_end, HERE_DOCUMENT_INPUT_END_SIZE);
	free(input_end);
	return (SUCCESS);
}
