/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minishell_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:19:25 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/28 23:34:35 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_minishell_path(t_shell *sh)
{
	int		i;
	int		len;

	len = sh->count.envs;
	i = -1;
	while (++i < len)
	{
		if (ft_strncmp("PATH=", sh->envs[i], 5) == 0)
			return (sh->envs[i] + 5);
	}
	return (NULL);
}
