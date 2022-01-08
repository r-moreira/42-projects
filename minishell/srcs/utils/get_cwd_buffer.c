/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cwd_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:56:35 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/07 22:56:55 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_cwd_buffer(void)
{
	char	*buffer;

	buffer = NULL;
	buffer = getcwd(buffer, DIR_MAX_SIZE);
	return (buffer);
}
