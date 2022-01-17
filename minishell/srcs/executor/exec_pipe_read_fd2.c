/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_read_fd2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:20:16 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/17 09:38:29 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	exec_fork(t_shell *sh, int num)
{
	pid_t	pid;

	sh->fd.open = ANY;
	pid = fork();
	if (pid == -1)
		exit_error(ERROR_FORK);
	if (pid == FORKED_CHILD)
	{
		dup_n_close(sh, TWO, READ_END, STDIN_FILENO);
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
		g_pid_number = waitpid(pid, NULL, 0);
	}
}

void	exec_pipe_read_fd2(t_shell *sh, int num)
{
	if (DEBUGGER_EXEC)
		exec_debugger_helper(sh, num, "Pipe    = |Read FD2|\n");
	if (!has_non_fork_builtins(sh, num))
		exec_fork(sh, num);
	else
		call_builtin(sh, num);
}
