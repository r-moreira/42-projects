/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:52:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/16 00:23:24 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	call_exec(t_shell *sh, int num)
{
	t_bool	pipe_last_cmd;
	t_bool	pipe;
	t_bool	redout;
	t_bool	redin;

	redout = FALSE;
	redin = FALSE;
	pipe_last_cmd = FALSE;
	pipe = sh->cmds[num].pipe;
	if (sh->cmds[num].redout.len > 0 || sh->cmds[num].redout_apd.len > 0)
		redout = TRUE;
	if (sh->cmds[num].redin.len > 0 || sh->cmds[num].heredoc)
		redin = TRUE;
	if (num > 0)
		pipe_last_cmd = sh->cmds[num - 1].pipe;
	if (redin)
		handle_input_redir(sh, num);
	if (redout)
		handle_output_redir(sh, num);
	if (pipe || pipe_last_cmd)
		handle_pipes(sh, num, pipe, pipe_last_cmd);
	if (!pipe_last_cmd && !pipe && !redout && !redin)
		exec_no_flags(sh, num);
}

//////////////////TO-DOs
// Lidar com as flags (Process Handlers, Pipe, Dup2 e afins..)
//		- Built-ins e Não Built-ins
// Adicionar log de execução nos built-ins
// Lidar com signals
// Garantir o retorno do PID para: "$?"
/////////////////////////
void	executor(t_shell *sh)
{
	int	i;

	sh->fd.open = ANY;
	if (DEBUGGER_EXEC)
		executor_debugger_helper(sh);
	i = -1;
	while (++i < sh->count.cmds)
		if (handle_builtin(sh, i) == NOT_BUILT_IN)
			if (get_cmd_path(sh, i) == SUCCESS)
				call_exec(sh, i);
	clear_execution(sh);
}
