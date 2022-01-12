/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_read_fd2_write_fd1.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:21:23 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/12 11:59:30 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_pipe_read_fd2_write_fd1(t_shell *sh, int num)
{
	pid_t	pid;

	if (DEBUGGER_EXEC)
		exec_debugger_helper(sh, num, "Pipe    = |Read FD2 - Write FD1|\n");

	sh->fd.open = IN;

	if (pipe(sh->fd.one) == -1)  {
		return ;
	}

	pid = fork();
	if (pid == -1)
		return ;

	if (pid == FORKED_CHILD)
	{
		dup2(sh->fd.two[READ_END], STDIN_FILENO);
		close(sh->fd.two[READ_END]);
		close(sh->fd.two[WRITE_END]);
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
	{
		close(sh->fd.two[READ_END]);
		close(sh->fd.two[WRITE_END]);
		g_pid_number = waitpid(pid, NULL, 0);
	}
}
