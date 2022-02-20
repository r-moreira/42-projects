/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:45:04 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/20 15:14:18 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_bool_str(t_bool boolean)
{
	if (boolean == TRUE)
		return ("TRUE");
	else if (boolean == FALSE)
		return ("FALSE");
	return ("NOT BOOLEAN");
}

static void print_fd_info(t_shell *sh)
{
	printf("FD Open    = |%d|\n", sh->fd.open);
	printf("FD RD1     = |%s|\n", get_bool_str(sh->fd.rd1));
	printf("FD RD2     = |%s|\n", get_bool_str(sh->fd.rd2));
	printf("FD WR1     = |%s|\n", get_bool_str(sh->fd.wr1));
	printf("FD RD1WR2  = |%s|\n", get_bool_str(sh->fd.rd1wr2));
	printf("FD RD2WR1  = |%s|\n", get_bool_str(sh->fd.rd2wr1));
}

void	executor_debugger_helper(t_shell *sh)
{
	parsed_info_logger(sh);
	print_fd_info(sh);
	printf("======= Start Execution =======\n");
}

void	path_debugger_helper(t_shell *sh, int i)
{
	printf("Command    = |%d|\n", i);
	printf("Path       = |%s|\n", sh->cmds[i].path);
}
