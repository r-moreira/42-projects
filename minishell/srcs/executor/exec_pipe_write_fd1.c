/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_write_fd1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:19:36 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/12 11:24:26 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_pipe_write_fd1(t_shell *sh, int num)
{
	pid_t	pid;

	if (DEBUGGER_EXEC)
		printf("PIPE    = |Write FD1|\n");

	sh->fd.open = IN;

	if (pipe(sh->fd.one) == -1)  {
		return ;
	}

	pid = fork();
	if (pid == -1)
		return ;

	if (pid == FORKED_CHILD)
	{
		dup2(sh->fd.one[WRITE_END], STDOUT_FILENO);
		close(sh->fd.one[READ_END]);
		close(sh->fd.one[WRITE_END]);
		if (execve(sh->cmds[num].path, sh->cmds[num].args, sh->envs) == -1)
		{
			perror(ERROR_EXEC);
			exit(errno);
		}
		else
			exit(EXIT_SUCCESS);
	}
	else
		g_pid_number = waitpid(pid, NULL, 0);
}
