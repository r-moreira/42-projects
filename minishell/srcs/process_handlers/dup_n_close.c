/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_n_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:24:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/22 18:05:21 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	debugger_log_aux(int fd, t_pipe_end end, int fileno)
{
	printf("Dupping fd[%d] - Pipe End[%d] - FILENO[%d] ", fd, end, fileno);
}

static void	dup_n_close_fd2(t_shell *sh, t_pipe_end end, int fileno)
{
	if (end == READ_END && fileno == STDIN_FILENO)
	{
		if (DEBUGGER_EXEC)
			debugger_log_aux(2, end, fileno);
		if (dup2(sh->fd.two[READ_END], STDIN_FILENO) == -1)
			return (exit_error(ERROR_DUP));
		close(sh->fd.two[READ_END]);
		close(sh->fd.two[WRITE_END]);
	}
	else if (end == WRITE_END && fileno == STDOUT_FILENO)
	{
		if (DEBUGGER_EXEC)
			debugger_log_aux(2, end, fileno);
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
		if (DEBUGGER_EXEC)
			debugger_log_aux(1, end, fileno);
		if (dup2(sh->fd.one[READ_END], STDIN_FILENO) == -1)
			return (exit_error(ERROR_DUP));
		close(sh->fd.one[READ_END]);
		close(sh->fd.one[WRITE_END]);
	}
	else if (end == WRITE_END && fileno == STDOUT_FILENO)
	{
		if (DEBUGGER_EXEC)
			debugger_log_aux(1, end, fileno);
		if (dup2(sh->fd.one[WRITE_END], STDOUT_FILENO) == -1)
			return (exit_error(ERROR_DUP));
		close(sh->fd.one[READ_END]);
		close(sh->fd.one[WRITE_END]);
	}
}

void	dup_n_close_pipe(t_shell *sh, t_dup dupinfo)
{
	if (dupinfo.flag == NONE)
	{
		if (dupinfo.fd == ONE)
			dup_n_close_fd1(sh, dupinfo.end, dupinfo.fileno);
		else if (dupinfo.fd == TWO)
			dup_n_close_fd2(sh, dupinfo.end, dupinfo.fileno);
	}
}

void	dup_n_close_redir_fd(int redir_fd, t_flag flag)
{
	if (flag == REDIRECT_IN || flag == HERE_DOCUMENT)
	{
		if (DEBUGGER_EXEC)
			printf("Dupping STDIN redirection with flag: %s",
				get_flags_str(flag));
		dup2(redir_fd, STDIN_FILENO);
		close(redir_fd);
	}
	else if (flag == REDIRECT_OUT || flag == REDIRECT_OUT_APPEND)
	{
		if (DEBUGGER_EXEC)
			printf("Dupping STDOUT redirection with flag: %s",
				get_flags_str(flag));
		dup2(redir_fd, STDOUT_FILENO);
		close(redir_fd);
	}
}
