/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:34:51 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/20 16:35:24 by romoreir         ###   ########.fr       */
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
	//else if (sh->cmds[num].exec.redout) {};
	//else if (sh->cmds[num].exec.redout_apd) {};
}