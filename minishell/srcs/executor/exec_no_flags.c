/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_no_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:18:49 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/18 20:37:57 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_no_flags(t_shell *sh, int num)
{
	pid_t	pid;

	if (DEBUGGER_EXEC)
		exec_debugger_helper(sh, num, "No Flags = |Write STDOUT|");
	if (!has_non_fork_builtins(sh, num))
	{
		pid = fork();
		if (pid == -1)
			exit_error(ERROR_FORK);
		if (pid == FORKED_CHILD)
		{
			run_signals_exec();
			if (sh->cmds[num].builtin)
				exec_builtin(sh, num);
			else if (execve(sh->cmds[num].path, sh->cmds[num].args,
					sh->envs) == -1)
				exit_error(ERROR_EXEC);
			exit(EXIT_SUCCESS);
		}
		else
			wait_aux(pid);
	}
	else
		call_builtin(sh, num);
}
