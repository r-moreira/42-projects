/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:43:06 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/26 20:34:09 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_shell(t_shell *sh)
{
	sh->cmds_count = 0;
	sh->cmds->args_count = 0;
	sh->heredoc_file_buffer = NULL;
}

//TO-DO:
//Chamar ao receber um signal


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
			analyzer(&sh);
		printf("INPUT = [%s]", sh.input_string); //TEMP
	}
	return (EXIT_SUCCESS);
}
