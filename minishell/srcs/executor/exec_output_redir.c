/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_output_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:55:59 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/16 11:25:40 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	open_output_file(t_shell *sh, int num, int arg_num, t_flag flag)
{
	int	redir_fd;
	int	truncate;
	int	append;

	redir_fd = -1;
	truncate = O_WRONLY | O_CREAT | O_TRUNC;
	append = O_WRONLY | O_CREAT | O_APPEND;
	if (flag == REDIRECT_OUT)
		redir_fd = open(sh->cmds[num].redout.arg[arg_num], truncate, 0644);
	else if (flag == REDIRECT_OUT_APPEND)
		redir_fd = open(sh->cmds[num].redout_apd.arg[arg_num], append, 0644);
	if (redir_fd == -1)
		exit_error(ERROR_OPEN_FILE);
	return (redir_fd);
}

void	exec_output_redir(t_shell *sh, int num, int arg_num, t_flag flag)
{
	int		redir_fd;
	pid_t	pid;

	if (DEBUGGER_EXEC && flag == REDIRECT_OUT)
		exec_debugger_helper(sh, num, "Redirect Out = |Write File|");
	else if (DEBUGGER_EXEC && flag == REDIRECT_OUT_APPEND)
		exec_debugger_helper(sh, num, "Redirect Out Append = |Write File|");
	pid = fork();
	if (pid == -1)
		exit_error(ERROR_FORK);
	if (pid == FORKED_CHILD)
	{
		redir_fd = open_output_file(sh, num, arg_num, flag);
		dup2(redir_fd, STDOUT_FILENO);
		if (execve(sh->cmds[num].path, sh->cmds[num].args, sh->envs) == -1)
			exit_error(ERROR_EXEC);
		else
			exit(EXIT_SUCCESS);
		close(redir_fd);
	}
	else
		g_pid_number = waitpid(pid, NULL, 0);
}
