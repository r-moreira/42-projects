/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:10:24 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/12 21:58:50 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_status	heredoc_aux(t_shell *sh, char *parsed)
{
	char	*input_end;
	char	*tmp;

	tmp = NULL;
	input_end = parse_heredoc_input_end(parsed);
	if (input_end[0] == '\0')
	{
		free(parsed);
		free(input_end);
		return (syntax_error(ERROR_HEREDOC));
	}
	ft_strlcpy(sh->heredoc_input_end, input_end, HERE_DOCUMENT_INPUT_END_SIZE);
	tmp = ft_remove_substr(parsed, input_end, ft_strlen(parsed));
	ft_strlcpy(sh->input_string, tmp, ft_strlen(tmp) + 1);
	free(tmp);
	free(input_end);
	return (SUCCESS);
}

t_status	take_input(t_shell *sh)
{
	char	*line_read;
	char	*parsed;

	line_read = readline(NULL);
	if (line_read && *line_read)
	{
		add_history(line_read);
		parsed = parse_env_variables(line_read);
		if (is_here_document(parsed))
		{
			if (heredoc_aux(sh, parsed) == ERROR)
				return (ERROR);
		}
		else
			ft_strlcpy(sh->input_string, parsed, ft_strlen(parsed) + 1);
		free(parsed);
	}
	else if (line_read == NULL)
		eof_exit_shell(sh);
	else
		printf("\n");
	free(line_read);
	return (SUCCESS);
}
