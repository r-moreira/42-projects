/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:18:49 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/19 23:11:04 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
