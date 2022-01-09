/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_no_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:42:07 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/09 16:42:57 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	strlen_no_spaces(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		if (!ft_isspace(s[i]))
			i++;
	return (i);
}
