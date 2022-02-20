/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:07:38 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/19 23:10:13 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_pipe(t_shell *sh, int num)
{
	if (sh->cmds[num].exec.pipe)
	{
		if (sh->fd.wr1 || sh->fd.rd2wr1)
		{
			if (pipe(sh->fd.one) == -1)
				exit_error(ERROR_PIPE_FD);
			sh->fd.open = ONE;
		}
		else if (sh->fd.rd1wr2)
		{
			if (pipe(sh->fd.two) == -1)
				exit_error(ERROR_PIPE_FD);
			sh->fd.open = TWO;
		}
	}
}
