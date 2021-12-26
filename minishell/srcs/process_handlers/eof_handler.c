/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:28:17 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/26 20:46:21 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdlib.h>

void	eof_exit_shell(t_shell *sh)
{
	if (sh->heredoc_file_buffer != NULL)
		free(sh->heredoc_file_buffer);
	printf("exit\n");
	exit(EXIT_SUCCESS);
}
