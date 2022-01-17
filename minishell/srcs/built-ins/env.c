/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:19:25 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/17 09:32:57 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_status	ft_env(t_shell *sh)
{
	int	i;

	i = -1;
	while (++i < sh->count.envs)
		printf("%s\n", sh->envs[i]);
	return (SUCCESS);
}
