/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_input_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:05:26 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/16 21:07:29 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	open_input_file(t_shell *sh, int num, int arg_num, t_flag flag)
{
	int	heredoc_fd;
	int	redir_fd;
	int	rcreate;
	int	truncate;

	heredoc_fd = -1;
	redir_fd = -1;
	rcreate = O_RDONLY | O_CREAT;
	truncate = O_WRONLY | O_CREAT | O_TRUNC;
	if (flag == REDIRECT_IN)
		redir_fd = open(sh->cmds[num].redin.arg[arg_num], O_RDONLY, 0644);
	else if (flag == HERE_DOCUMENT)
	{
		heredoc_fd = open("/tmp/heredoc", truncate, 0644);
		if (heredoc_fd == -1)
			exit_error(ERROR_OPEN_FILE);
		ft_putstr_fd(sh->heredoc_file_buffer, heredoc_fd);
		redir_fd = open("/tmp/heredoc", O_RDONLY, 0644);
		close(heredoc_fd);
	}
	if (redir_fd == -1)
		exit_error(ERROR_OPEN_FILE);
	return (redir_fd);
}

void	exec_input_redir(t_shell *sh, int num, int arg_num, t_flag flag)
{
	int		redir_fd;
	pid_t	pid;

	if (DEBUGGER_EXEC && flag == REDIRECT_IN)
		exec_debugger_helper(sh, num, "Redirect In = |Write File|");
	else if (DEBUGGER_EXEC && flag == HERE_DOCUMENT)
		exec_debugger_helper(sh, num, "Here document = |Write File|");
	if (fork_builtins(sh, num))
	{
		pid = fork();
		if (pid == -1)
			exit_error(ERROR_FORK);
		if (pid == FORKED_CHILD)
		{
			redir_fd = open_input_file(sh, num, arg_num, flag);
			dup2(redir_fd, STDIN_FILENO);
			close(redir_fd);
			if (sh->cmds[num].builtin)
				exec_builtin(sh, num);
			else if (execve(sh->cmds[num].path, sh->cmds[num].args, sh->envs) == -1)
				exit_error(ERROR_EXEC);
			exit(EXIT_SUCCESS);
		}
		else
			g_pid_number = waitpid(pid, NULL, 0);
	}
	else
		exec_builtin(sh, num);
}
