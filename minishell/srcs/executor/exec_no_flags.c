/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_no_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:18:49 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/16 19:48:55 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	exec_builtin(t_shell *sh, int num)
{
	call_builtin(sh, num);
	printf("%s", sh->builtin_out);
}

void	exec_no_flags(t_shell *sh, int num)
{
	int		status;
	pid_t	pid;

	if (DEBUGGER_EXEC)
		exec_debugger_helper(sh, num, "No Flags = |Write STDOUT|");
	pid = fork();
	if (pid == -1)
		exit_error(ERROR_FORK);
	if (pid == FORKED_CHILD)
	{
		if (sh->cmds[num].builtin)
			exec_builtin(sh, num);
		else if (execve(sh->cmds[num].path, sh->cmds[num].args, sh->envs) == -1)
			exit_error(ERROR_EXEC);
		exit(EXIT_SUCCESS);
	}
	else
		g_pid_number = wait(&status);
}
