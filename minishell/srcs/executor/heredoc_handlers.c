/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:12:09 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/17 13:00:36 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*take_heredoc_input(char *input_end)
{
	char	*heredoc_input;
	char	*hdoc_line_read;
	char	*parsed_heredoc_in;
	char	*tmp_ptr;

	tmp_ptr = NULL;
	hdoc_line_read = NULL;
	heredoc_input = ft_strdup("");
	while (TRUE)
	{
		hdoc_line_read = readline("> ");
		if (hdoc_line_read && *hdoc_line_read)
		{
			if (!ft_strncmp(input_end, hdoc_line_read, sizeof(input_end)))
				break ;
			tmp_ptr = heredoc_input;
			heredoc_input = strjoin_newline(heredoc_input, hdoc_line_read);
			free(tmp_ptr);
			free(hdoc_line_read);
		} else
			exit(EXIT_SUCCESS);
	}
	parsed_heredoc_in = parse_env_variables(heredoc_input);
	free(heredoc_input);
	return (parsed_heredoc_in);
}

t_status	handle_here_document_input(t_shell *sh)
{
	char	*hdoc_fb;

	if (sh->heredoc_input_end[0] == '\0')
		return (syntax_error(ERROR_HEREDOC));
	hdoc_fb = take_heredoc_input(sh->heredoc_input_end);
	ft_strlcpy(sh->heredoc_file_buffer, hdoc_fb, ft_strlen(hdoc_fb) + 1);
	free(hdoc_fb);
	return (SUCCESS);
}
