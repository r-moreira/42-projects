/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:28:17 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/31 21:03:01 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdlib.h>

void	eof_exit_shell(t_shell *sh)
{
	int	i;
	int	j;

	if (sh->heredoc_file_buffer != NULL)
		free(sh->heredoc_file_buffer);
	i = -1;
	while (++i < sh->cmds_count)
	{
		j = -1;
		while (sh->cmds[i].args[++j])
			free(sh->cmds[i].args[j]);
	}
	free(sh->cmds->args);
	printf("exit\n");
	exit(EXIT_SUCCESS);
}
