/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:52:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/22 11:01:47 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	call_exec(t_shell *sh, int num)
{
	(void)sh;
	(void)num;
}

static void	setup_exec(t_shell *sh, int num)
{
	(void)sh;
	(void)num;
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
		setup_exec(sh, i);
		call_exec(sh, i);
	}
	clear_execution(sh);
}
