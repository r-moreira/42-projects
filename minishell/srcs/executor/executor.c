/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:52:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/19 22:57:25 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	clear_exec_params(t_shell *sh)
{
	sh->fd.open = ANY;
	sh->fd.rd1 = FALSE;
	sh->fd.rd2 = FALSE;
	sh->fd.wr1 = FALSE;
	sh->fd.rd1wr2 = FALSE;
	sh->fd.rd2wr1 = FALSE;
}

static void	define_exec_params(t_shell *sh, int num)
{
	(void)sh;
	(void)num;
}

void	executor(t_shell *sh)
{
	int	i;

	g_pid_number = 0;
	if (DEBUGGER_EXEC)
		executor_debugger_helper(sh);
	i = -1;
	while (++i < sh->count.cmds)
	{
		sh->cmds[i].exec.builtin = FALSE;
		if (is_builtin(sh, i) == FALSE)
			get_cmd_path(sh, i);
		define_exec_params(sh, i);
		exec_cmd(sh, i);
		clear_exec_params(sh);
	}
	clear_execution(sh);
}
