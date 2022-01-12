/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_read_fd2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:20:16 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/12 11:59:36 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_pipe_read_fd2(t_shell *sh, int num)
{
	pid_t	pid;

	if (DEBUGGER_EXEC)
		exec_debugger_helper(sh, num, "Pipe    = |Read FD2|\n");

	sh->fd.open = ANY;

	pid = fork();
	if (pid == -1)
		return ;

	if (pid == FORKED_CHILD)
	{
		dup2(sh->fd.two[READ_END], STDIN_FILENO);
		close(sh->fd.two[READ_END]);
		close(sh->fd.two[WRITE_END]);
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
		close(sh->fd.two[READ_END]);
		close(sh->fd.two[WRITE_END]);
		g_pid_number = waitpid(pid, NULL, 0);
	}
}
