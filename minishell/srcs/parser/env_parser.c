/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 02:54:01 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/09 02:59:42 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*parse_env(char *env)
{
	char	*new;
	int		i;
	int		j;

	new = (char *)malloc(sizeof(char) * ft_strlen(env) + 1);
	i = 0;
	j = 0;
	while (ft_isspace(env[i]))
		i++;
	while (env[i] != '=' && !ft_isspace(env[i]))
		new[j++] = env[i++];
	if (env[i] != '=')
		while (env[i] != '=')
			i++;
	new[j] = '=';
	i++;
	while (env[i] && !ft_isspace(env[i]))
		new[++j] = env[i++];
	new[++j] = '\0';
	return (new);
}
