/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:18:49 by romoreir          #+#    #+#             */
/*   Updated: 2022/03/02 00:14:37 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	close_parent_fd(t_shell *sh)
{
	if (sh->fd.rd1 || sh->fd.rd1wr2)
	{
		close(sh->fd.one[READ_END]);
		close(sh->fd.one[WRITE_END]);
	}
	else if (sh->fd.rd2 || sh->fd.rd2wr1)
	{
		close(sh->fd.two[READ_END]);
		close(sh->fd.two[WRITE_END]);
	}
}

static void	exec_fork(t_shell *sh, int num)
{
	pid_t	pid;

	handle_pipe(sh, num);
	pid = handle_fork();
	run_signals_exec();
	if (pid == FORKED_CHILD)
	{
		handle_io(sh, num);
		handle_dup(sh, num);
		if (sh->cmds[num].exec.builtin)
			exec_builtin(sh, num);
		else if (execve(sh->cmds[num].path, sh->cmds[num].args,
				sh->envs) == -1)
			exit_error(ERROR_EXEC);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close_parent_fd(sh);
		wait_aux(pid);
	}
}

void	exec_cmd(t_shell *sh, int num)
{
	if (!has_non_fork_builtins(sh, num))
		exec_fork(sh, num);
	else
		call_builtin(sh, num);
}
