/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:34:51 by romoreir          #+#    #+#             */
/*   Updated: 2022/03/01 16:59:13 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	open_redout_apd_file(t_shell *sh, int num)
{
	int	append;
	int	i;

	append = O_WRONLY | O_CREAT | O_APPEND;
	while (++i < sh->cmds[num].redout_apd.len)
	{
		if (DEBUGGER_EXEC)
			printf("Opening ouput file - O_APPEND: %s\n",
				sh->cmds[num].redout_apd.arg[i]);
		sh->fd.redout_apd = open(sh->cmds[num].redout_apd.arg[i],
				append, 0644);
		if (sh->fd.redout_apd == -1)
			exit_error(ERROR_OPEN_FILE);
	}
}

static void	open_redout_file(t_shell *sh, int num)
{
	int	truncate;
	int	i;

	truncate = O_WRONLY | O_CREAT | O_TRUNC;
	i = -1;
	while (++i < sh->cmds[num].redout.len)
	{
		if (DEBUGGER_EXEC)
			printf("Opening ouput file - O_TRUNC: %s\n",
				sh->cmds[num].redout.arg[i]);
		sh->fd.redout = open(sh->cmds[num].redout.arg[i],
				truncate, 0644);
		if (sh->fd.redout == -1)
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
	int		heredoc_fd;
	int		truncate;

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
	if (DEBUGGER_EXEC)
		printf("Heredoc Buffer: \n|%s|\n", sh->heredoc_file_buffer);
	close(heredoc_fd);
}

void	handle_io(t_shell *sh, int num)
{
	if (sh->cmds[num].exec.redin)
		open_redin_file(sh, num, sh->cmds[num].redin.len - 1);
	if (sh->cmds[num].exec.heredoc)
		open_heredoc_file(sh);
	if (sh->cmds[num].exec.redout)
		open_redout_file(sh, num);
	if (sh->cmds[num].exec.redout_apd)
		open_redout_apd_file(sh, num);
}
