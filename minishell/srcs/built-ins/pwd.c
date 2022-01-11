/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:18:36 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/10 21:30:33 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_status	get_pwd(t_shell *sh, int num)
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

//TO-DO
//Adicionar tratamento de flags ao comando (> < | >> <<)
//Adicionar in e out fd na struct dependendo da flag;
t_status	ft_pwd(t_shell *sh, int num)
{
	if (num == 0 && sh->cmds[num].flag == NONE)
		return (get_pwd(sh, num));
	printf("ERROR - PWD ON CMD 2+ AND FLAG NOT IMPLEMENTED\n");
	return (ERROR);
}
