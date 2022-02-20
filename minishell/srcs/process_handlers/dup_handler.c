/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:05:19 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/19 23:05:32 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_dup(t_shell *sh)
{
	if (sh->fd.wr1)
		dup_n_close(sh, ONE, WRITE_END, STDOUT_FILENO);
	else if (sh->fd.rd1)
		dup_n_close(sh, ONE, READ_END, STDIN_FILENO);
	else if (sh->fd.rd2)
		dup_n_close(sh, TWO, READ_END, STDIN_FILENO);
	else if (sh->fd.rd1wr2)
	{
		dup_n_close(sh, ONE, READ_END, STDIN_FILENO);
		dup_n_close(sh, TWO, WRITE_END, STDOUT_FILENO);
	}
	else if (sh->fd.rd2wr1)
	{
		dup_n_close(sh, TWO, READ_END, STDIN_FILENO);
		dup_n_close(sh, ONE, WRITE_END, STDOUT_FILENO);
	}
}
