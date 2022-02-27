/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:10:24 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/26 21:04:36 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_status	heredoc_aux(t_shell *sh, char *parsed)
{
	char	*input_end;

	input_end = parse_heredoc_input_end(parsed);
	if (input_end[0] == '\0')
	{
		free(parsed);
		free(input_end);
		return (syntax_error(ERROR_HEREDOC));
	}
	ft_strlcpy(sh->heredoc_input_end, input_end, HERE_DOCUMENT_INPUT_END_SIZE);
	ft_strlcpy(sh->input_string, parsed, ft_strlen(parsed) + 1);
	free(input_end);
	return (SUCCESS);
}

t_status	take_input(t_shell *sh)
{
	char	*line_read;
	char	*parsed;
	char	*prompt;

	prompt = create_prompt();
	line_read = readline(prompt);
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
	free(prompt);
	return (SUCCESS);
}
