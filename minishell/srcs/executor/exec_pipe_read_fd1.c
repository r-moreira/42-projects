/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_read_fd1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:20:23 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/12 11:59:25 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_pipe_read_fd1(t_shell *sh, int num)
{
	pid_t	pid;

	if (DEBUGGER_EXEC)
		exec_debugger_helper(sh, num, "Pipe    = |Read FD1|\n");

	sh->fd.open = ANY;

	pid = fork();
	if (pid == -1)
		return ;

	if (pid == FORKED_CHILD)
	{
		dup2(sh->fd.one[READ_END], STDIN_FILENO);
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
	{
		close(sh->fd.one[READ_END]);
		close(sh->fd.one[WRITE_END]);
		g_pid_number = waitpid(pid, NULL, 0);
	}
}
