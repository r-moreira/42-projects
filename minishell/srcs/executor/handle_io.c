/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:34:51 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/20 16:50:46 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	open_output_file(t_shell *sh, int num, int arg_num, t_flag flag)
{
	int	redir_fd;
	int	truncate;
	int	append;

	redir_fd = -1;
	truncate = O_WRONLY | O_CREAT | O_TRUNC;
	append = O_WRONLY | O_CREAT | O_APPEND;
	if (flag == REDIRECT_OUT)
	{
		sh->fd.redout = open(sh->cmds[num].redout.arg[arg_num],
				truncate, 0644);
		if (sh->fd.redout == -1)
			exit_error(ERROR_OPEN_FILE);
	}
	else if (flag == REDIRECT_OUT_APPEND)
	{
		sh->fd.redout_apd = open(sh->cmds[num].redout_apd.arg[arg_num],
				append, 0644);
		if (sh->fd.redout_apd == -1)
			exit_error(ERROR_OPEN_FILE);
	}
}

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

void	handle_io(t_shell *sh, int num)
{
	int	arg_num;

	if (sh->cmds[num].exec.redin)
	{
		arg_num = sh->cmds[num].redin.len - 1;
		open_redin_file(sh, num, arg_num);
	}
	else if (sh->cmds[num].exec.heredoc)
		open_heredoc_file(sh);
	else if (sh->cmds[num].exec.redout)
	{
		arg_num = sh->cmds[num].redout.len - 1;
		open_output_file(sh, num, arg_num, REDIRECT_OUT);
	}
	else if (sh->cmds[num].exec.redout_apd)
	{
		arg_num = sh->cmds[num].redout_apd.len - 1;
		open_output_file(sh, num, arg_num, REDIRECT_OUT_APPEND);
	}
}
