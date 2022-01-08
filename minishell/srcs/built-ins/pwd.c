/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:18:36 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/07 22:40:50 by romoreir         ###   ########.fr       */
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

static t_status	get_pwd(t_shell *sh, int cmd_num)
{
	char	*buffer;

	(void)sh;
	(void)cmd_num;
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
t_status	ft_pwd(t_shell *sh, int cmd_num)
{
if (cmd_num == 0 && sh->cmds[cmd_num].flag == NONE)
		return (get_pwd(sh, cmd_num));
	printf("ERROR - PWD ON CMD 2+ AND FLAG NOT IMPLEMENTED\n");
	return (ERROR);
}
