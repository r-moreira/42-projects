/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:17:47 by romoreir          #+#    #+#             */
/*   Updated: 2022/03/15 00:47:43 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	setup_cmd_info(t_shell *sh, int num)
{
	int	i;

	i = -1;
	while (++i < sh->cmds[num].args_count)
		free(sh->cmds[num].args[i]);
	i = -1;
	while (++i < sh->cmds[num].redin.len)
		ft_strlcpy(sh->cmds[num].redin.arg[i], "\0", 1);
	i = -1;
	while (++i < sh->cmds[num].redout.len)
		ft_strlcpy(sh->cmds[num].redout.arg[i], "\0", 1);
	i = -1;
	while (++i < sh->cmds[num].redout_apd.len)
		ft_strlcpy(sh->cmds[num].redout_apd.arg[i], "\0", 1);
	i = -1;
	while (++i < sh->cmds[num].heredoc.len)
	{
		ft_strlcpy(sh->cmds[num].heredoc.file_buffer[i], "\0", 1);
		ft_strlcpy(sh->cmds[num].heredoc.input_end[i], "\0", 1);
	}
}

static void	setup_cmds_info(t_shell *sh)
{
	int	i;

	i = -1;
	while (++i < sh->count.cmds)
	{
		setup_cmd_info(sh, i);
		sh->cmds[i].args_count = 0;
		ft_strlcpy(sh->cmds[i].name, "\0", 1);
		ft_strlcpy(sh->cmds[i].path, "\0", 1);
	}
}

static void	setup_fd_info(t_shell *sh)
{
	sh->fd.open = ANY;
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

void	setup_flag_info(t_shell *sh, int num)
{
	sh->cmds[num].redin.len = 0;
	sh->cmds[num].redout.len = 0;
	sh->cmds[num].redout_apd.len = 0;
	sh->cmds[num].heredoc.len = 0;
	sh->cmds[num].exec.heredoc = FALSE;
	sh->cmds[num].exec.pipe = FALSE;
	sh->cmds[num].exec.redin = FALSE;
	sh->cmds[num].exec.redout = FALSE;
	sh->cmds[num].exec.redout_apd = FALSE;
	sh->cmds[num].exec.last_redin = NONE;
	sh->cmds[num].exec.last_redout = NONE;
}

void	setup_info(t_shell *sh)
{
	ft_strlcpy(sh->input_string, "\0", 1);
	setup_cmds_info(sh);
	setup_fd_info(sh);
}
