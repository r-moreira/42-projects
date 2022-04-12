/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 00:30:33 by romoreir          #+#    #+#             */
/*   Updated: 2022/03/15 18:58:23 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_status	error_invalid_flags(t_shell *sh)
{
	int	i;

	i = -1;
	while (++i < sh->count.cmds)
		free(sh->cmd_tokens[i]);
	return (syntax_error(ERROR_INVLD_FLAG));
}

t_status	error_no_alphanum(t_shell *sh)
{
	int		i;
	int		j;
	t_bool	has_only_whitespaces;

	has_only_whitespaces = TRUE;
	i = -1;
	while (++i < sh->count.cmds)
	{
		j = 0;
		while (sh->cmd_tokens[i][j])
		{
			if (!ft_isspace(sh->cmd_tokens[i][j]))
				has_only_whitespaces = FALSE;
			j++;
		}
	}
	i = -1;
	while (++i < sh->count.cmds)
		free(sh->cmd_tokens[i]);
	if (has_only_whitespaces)
		return (SUCCESS);
	return (syntax_error(ERROR_NO_ALPNUM));
}
