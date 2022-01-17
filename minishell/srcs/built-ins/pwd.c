/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:18:36 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/17 09:53:55 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_status	ft_pwd(t_shell *sh, int num)
{
	char	*buffer;

	(void)sh;
	(void)num;
	buffer = get_cwd_buffer();
	if (buffer == NULL)
	{
		g_pid_number = 1;
		free(buffer);
		return (ERROR);
	}
	printf("%s\n", buffer);
	g_pid_number = 0;
	free(buffer);
	return (SUCCESS);
}
