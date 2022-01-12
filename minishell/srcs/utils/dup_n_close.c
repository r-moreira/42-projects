/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_n_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:24:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/12 12:47:31 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	dup_n_close(t_shell *sh, e_fds fd, e_pipe_end end, int fileno)
{
	if (fd == ONE && end == READ_END && fileno == STDIN_FILENO)
	{
		dup2(sh->fd.one[READ_END], STDIN_FILENO);
		close(sh->fd.one[READ_END]);
		close(sh->fd.one[WRITE_END]);
	}
	else if (fd == ONE && end == WRITE_END && fileno == STDOUT_FILENO)
	{
		dup2(sh->fd.one[WRITE_END], STDOUT_FILENO);
		close(sh->fd.one[READ_END]);
		close(sh->fd.one[WRITE_END]);
	}
	else if (fd == TWO && end == READ_END && fileno == STDIN_FILENO)
	{
		dup2(sh->fd.two[READ_END], STDIN_FILENO);
		close(sh->fd.two[READ_END]);
		close(sh->fd.two[WRITE_END]);
	}
	else if (fd == TWO && end == WRITE_END && fileno == STDOUT_FILENO)
	{
		dup2(sh->fd.two[WRITE_END], STDOUT_FILENO);
		close(sh->fd.two[READ_END]);
		close(sh->fd.two[WRITE_END]);
	}
}
