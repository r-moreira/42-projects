/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:05:19 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/20 16:15:09 by romoreir         ###   ########.fr       */
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

static void dup_pipe(t_shell *sh)
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
	if (sh->cmds[num].exec.redin)
		dup_n_close_redir_fd(sh->fd.redin, REDIRECT_IN);
	/*else*/ if (sh->cmds[num].exec.heredoc)
		dup_n_close_redir_fd(sh->fd.heredoc, HERE_DOCUMENT);
	/*else*/ if (sh->cmds[num].exec.redout)
		dup_n_close_redir_fd(sh->fd.redout, REDIRECT_OUT);
	/*else*/ if (sh->cmds[num].exec.redout_apd)
		dup_n_close_redir_fd(sh->fd.redout_apd, REDIRECT_OUT_APPEND);
}

void	handle_dup(t_shell *sh, int num)
{
	dup_io(sh, num);
	dup_pipe(sh);
}
