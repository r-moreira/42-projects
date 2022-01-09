/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_env_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 02:56:25 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/09 02:59:25 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_env_valid(char *env)
{
	t_bool	has_eql;
	int		i;
	int		key_count;

	i = 0;
	key_count = 0;
	has_eql = FALSE;
	if (ft_strlen(env) < 3 || ft_isdigit(env[0]))
		return (FALSE);
	while (env[i] && env[i] != '=')
	{
		key_count++;
		i++;
	}
	if (env[i] == '=')
		has_eql = TRUE;
	if (key_count && has_eql == TRUE)
		return (TRUE);
	return (FALSE);
}
