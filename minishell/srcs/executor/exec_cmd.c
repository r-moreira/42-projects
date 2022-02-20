/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:18:49 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/20 16:35:16 by romoreir         ###   ########.fr       */
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
		handle_io(sh, num);
		if (DEBUGGER_EXEC)
			printf("======= CMD[%d] STDOUT =========\n", num);
		handle_dup(sh, num);
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
	if (!has_non_fork_builtins(sh, num))
		exec_fork(sh, num);
	else
		call_builtin(sh, num);
	if (DEBUGGER_EXEC && sh->count.cmds == num + 1)
		printf("======== End Execution ========\n");
}
