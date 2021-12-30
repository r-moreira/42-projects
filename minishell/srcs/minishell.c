/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:43:06 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/30 14:27:50 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_shell(t_shell *sh)
{
	sh->cmds_count = 0;
	sh->cmds->args_count = 0;
	sh->heredoc_file_buffer = NULL;
}

void	exit_shell(t_shell *sh)
{
	int i;
	if (sh->heredoc_file_buffer != NULL)
		free(sh->heredoc_file_buffer);
}

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
	}
	return (EXIT_SUCCESS);
}
