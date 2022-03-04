/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:10:24 by romoreir          #+#    #+#             */
/*   Updated: 2022/03/04 02:44:38 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_bool	is_pipe_end(char *parsed)
{
	int		i;
	char	last_char;

	last_char = '\0';
	i = -1;
	while (parsed[++i])
	{
		if (!ft_isspace(parsed[i]))
			last_char = parsed[i];
	}
	if (last_char == '|')
		return (TRUE);
	return (FALSE);
}

static void	handle_pipe_end(t_shell *sh, char *parsed)
{
	char	*new;
	char	*pipe_arg;

	pipe_arg = readline("> ");
	if (pipe_arg && *pipe_arg)
	{
		new = ft_strjoin(parsed, pipe_arg);
		ft_strlcpy(sh->input_string, new, ft_strlen(new) + 1);
		free(new);
	}
	free(pipe_arg);
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
		if (is_pipe_end(parsed))
			handle_pipe_end(sh, parsed);
		else
			ft_strlcpy(sh->input_string, parsed, ft_strlen(parsed) + 1);
		free(parsed);
	}
	else if (line_read == NULL)
		eof_exit_shell(sh);
	free(line_read);
	free(prompt);
	return (SUCCESS);
}
