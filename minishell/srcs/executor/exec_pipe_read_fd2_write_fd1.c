/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_read_fd2_write_fd1.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:21:23 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/18 20:22:05 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	exec_fork(t_shell *sh, int num)
{
	pid_t	pid;

	if (pipe(sh->fd.one) == -1)
		exit_error(ERROR_PIPE_FD);
	sh->fd.open = ONE;
	pid = fork();
	if (pid == -1)
		exit_error(ERROR_FORK);
	if (pid == FORKED_CHILD)
	{
		run_signals_exec();
		dup_n_close(sh, TWO, READ_END, STDIN_FILENO);
		dup_n_close(sh, ONE, WRITE_END, STDOUT_FILENO);
		if (sh->cmds[num].builtin)
			exec_builtin(sh, num);
		else if (execve(sh->cmds[num].path, sh->cmds[num].args, sh->envs) == -1)
			exit_error(ERROR_EXEC);
		else
			exit(EXIT_SUCCESS);
	}
	else
	{
		close_fd(sh, TWO);
		wait_aux(pid);
	}
}

void	exec_pipe_read_fd2_write_fd1(t_shell *sh, int num)
{
	if (DEBUGGER_EXEC)
		exec_debugger_helper(sh, num, "Pipe    = |Read FD2 - Write FD1|\n");
	if (!has_non_fork_builtins(sh, num))
		exec_fork(sh, num);
	else
		call_builtin(sh, num);
}
