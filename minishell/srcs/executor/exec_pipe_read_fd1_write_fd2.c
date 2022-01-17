/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_read_fd1_write_fd2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:20:55 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/16 21:39:33 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	exec_fork(t_shell *sh, int num)
{
	pid_t	pid;

	if (pipe(sh->fd.two) == -1)
		exit_error(ERROR_PIPE_FD);
	sh->fd.open = TWO;
	pid = fork();
	if (pid == -1)
		exit_error(ERROR_FORK);
	if (pid == FORKED_CHILD)
	{
		dup_n_close(sh, ONE, READ_END, STDIN_FILENO);
		dup_n_close(sh, TWO, WRITE_END, STDOUT_FILENO);
		if (sh->cmds[num].builtin)
			exec_builtin(sh, num);
		else if (execve(sh->cmds[num].path, sh->cmds[num].args, sh->envs) == -1)
			exit_error(ERROR_EXEC);
		else
			exit(EXIT_SUCCESS);
	}
	else
	{
		close_fd(sh, ONE);
		g_pid_number = waitpid(pid, NULL, 0);
	}
}

void	exec_pipe_read_fd1_write_fd2(t_shell *sh, int num)
{
	if (DEBUGGER_EXEC)
		exec_debugger_helper(sh, num, "Pipe    = |Read FD1 - Write FD2|\n");
	if (!has_non_fork_builtins(sh, num))
		exec_fork(sh, num);
	else
		exec_builtin(sh, num);
}
