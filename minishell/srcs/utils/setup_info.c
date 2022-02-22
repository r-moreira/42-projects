/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:17:47 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/22 16:34:26 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	setup_cmds_info(t_shell *sh)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sh->count.cmds)
	{
		j = -1;
		while (++j < sh->cmds[i].args_count)
			free(sh->cmds[i].args[j]);
		j = -1;
		while (++j < sh->cmds[i].redin.len)
			ft_strlcpy(sh->cmds[i].redin.arg[j], "\0", 1);
		j = -1;
		while (++j < sh->cmds[i].redout.len)
			ft_strlcpy(sh->cmds[i].redout.arg[j], "\0", 1);
		j = -1;
		while (++j < sh->cmds[i].redout_apd.len)
			ft_strlcpy(sh->cmds[i].redout_apd.arg[j], "\0", 1);
		sh->cmds[i].args_count = 0;
		ft_strlcpy(sh->cmds[i].name, "\0", 1);
		ft_strlcpy(sh->cmds[i].path, "\0", 1);
	}
}

void	setup_flag_info(t_shell *sh, int num)
{
	sh->cmds[num].redin.len = 0;
	sh->cmds[num].redout.len = 0;
	sh->cmds[num].redout_apd.len = 0;
	sh->cmds[num].exec.heredoc = FALSE;
	sh->cmds[num].exec.pipe = FALSE;
	sh->cmds[num].exec.redin = FALSE;
	sh->cmds[num].exec.redout = FALSE;
	sh->cmds[num].exec.redout_apd = FALSE;
	sh->cmds[num].exec.last_redout = NONE;
}

void	setup_fd_info(t_shell *sh)
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

void	setup_info(t_shell *sh)
{
	setup_cmds_info(sh);
	setup_fd_info(sh);
	ft_strlcpy(sh->heredoc_file_buffer, "\0", 1);
	ft_strlcpy(sh->input_string, "\0", 1);
}
