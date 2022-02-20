/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:45:04 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/19 22:34:31 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_debugger_helper(t_shell *sh, int num)
{
	if (sh->count.cmds == num + 1)
		printf("%s\n======= End Execution ========\n", sh->cmds[num].exec.log);
	else
		printf("%s", sh->cmds[num].exec.log);
}

void	executor_debugger_helper(t_shell *sh)
{
	parsed_info_logger(sh);
	printf("======= Start Execution =======\n");
}

void	path_debugger_helper(t_shell *sh, int i)
{
	printf("Command = |%d|\n", i);
	printf("Path    = |%s|\n", sh->cmds[i].path);
}
