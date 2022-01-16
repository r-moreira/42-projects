/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:17:47 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/16 19:45:11 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clear_execution(t_shell *sh)
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
	ft_strlcpy(sh->heredoc_file_buffer, "\0", 1);
	ft_strlcpy(sh->builtin_out, "\0", 1);
	ft_strlcpy(sh->input_string, "\0", 1);
}
