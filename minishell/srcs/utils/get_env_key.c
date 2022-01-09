/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 02:57:35 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/09 02:57:50 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_key(char *env)
{
	char	*env_key;
	int		i;

	env_key = (char *)malloc(sizeof(char) * ft_strlen(env) + 1);
	i = 0;
	while (env[i] && env[i] != '=')
	{
		env_key[i] = env[i];
		i++;
	}
	env_key[i] = '\0';
	return (env_key);
}
