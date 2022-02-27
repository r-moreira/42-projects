/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:52:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/26 19:20:12 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_fd_info(t_shell *sh, t_bool pipe, t_bool pipe_last_cmd)
{
	printf("Handling Pipes...\n");
	printf("PIPE       = |%s|\n", get_bool_str(pipe));
	printf("PIPELSTCMD = |%s|\n", get_bool_str(pipe_last_cmd));
	printf("FD Open    = |%d|\n", sh->fd.open);
	printf("FD RD1     = |%s|\n", get_bool_str(sh->fd.rd1));
	printf("FD RD2     = |%s|\n", get_bool_str(sh->fd.rd2));
	printf("FD WR1     = |%s|\n", get_bool_str(sh->fd.wr1));
	printf("FD RD1WR2  = |%s|\n", get_bool_str(sh->fd.rd1wr2));
	printf("FD RD2WR1  = |%s|\n", get_bool_str(sh->fd.rd2wr1));
}

static void	reset_pipe_fd_info(t_shell *sh)
{
	sh->fd.rd1 = FALSE;
	sh->fd.rd2 = FALSE;
	sh->fd.wr1 = FALSE;
	sh->fd.rd1wr2 = FALSE;
	sh->fd.rd2wr1 = FALSE;
	sh->fd.redin = -1;
	sh->fd.heredoc = -1;
	sh->fd.redout = -1;
	sh->fd.redout_apd = -1;
}

static void	set_open_fd(t_shell *sh)
{
	if (sh->fd.wr1 || sh->fd.rd2wr1)
		sh->fd.open = ONE;
	else if (sh->fd.rd1wr2)
		sh->fd.open = TWO;
}

static void	define_fd_info(t_shell *sh, int num)
{
	t_bool	pipe_last_cmd;
	t_bool	pipe;

	pipe = FALSE;
	pipe_last_cmd = FALSE;
	pipe = sh->cmds[num].exec.pipe;
	if (num > 0)
		pipe_last_cmd = sh->cmds[num - 1].exec.pipe;
	if (!pipe && !pipe_last_cmd)
		return ;
	else if (pipe && !pipe_last_cmd && sh->fd.open == ANY)
		sh->fd.wr1 = TRUE;
	else if (pipe && pipe_last_cmd && sh->fd.open == ONE)
		sh->fd.rd1wr2 = TRUE;
	else if (pipe && pipe_last_cmd && sh->fd.open == TWO)
		sh->fd.rd2wr1 = TRUE;
	else if (!pipe && pipe_last_cmd && sh->fd.open == ONE)
		sh->fd.rd1 = TRUE;
	else if (!pipe && pipe_last_cmd && sh->fd.open == TWO)
		sh->fd.rd2 = TRUE;
	else if (pipe && !pipe_last_cmd && sh->fd.open == ONE)
		sh->fd.rd1 = TRUE;
	set_open_fd(sh);
	if (DEBUGGER_EXEC)
		print_fd_info(sh, pipe, pipe_last_cmd);
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
		define_fd_info(sh, i);
		exec_cmd(sh, i);
		reset_pipe_fd_info(sh);
	}
	sh->fd.open = ANY;
}
