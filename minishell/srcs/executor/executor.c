/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:52:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/19 20:40:22 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_bool is_noflags(t_shell *sh, int num)
{
	if (!sh->cmds[num].exec.pipe
		&& !sh->cmds[num].exec.pipe
		&& !sh->cmds[num].exec.redin
		&& !sh->cmds[num].exec.heredoc
		&& !sh->cmds[num].exec.redout
		&& !sh->cmds[num].exec.redout_apd)
		return (TRUE);
	return (FALSE);
}

static void	call_exec(t_shell *sh, int num)
{
	if (is_noflags(sh, num))
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
