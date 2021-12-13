/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:10:24 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/12 21:59:48 by romoreir         ###   ########.fr       */
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

static char *take_heredoc_input_ending(char *line_read, char *input_ending)
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

//TO-DO
//Loop com prompt = '>'
//Ler e concatenar a string em cada loop até o input ending
//Concatenar como um argumento para o comando na string line_read
static t_status take_here_document_input(char *line_read)
{
	int		len;
	char	*input_ending;

	input_ending = take_heredoc_input_ending(line_read, input_ending);
	if (input_ending[0] == '\0')
		return (print_error("Here document '<<' doesn't contain an input ending."));
	free(input_ending);
	return (SUCCESS);
}

//TO-DO:
//substituir "$VAR" pelo valor correspondente
static void	handle_variables(char *line_read)
{
	(void)line_read;
}

//TO-DO:
//3) Free line read?
t_status	take_input(t_shell *sh)
{
	char	*line_read;
	char	quote;

	line_read = readline(" $> ");
	if (strlen(line_read) != 0)
	{
		if (line_read && *line_read)
		{
			add_history(line_read);
			handle_variables(line_read);
			if (is_here_document(line_read) == TRUE)
			{
				if(take_here_document_input(line_read) == ERROR)
					return ERROR;
			}
			else
				ft_strlcpy(sh->input_string, line_read, ft_strlen(line_read) + 1);
		}
	}
	return (SUCCESS);
}
