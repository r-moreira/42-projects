/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:45:04 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/15 18:24:17 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_debugger_helper(t_shell *sh, int num, char *log)
{
	if (sh->count.cmds == num + 1)
		printf("%s\n======= End Execution ========\n", log);
	else
		printf("%s", log);
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
