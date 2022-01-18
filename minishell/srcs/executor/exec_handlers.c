/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:23:12 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/17 23:26:25 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_pipes(t_shell *sh, int num, t_bool pipe,
t_bool pipe_last_cmd)
{
	if (num > 0)
		pipe_last_cmd = sh->cmds[num - 1].pipe;
	if (pipe && !pipe_last_cmd && sh->fd.open == ANY)
		exec_pipe_write_fd1(sh, num);
	else if (pipe && pipe_last_cmd && sh->fd.open == ONE)
		exec_pipe_read_fd1_write_fd2(sh, num);
	else if (pipe && pipe_last_cmd && sh->fd.open == TWO)
		exec_pipe_read_fd2_write_fd1(sh, num);
	else if (!pipe && pipe_last_cmd && sh->fd.open == ONE)
		exec_pipe_read_fd1(sh, num);
	else if (!pipe && pipe_last_cmd && sh->fd.open == TWO)
		exec_pipe_read_fd2(sh, num);
	else if (pipe && !pipe_last_cmd && sh->fd.open == ONE)
		exec_pipe_read_fd1(sh, num);
}

void	handle_input_redir(t_shell *sh, int num)
{
	int	i;

	i = -1;
	while (++i < sh->cmds[num].redin.len)
		exec_input_redir(sh, num, i, REDIRECT_IN);
	if (sh->cmds[num].heredoc)
		exec_input_redir(sh, num, i, HERE_DOCUMENT);
}

void	handle_output_redir(t_shell *sh, int num)
{
	int	i;

	i = -1;
	while (++i < sh->cmds[num].redout.len)
		exec_output_redir(sh, num, i, REDIRECT_OUT);
	i = -1;
	while (++i < sh->cmds[num].redout_apd.len)
		exec_output_redir(sh, num, i, REDIRECT_OUT_APPEND);
}
