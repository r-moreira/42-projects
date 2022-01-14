/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:28:17 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/13 22:53:40 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	eof_exit_shell(t_shell *sh)
{
	int	i;

	i = -1;
	while (++i < sh->count.envs)
		free(sh->envs[i]);
	i = -1;
	while (++i < sh->count.paths)
		free(sh->paths[i]);
	printf("exit\n");
	exit(EXIT_SUCCESS);
}
