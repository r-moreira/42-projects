/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:10:24 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/17 13:27:26 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	heredoc_aux(t_shell *sh, char *parsed)
{
	char	*input_end;
	char	*tmp;

	tmp = NULL;
	input_end = parse_heredoc_input_end(parsed);
	ft_strlcpy(sh->heredoc_input_end, input_end, HERE_DOCUMENT_INPUT_END_SIZE);
	tmp = ft_remove_substr(parsed, input_end, ft_strlen(parsed));
	ft_strlcpy(sh->input_string, tmp, ft_strlen(tmp) + 1);
	free(input_end);
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
			heredoc_aux(sh, parsed);
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
