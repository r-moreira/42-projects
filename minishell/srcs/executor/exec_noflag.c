/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_noflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:18:49 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/12 11:22:54 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_noflag(t_shell *sh, int num)
{
	int		status;
	pid_t	pid;
	printf("NOFLAG  = |Write FD1|\n");

	pid = fork();
	if (pid == FORKED_CHILD)
	{
		if (execve(sh->cmds[num].path, sh->cmds[num].args, sh->envs) == -1)
		{
			perror(ERROR_EXEC);
			exit(errno);
		}
		else
			exit(EXIT_SUCCESS);
	}
	else
		g_pid_number = wait(&status);
}
