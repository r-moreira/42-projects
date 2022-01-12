/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:40:07 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/12 12:41:05 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_fd(t_shell *sh, e_fds fd)
{
	if (fd == ONE)
	{
		close(sh->fd.one[READ_END]);
		close(sh->fd.one[WRITE_END]);
	}
	else if (fd == TWO)
	{
		close(sh->fd.two[READ_END]);
		close(sh->fd.two[WRITE_END]);
	}
}
