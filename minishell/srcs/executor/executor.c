/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:52:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/12 21:30:23 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	call_exec(t_shell *sh, int num)
{
	exec_no_flags(sh, num);
}

void	executor(t_shell *sh)
{
	int	i;

	g_pid_number = 0;
	sh->fd.open = ANY;
	if (DEBUGGER_EXEC)
		executor_debugger_helper(sh);
	i = -1;
	while (++i < sh->count.cmds)
	{
		sh->cmds[i].exec.builtin = FALSE;
		if (is_builtin(sh, i) == FALSE)
			get_cmd_path(sh, i);
		call_exec(sh, i);
	}
	clear_execution(sh);
}
