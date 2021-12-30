/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:10:24 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/30 20:26:58 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_bool	is_here_document(char *line_read)
{
	int	i;

	i = 0;
	while (line_read[++i])
		if (line_read[i - 1] == '<' && line_read[i] == '<')
			return (TRUE);
	return (FALSE);
}

static char	*parse_heredoc_input_ending(char *line_read)
{
	int		i;
	int		j;
	int		len;
	char	*input_ending;

	i = 1;
	while (line_read[i - 1] != '<' && line_read[i] != '<')
		i++;
	i += 2;
	len = ft_strlen(line_read);
	input_ending = (char *)malloc(sizeof(char) * (len - i) + 10);
	j = -1;
	while (i++ < len)
		if (!ft_isspace(line_read[i]))
			input_ending[++j] = line_read[i];
	input_ending[++j] = '\0';
	return (input_ending);
}

static char	*take_heredoc_input(t_shell *sh, char *input_ending)
{
	char	*heredoc_input;
	char	*hdoc_line_read;
	char	*parsed_heredoc_in;

	heredoc_input = (char *)malloc(HERE_DOCUMENT_BUFFER_SIZE);
	while (TRUE)
	{
		hdoc_line_read = readline("> ");
		if (hdoc_line_read && *hdoc_line_read)
		{
			if (!ft_strncmp(input_ending, hdoc_line_read, sizeof(input_ending)))
				break ;
			ft_strcat(heredoc_input, hdoc_line_read);
			ft_strcat(heredoc_input, "\n");
			free(hdoc_line_read);
		}
		else
			eof_exit_shell(sh);
	}
	parsed_heredoc_in = parse_env_variables(heredoc_input);
	return (parsed_heredoc_in);
}

static t_status	handle_here_document_input(t_shell *sh, char *line_read)
{
	char	*input_ending;

	input_ending = parse_heredoc_input_ending(line_read);
	if (input_ending[0] == '\0')
		return (syntax_error("Heredoc '<<' doesn't contain an input ending."));
	sh->heredoc_file_buffer = take_heredoc_input(sh, input_ending);
	free(input_ending);
	return (SUCCESS);
}

//TO-DO
//FIX heredoc memory leak
//FIX exit on empty heredoc line
//FIX heredoc with multiple flags, ex: wc -l | oi > viv >> kk < aaa << EOF
//Remove heredoc inpud ending from input string
t_status	take_input(t_shell *sh)
{
	char	*line_read;
	char	*parsed_line_read;

	line_read = readline(NULL);
	if (line_read && *line_read)
	{
		add_history(line_read);
		parsed_line_read = parse_env_variables(line_read);
		if (is_here_document(parsed_line_read) == TRUE)
			if (handle_here_document_input(sh, parsed_line_read) == ERROR)
				return (ERROR);
		ft_strlcpy(sh->input_string, parsed_line_read,
			ft_strlen(parsed_line_read) + 1);
		free(parsed_line_read);
	}
	else
		eof_exit_shell(sh);
	free(line_read);
	return (SUCCESS);
}
