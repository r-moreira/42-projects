/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_n_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:24:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/23 23:28:30 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	dup_n_close_fd2(t_shell *sh, t_pipe_end end, int fileno)
{
	if (end == READ_END && fileno == STDIN_FILENO)
	{
		if (dup2(sh->fd.two[READ_END], STDIN_FILENO) == -1)
			return (exit_error(ERROR_DUP));
		close(sh->fd.two[READ_END]);
		close(sh->fd.two[WRITE_END]);
	}
	else if (end == WRITE_END && fileno == STDOUT_FILENO)
	{
		if (dup2(sh->fd.two[WRITE_END], STDOUT_FILENO) == -1)
			return (exit_error(ERROR_DUP));
		close(sh->fd.two[READ_END]);
		close(sh->fd.two[WRITE_END]);
	}
}

static void	dup_n_close_fd1(t_shell *sh, t_pipe_end end, int fileno)
{
	if (end == READ_END && fileno == STDIN_FILENO)
	{
		if (dup2(sh->fd.one[READ_END], STDIN_FILENO) == -1)
			return (exit_error(ERROR_DUP));
		close(sh->fd.one[READ_END]);
		close(sh->fd.one[WRITE_END]);
	}
	else if (end == WRITE_END && fileno == STDOUT_FILENO)
	{
		if (dup2(sh->fd.one[WRITE_END], STDOUT_FILENO) == -1)
			return (exit_error(ERROR_DUP));
		close(sh->fd.one[READ_END]);
		close(sh->fd.one[WRITE_END]);
	}
}

void	dup_n_close_pipe(t_shell *sh, t_dup dupinfo)
{
	if (dupinfo.fd == ONE)
		dup_n_close_fd1(sh, dupinfo.end, dupinfo.fileno);
	else if (dupinfo.fd == TWO)
		dup_n_close_fd2(sh, dupinfo.end, dupinfo.fileno);
}

void	dup_n_close_redir_fd(int redir_fd, t_flag flag)
{
	if (flag == REDIRECT_IN || flag == HERE_DOCUMENT)
	{
		dup2(redir_fd, STDIN_FILENO);
		close(redir_fd);
	}
	else if (flag == REDIRECT_OUT || flag == REDIRECT_OUT_APPEND)
	{
		dup2(redir_fd, STDOUT_FILENO);
		close(redir_fd);
	}
}
