/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:12:09 by romoreir          #+#    #+#             */
/*   Updated: 2022/03/02 23:44:02 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_aux(char *p1, char *p2)
{
	free(p1);
	free(p2);
}

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
			free_aux(tmp_ptr, hdoc_line_read);
		}
		else
			exit(EXIT_SUCCESS);
	}
	parsed_heredoc_in = parse_env_variables(heredoc_input);
	free(heredoc_input);
	return (parsed_heredoc_in);
}

t_status	handle_here_document_input(t_shell *sh, int num)
{
	int		i;
	char	*hdoc_fb;

	i = -1;
	while (++i < sh->cmds[num].heredoc.len)
	{
		if (sh->cmds[num].heredoc.input_end[i][0] == '\0')
			return (syntax_error(ERROR_HEREDOC));
		hdoc_fb = take_heredoc_input(sh->cmds[num].heredoc.input_end[i]);
		ft_strlcpy(sh->cmds[num].heredoc.file_buffer[i], hdoc_fb, ft_strlen(hdoc_fb) + 1);
		free(hdoc_fb);
	}
	return (SUCCESS);
}
