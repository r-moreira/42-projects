/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:18:49 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/20 16:34:12 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	open_redin_file(t_shell *sh, int num, int arg_num)
{
	if (DEBUGGER_EXEC)
		printf("Opening input file: %s\n",
			sh->cmds[num].redin.arg[arg_num]);
	sh->fd.redin = open(sh->cmds[num].redin.arg[arg_num], O_RDONLY, 0644);
	if (sh->fd.redin == -1)
		exit_error(ERROR_OPEN_FILE);
}

static void	open_heredoc_file(t_shell *sh)
{
	int	heredoc_fd;
	int	truncate;

	truncate = O_WRONLY | O_CREAT | O_TRUNC;
	if (DEBUGGER_EXEC)
		printf("Getting heredoc...\n");
	handle_here_document_input(sh);
	heredoc_fd = open(HEREDOC_FILE, truncate, 0644);
	if (heredoc_fd == -1)
		exit_error(ERROR_OPEN_FILE);
	ft_putstr_fd(sh->heredoc_file_buffer, heredoc_fd);
	sh->fd.heredoc = open(HEREDOC_FILE, O_RDONLY, 0644);
	if (sh->fd.heredoc == -1)
		exit_error(ERROR_OPEN_FILE);
	close(heredoc_fd);
}

static void	handle_io(t_shell *sh, int num)
{
	int	arg_num;

	if (sh->cmds[num].exec.redin)
	{
		arg_num = sh->cmds[num].redin.len - 1;
		open_redin_file(sh, num, arg_num);
	}
	else if (sh->cmds[num].exec.heredoc)
		open_heredoc_file(sh);
	//else if (sh->cmds[num].exec.redout) {};
	//else if (sh->cmds[num].exec.redout_apd) {};
}

void	exec_fork(t_shell *sh, int num)
{
	pid_t	pid;

	handle_pipe(sh, num);
	pid = handle_fork();
	if (pid == FORKED_CHILD)
	{
		run_signals_exec();
		handle_io(sh, num);
		if (DEBUGGER_EXEC)
			printf("======= CMD[%d] STDOUT =========\n", num);
		handle_dup(sh, num);
		if (sh->cmds[num].exec.builtin)
			exec_builtin(sh, num);
		else if (execve(sh->cmds[num].path, sh->cmds[num].args,
				sh->envs) == -1)
			exit_error(ERROR_EXEC);
		exit(EXIT_SUCCESS);
	}
	else
		wait_aux(pid);
}

void	exec_cmd(t_shell *sh, int num)
{
	if (!has_non_fork_builtins(sh, num))
		exec_fork(sh, num);
	else
		call_builtin(sh, num);
	if (DEBUGGER_EXEC && sh->count.cmds == num + 1)
		printf("======== End Execution ========\n");
}
