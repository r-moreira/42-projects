/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:10:24 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/19 12:08:01 by romoreir         ###   ########.fr       */
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
	return FALSE;
}

static char *parse_heredoc_input_ending(char *line_read, char *input_ending)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (line_read[i - 1] != '<' && line_read[i] != '<')
		i++;
	i += 2;
	len = ft_strlen(line_read);
	input_ending = (char *)malloc(sizeof(char) * (len - i) + 1);
	j = -1;
	while (i++ < len)
		if(!ft_isspace(line_read[i]))
			input_ending[++j] = line_read[i];
	input_ending[++j] = '\0';
	return (input_ending);
}

static char *take_heredoc_input(char *input_ending)
{
	char	*heredoc_input;
	char	*hdoc_line_read;
	char	*parsed_heredoc_in;

	heredoc_input = (char*)malloc(HERE_DOCUMENT_BUFFER_SIZE);
	while (TRUE)
	{
		hdoc_line_read = readline("> ");
		if (!ft_strncmp(input_ending, hdoc_line_read, sizeof(input_ending)))
			break;
		ft_strcat(heredoc_input, hdoc_line_read);
		ft_strcat(heredoc_input, "\n");
		free(hdoc_line_read);
	}
	parsed_heredoc_in = parse_env_variables(heredoc_input);
	return (parsed_heredoc_in);
}

//TO-DO
//Lidar com o SIGNAL CONTROL-C, entre outros
static t_status handle_here_document_input(t_shell *sh, char *line_read)
{
	int		len;
	char	*input_ending;

	input_ending = parse_heredoc_input_ending(line_read, input_ending);
	if (input_ending[0] == '\0')
		return (print_error("Heredoc '<<' doesn't contain an input ending."));
	sh->heredoc_file_buffer = take_heredoc_input(input_ending);
	printf("Heredoc FB = \n%s\n", sh->heredoc_file_buffer); //TEMP
	free(input_ending);
	return (SUCCESS);
}

t_status	take_input(t_shell *sh)
{
	char	*line_read;
	char	*parsed_line_read;
	char	quote;

	line_read = readline(" $> ");
	if (strlen(line_read) != 0)
	{
		if (line_read && *line_read)
		{
			add_history(line_read);
			parsed_line_read = parse_env_variables(line_read);
			if (is_here_document(parsed_line_read) == TRUE)
			{
				if(handle_here_document_input(sh, parsed_line_read) == ERROR)
					return ERROR;
			}
			else
				ft_strlcpy(sh->input_string, parsed_line_read,
					ft_strlen(parsed_line_read) + 1);
		}
	}
	free(line_read);
	free(parsed_line_read);
	return (SUCCESS);
}
