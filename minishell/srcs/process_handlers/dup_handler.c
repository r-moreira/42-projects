/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:05:19 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/22 17:54:36 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_dup	dup_constructor(t_fds_num fd, t_pipe_end end, int fileno,
t_flag flag)
{
	t_dup	dupinfo;

	dupinfo.fd = fd;
	dupinfo.end = end;
	dupinfo.fileno = fileno;
	dupinfo.flag = flag;
	return (dupinfo);
}

static void	dup_pipe(t_shell *sh)
{
	t_dup	dupinfo;
	t_dup	dupinfo2;

	dupinfo = dup_constructor(ANY, -1, -1, NONE);
	dupinfo2 = dup_constructor(ANY, -1, -1, NONE);
	if (sh->fd.wr1)
		dupinfo = dup_constructor(ONE, WRITE_END, STDOUT_FILENO, NONE);
	else if (sh->fd.rd1)
		dupinfo = dup_constructor(ONE, READ_END, STDIN_FILENO, NONE);
	else if (sh->fd.rd2)
		dupinfo = dup_constructor(TWO, READ_END, STDIN_FILENO, NONE);
	else if (sh->fd.rd1wr2)
	{
		dupinfo = dup_constructor(ONE, READ_END, STDIN_FILENO, NONE);
		dupinfo2 = dup_constructor(TWO, WRITE_END, STDOUT_FILENO, NONE);
	}
	else if (sh->fd.rd2wr1)
	{
		dupinfo = dup_constructor(TWO, READ_END, STDIN_FILENO, NONE);
		dupinfo2 = dup_constructor(ONE, WRITE_END, STDOUT_FILENO, NONE);
	}
	dup_n_close_pipe(sh, dupinfo);
	if (sh->fd.rd1wr2 || sh->fd.rd2wr1)
		dup_n_close_pipe(sh, dupinfo2);
}

static void	dup_io(t_shell *sh, int num)
{
	if (sh->cmds[num].exec.redin
			&& sh->cmds[num].exec.last_redin == REDIRECT_IN)
		dup_n_close_redir_fd(sh->fd.redin, REDIRECT_IN);
	if (sh->cmds[num].exec.heredoc
			&& sh->cmds[num].exec.last_redin == HERE_DOCUMENT)
		dup_n_close_redir_fd(sh->fd.heredoc, HERE_DOCUMENT);
	if (sh->cmds[num].exec.redout
	 		&& sh->cmds[num].exec.last_redout == REDIRECT_OUT)
		dup_n_close_redir_fd(sh->fd.redout, REDIRECT_OUT);
	if (sh->cmds[num].exec.redout_apd
			&& sh->cmds[num].exec.last_redout == REDIRECT_OUT_APPEND)
		dup_n_close_redir_fd(sh->fd.redout_apd, REDIRECT_OUT_APPEND);
}

void	handle_dup(t_shell *sh, int num)
{
	dup_io(sh, num);
	dup_pipe(sh);
}
