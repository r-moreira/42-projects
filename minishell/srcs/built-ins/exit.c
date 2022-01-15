/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:19:42 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/15 16:07:33 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(t_shell *sh)
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
