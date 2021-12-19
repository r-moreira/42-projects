/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:43:06 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/19 12:27:22 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	init_shell(t_shell *sh)
{
	sh->cmds_count = 0;
	sh->cmds->args_count = 0;
	sh->heredoc_file_buffer = NULL;
}

void	exit_shell(t_shell *sh)
{
	if (sh->heredoc_file_buffer != NULL)
	 	free(sh->heredoc_file_buffer);
}

int	main(void)
{
	t_shell	sh;

	init_shell(&sh);
	welcome_message();
	while (TRUE)
	{
		print_dir();
		if (take_input(&sh) == SUCCESS)
			analyzer(&sh);
		printf("INPUT = [%s]", sh.input_string); //TEMP
	}
	return (EXIT_SUCCESS);
}
