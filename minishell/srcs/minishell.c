/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:43:06 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/01 01:49:10 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_shell(t_shell *sh)
{
	sh->cmds_count = 0;
	sh->cmds->args_count = 0;
}

/*void	free_struct(t_shell *sh)
{
	int	i;
	int	j;

	if (sh->heredoc_file_buffer != NULL)
		free(sh->heredoc_file_buffer);
	i = -1;
	while (++i < sh->cmds_count)
	{
		j = -1;
		while (sh->cmds[i].args[++j])
			if ((sh->cmds[i].args[j] != NULL))
			free(sh->cmds[i].args[j]);
	}
	if (sh->cmds->args != NULL)
		free(sh->cmds->args);
}*/

//TO-DO
//Dar um free do que for necessário após o fim do loop
int	main(void)
{
	t_shell	sh;

	init_shell(&sh);
	run_signals();
	welcome_message();
	while (TRUE)
	{
		print_prompt();
		if (take_input(&sh) == SUCCESS)
			if (analyzer(&sh) == SUCCESS)
				if (parser(&sh) == SUCCESS)
					printf("SUCCESS\n");
		//free_struct(&sh);
	}
	return (EXIT_SUCCESS);
}
