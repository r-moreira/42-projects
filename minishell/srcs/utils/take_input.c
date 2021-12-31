/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:10:24 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/31 15:39:54 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_bool	is_here_document(char *parsed_line)
{
	int	i;

	i = 0;
	while (parsed_line[++i])
		if (parsed_line[i - 1] == '<' && parsed_line[i] == '<')
			return (TRUE);
	return (FALSE);
}

static char	*parse_heredoc_input_end(char *parsed_line)
{
	int		i;
	int		j;
	int		len;
	char	*input_end;

	i = 1;
	while (TRUE)
	{
		if (parsed_line[i - 1] == '<' && parsed_line[i] == '<')
			break ;
		i++;
	}
	while (ft_isspace(parsed_line[i]))
		i++;
	len = ft_strlen(parsed_line);
	input_end = (char *)malloc(sizeof(char) * (len - i) + 1);
	j = -1;
	while (i++ < len)
		if (!ft_isspace(parsed_line[i]))
			input_end[++j] = parsed_line[i];
	input_end[++j] = '\0';
	return (input_end);
}

static char	*take_heredoc_input(t_shell *sh, char *input_end)
{
	char	*heredoc_input;
	char	*hdoc_line_read;
	char	*parsed_heredoc_in;
	char	*tmp_ptr;

	heredoc_input = ft_strdup("");
	while (TRUE)
	{
		hdoc_line_read = readline("> ");
		if (hdoc_line_read && *hdoc_line_read)
		{
			if (!ft_strncmp(input_end, hdoc_line_read, sizeof(input_end)))
				break ;
			tmp_ptr = heredoc_input;
			heredoc_input = ft_strjoin(
					ft_strcat(heredoc_input, "\n"), hdoc_line_read);
			free(hdoc_line_read);
			free(tmp_ptr);
		}
		else if (hdoc_line_read == NULL)
			eof_exit_shell(sh);
	}
	parsed_heredoc_in = parse_env_variables(heredoc_input);
	free(heredoc_input);
	return (parsed_heredoc_in);
}

static t_status	handle_here_document_input(t_shell *sh, char *parsed_line)
{
	char	*input_end;
	char	*tmp;

	input_end = parse_heredoc_input_end(parsed_line);
	if (input_end[0] == '\0')
		return (syntax_error("Heredoc '<<' doesn't contain an input ending."));
	sh->heredoc_file_buffer = take_heredoc_input(sh, input_end);
	tmp = ft_remove_substr(parsed_line, input_end, ft_strlen(parsed_line));
	ft_strlcpy(sh->input_string, tmp, ft_strlen(tmp) + 1);
	free(parsed_line);
	free(input_end);
	free(tmp);
	return (SUCCESS);
}

t_status	take_input(t_shell *sh)
{
	char	*line_read;
	char	*parsed_line;

	line_read = readline(NULL);
	if (line_read && *line_read)
	{
		add_history(line_read);
		parsed_line = parse_env_variables(line_read);
		if (is_here_document(parsed_line) == TRUE)
		{
			if (handle_here_document_input(sh, parsed_line) == ERROR)
				return (ERROR);
		}
		else
		{
			ft_strlcpy(sh->input_string, parsed_line,
				ft_strlen(parsed_line) + 1);
			free(parsed_line);
		}
	}
	else if (line_read == NULL)
		eof_exit_shell(sh);
	free(line_read);
	return (SUCCESS);
}
