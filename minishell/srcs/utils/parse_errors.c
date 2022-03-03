/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 00:30:33 by romoreir          #+#    #+#             */
/*   Updated: 2022/03/03 00:30:49 by romoreir         ###   ########.fr       */
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
	int	i;

	i = -1;
	while (++i < sh->count.cmds)
		free(sh->cmd_tokens[i]);
	return (syntax_error(ERROR_NO_ALPNUM));
}
