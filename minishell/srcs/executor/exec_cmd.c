/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:18:49 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/19 22:55:39 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void handle_pipe(t_shell *sh, int num)
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

static pid_t handle_fork()
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_error(ERROR_FORK);
	return (pid);
}

static void handle_dup(t_shell *sh)
{
	if (sh->fd.wr1)
		dup_n_close(sh, ONE, WRITE_END, STDOUT_FILENO);
	else if (sh->fd.rd1)
		dup_n_close(sh, ONE, READ_END, STDIN_FILENO);
	else if (sh->fd.rd2)
		dup_n_close(sh, TWO, READ_END, STDIN_FILENO);
	else if (sh->fd.rd1wr2)
	{
		dup_n_close(sh, ONE, READ_END, STDIN_FILENO);
		dup_n_close(sh, TWO, WRITE_END, STDOUT_FILENO);
	}
	else if (sh->fd.rd2wr1)
	{
		dup_n_close(sh, TWO, READ_END, STDIN_FILENO);
		dup_n_close(sh, ONE, WRITE_END, STDOUT_FILENO);
	}
}

void	exec_fork(t_shell *sh, int num)
{
	pid_t	pid;

	handle_pipe(sh, num);
	pid = handle_fork();
	if (pid == FORKED_CHILD)
	{
		run_signals_exec();
		handle_dup(sh);
		if (sh->cmds[num].exec.builtin)
			exec_builtin(sh, num);
		else if (execve(sh->cmds[num].path, sh->cmds[num].args,
				sh->envs) == -1)
			exit_error(ERROR_EXEC);
		exit(EXIT_SUCCESS);
	}
	else
		wait_aux(pid);
}


void	exec_cmd(t_shell *sh, int num)
{

	if (DEBUGGER_EXEC)
		exec_debugger_helper(sh, num);
	if (!has_non_fork_builtins(sh, num))
		exec_fork(sh, num);
	else
		call_builtin(sh, num);
}
